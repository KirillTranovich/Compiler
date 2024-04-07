%code{
    struct line{
double num;
char *str;

};

}
%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/*struct line{
double num;
char *str;

};*/
extern struct a;
%}

%union { 
    struct a a;
    double num;
    char *str;
 //   struct line ln;
}

/* declare tokens */
%token <num> NUMBER
%token <str> NAME STRING


%token IF ELSE WHILE FOR DEF CLASS NEW AND OR

%nonassoc <str> CMP
%right '='
%left AND OR
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
|command level  {}
|command cycle  {}
|command condition  {}
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

condition: IF '(' exp ')'   level                     {}
| ELSE   level                                 {}
;

cycle: FOR '('exp ';' exp ';' exp  ')'  level         {}
| FOR '('name ':' exp ')'   level                     {}
| WHILE '(' exp ')'     level                         {}
;

level: '{'command '}' {}
;

exp: exp CMP exp            { }
  | exp AND exp             { }
  | exp OR exp              { }
  | exp '+' exp             { }
  | exp '-' exp             { }
  | exp '*' exp             { }
  | exp '/' exp             { }
  | '(' exp ')'             { }
  | '-' exp %prec UMINUS    { }
  | NUMBER                  { }
  | name '.' name           { }
  | name '.' name '(' explist ')'  { }
  | name '=' exp            { }
  | name '(' explist ')'    { }
  | name '[' explist ']'    { }
  | STRING                  { }
  | name                    { }
  |'(' ')'                  { }
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