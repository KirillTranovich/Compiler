%{
    #include "parser_retTokens.tab.h"
%}
%%
"//".* {}


"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"|" { return ABS; }
"(" { return OP; }
")" { return CP; }
[0-9]+ { yylval.num = atoi(yytext); return NUMBER; }
\n { return EOL; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %c\n", *yytext); }
%%

int yywrap(){return 1;}

