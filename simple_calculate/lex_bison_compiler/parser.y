%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*struct line{
double num;
char *str;

};*/

%}

%union { 
    
    double num;
    char *str;
 //   struct line ln;
}

/* declare tokens */
%token <num> NUMBER
%token <str> NAME


%token IF ELSE WHILE FOR DEF CLASS NEW

%nonassoc <str> CMP
%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS

%type <str> exp  explist level cr_class cr_func new_class condition cycle name command

/*%start parse*/

%%
command:        {}
| command ';'           {}
|command new_class ';'  {}
|command cr_class ';'   {}
|command cr_func ';'    {}
|command exp ';'        {}
|command level ';' {}
|command cycle ';' {}
|command condition ';' {}
;

name: NAME  {}
|name NAME  {}
;

new_class: name  '=' NEW name '(' explist ')' {}
|name  '=' NEW name '('  ')' {}
;

cr_class: CLASS name'(' explist ')'               {}
|CLASS name '('  ')'                {}
;

cr_func: DEF name '(' explist ')'                {}
|DEF name '('  ')'                {}
;

condition: IF '(' exp ')'                        {}
| ELSE                                           {}
;

cycle: FOR '('exp ';' exp ';' exp  ')'           {}
| FOR '('name ':' name ')'                       {}
| WHILE '(' exp ')'                              {}
;

level: '{' {}
| '}'      {}
;

exp: exp CMP exp            { }
  | exp '+' exp             { }
  | exp '-' exp             { }
  | exp '*' exp             { }
  | exp '/' exp             { }
  | '(' exp ')'             { }
  | '-' exp %prec UMINUS    { }
  | NUMBER                  { }
  | name                    { }
  | name '.' name           { }
  | name '.' name '(' explist ')'  { }
  | name '=' exp            { }
  | name '(' explist ')'    { }
  | name '[' explist ']'    { }
;

explist: exp { }
  | exp ',' explist { }
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