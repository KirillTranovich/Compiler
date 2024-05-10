

%{
    #include "C:\Users\packard\Desktop\real_work_compil\main.h"
  #include "parser.hpp"
  /* handle locations */
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
 yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
 yycolumn += yyleng;
  
%}
%option yylineno 
/* float exponent */
EXP ([Ee][-+]?[0-9]+)

%%


"+" |
"-" |
"*" |
"/" |
"=" |
"|" |
"," |
"." |
";" |
":" |
"[" |
"]" |
"{" |
"}" |
"(" |
")" { yylval.str = strdup(yytext);return yytext[0]; }

">"  { yylval.str = strdup(yytext);  return CMP; }
"<"  {  yylval.str = strdup(yytext); return CMP; }
"<>" { yylval.str  = strdup(yytext); return CMP; }
"==" { yylval.str  = strdup(yytext); return CMP; }
">=" { yylval.str  = strdup(yytext); return CMP; }
"<=" { yylval.str  = strdup(yytext); return CMP; }

  /* keywords */
"EOF" {return EF;}
"return" {return RET;}
"if"    {      return IF; }
"and"   {      return AND; }
"or"    {return OR;}
"else"  {    return ELSE; }
"while" {  return WHILE; }
"for"    {    return FOR; }
"def"   {   return DEF ;}
"class" {return CLASS;}
"new" {return NEW;}
  /* names */
[a-zA-Z][a-zA-Z0-9_]* {yylval.str  = strdup(yytext); printf("%s\n","ok"); return NAME; }
"\""[^\"]*"\"" {yylval.str  = strdup(yytext); return STRING; }


[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.str  = strdup(yytext); return NUMBER; }
" " {/*yycolumn = yycolumn+1;*/}
[ \t] { /* ignore whitespace */ }

\\\n {/*yycolumn = 1;*/ } /* ignore line continuation */

\n { /*yycolumn = 1;*/}

. { yylval.str  = strdup(yytext); return ERR; }

%%
int yywrap(){return 1;}