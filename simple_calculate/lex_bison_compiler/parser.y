

%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
char* concat_strings(char* str1, char* str2) {
    // Calculate the length of the resulting string
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t total_len = len1 + len2 + 1;

    // Allocate memory for the resulting string
    char* result = (char*)malloc(total_len * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy the first string to the resulting string
    strncpy(result, str1, len1);

    // Concatenate the second string to the resulting string
    strncpy(result + len1, str2, len2 + 1);

    return result;
}

extern struct ast;
%}

%union { 
    struct ast a;
    double num;
    char *str;
}

/* declare tokens */
%token <str> NUMBER
%token <str> NAME STRING


%token IF ELSE WHILE FOR DEF CLASS NEW AND OR

%nonassoc <str> CMP
%right '='
%left AND OR
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS

%type <a> exp  explist level cr_class cr_func new_class condition cycle name command

/*%start parse*/

%%
command:        {$$.type="command";$$.in_level->line=0;$$.in_level->next=0;}
|command ';'            {$$.type="command";$$.in_level->line=$1.in_level->line;$$.in_level->next=$1.in_level->next;
$1.in_level->prev=$$.in_level->prev;}
|command new_class ';'  {$$.type="command";$$.in_level->line=&$2;$$.in_level->next=$1.in_level;
$1.in_level->prev=$$.in_level;}
|command cr_class ';'   {$$.type="command";$$.in_level->line=&$2;$$.in_level->next=$1.in_level;
$1.in_level->prev=$$.in_level;}
|command cr_func ';'    {$$.type="command";$$.in_level->line=&$2;$$.in_level->next=$1.in_level;
$1.in_level->prev=$$.in_level;}
|command exp ';'        {$$.type="command";$$.in_level->line=&$2;$$.in_level->next=$1.in_level;
$1.in_level->prev=$$.in_level;}
|command level  {$$.type="command";$$.in_level->line=&$2;$$.in_level->next=$1.in_level;
$1.in_level->prev=$$.in_level;}
|command cycle  {$$.type="command";$$.in_level->line=&$2;$$.in_level->next=$1.in_level;
$1.in_level->prev=$$.in_level;}
|command condition  {$$.type="command";$$.in_level->line=&$2;$$.in_level->next=$1.in_level;
$1.in_level->prev=$$.in_level;}
;

name: NAME  {$$.type = "Name"; $$.name = $1; printf("%s\n",$$.name);}
|name NAME  {$$.type = ""; $$.name = $2;$1.type = "type"; printf("%s\n",$$.name);
            $1.parent = &$$;}
|name '('')' {$$.type = "Callfunk"; $$.name = concat_strings($1.name, "()"); printf("%s\n",$$.name);}
| name '.' NAME   { $$.type = "Name"; $$.name = concat_strings($3, $1.name); printf("%s\n",$$.name);}
| name '(' explist ')'  {$$.type="Callfunk";$$.name=$1.name;$$.args->line=$3.args->line;$$.args->next=$3.args->next;  }

  | name '[' explist ']'    {$$.type="arr_member";$$.name=$1.name;$$.args->line=$3.args->line;$$.args->next=$3.args->next; }
;

new_class: name  '=' NEW name '(' explist ')' {$$.type=concat_strings("ex_of_class",$4.name); $$.name=$1.name;$$.args->line=$6.args->line;$$.args->next=$6.args->next;}
|name  '=' NEW name '('  ')' {$$.type=concat_strings("ex_of_class",$4.name); $$.name=$1.name;$$.args->line=0;$$.args->next=0;}
;

cr_class: CLASS name'(' explist ')'  level             {$$.type=concat_strings("class",$4.name); $$.name=$2.name;$$.args->line=$6.args->line;$$.args->next=$6.args->next;}
|CLASS name '('  ')'   level             {}
;

cr_func: DEF name '(' explist ')' level                {}
|DEF name '('  ')' level           {}
;

condition: IF '(' exp ')'   level                     {}
| ELSE   level                                 {}
;

cycle: FOR '('exp ';' exp ';' exp  ')'  level         {}
| FOR '('name ':' exp ')'   level                     {}
| WHILE '(' exp ')'     level                         {}
;

level: '{'command '}' {$$.type = "lvl"; $$.left_child=&$2;$2.parent=&$$;}
;

exp: exp CMP exp            { $$.type=$2; $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | exp AND exp             {$$.type="and";  $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | exp OR exp              {$$.type="or";  $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | exp '+' exp             {$$.type="+"; $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | exp '-' exp             {$$.type="-";  $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | exp '*' exp             {$$.type="*";  $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | exp '/' exp             {$$.type="/";  $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | '(' exp ')'             { $$.type=concat_strings(concat_strings("(",$2.type),")"); $$.left_child = &$2;
                              $2.parent = &$$; }
  | '-' exp %prec UMINUS    {$$.type=concat_strings("-",$2.name);  $$.left_child = &$2;
                              $2.parent = &$$; }
  | NUMBER                  {$$.type = "Digit"; $$.value = $1; printf("%s\n",$$.value); }
  | name '=' exp            { $$.type="="; $$.left_child = &$1; $$.right_child = &$3;
                              $1.parent = &$$; $3.parent = &$$; }
  | STRING                  { $$.type = "String"; $$.value = $1; printf("%s\n",$$.value); }
  | name                    {$$.type=$1.type; $$.value = "extern value"; $$.name=$1.name;$$.left_child = &$1;$1.parent = &$$;}
;

explist: exp {$$.type="arg";$$.args->line=&$1; }
  | explist ',' exp {$1.type="arg";$$.type="args";$$.args->next = $1.args;$$.args->line=&$3;    }
;







%%

int main()
{
    
    yyparse();
    
    
}
void yyerror(char *s)
{
fprintf(stderr, "error: %s\n", s);
}