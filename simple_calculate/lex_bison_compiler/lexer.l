





%{
    #include "main.h"
  #include "parser.tab.h"
  
%}

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
")" { return yytext[0]; }

">"  { yylval.str = strdup(yytext);  return CMP; }
"<"  {  yylval.str = strdup(yytext); return CMP; }
"<>" { yylval.str  = strdup(yytext); return CMP; }
"==" { yylval.str  = strdup(yytext); return CMP; }
">=" { yylval.str  = strdup(yytext); return CMP; }
"<=" { yylval.str  = strdup(yytext); return CMP; }

  /* keywords */
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
[a-zA-Z][a-zA-Z0-9_-]* {yylval.str  = strdup(yytext); return NAME; }
"\""[a-zA-Z0-9_-]*"\"" {yylval.str  = strdup(yytext); return STRING; }


[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.str  = strdup(yytext); return NUMBER; }


 

[ \t] { /* ignore whitespace */ }

\\\n { } /* ignore line continuation */

\n { }

. { yyerror( "Mystery character %c\n", *yytext); }

%%
int yywrap(){return 1;}