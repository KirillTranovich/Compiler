%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char* format_string(const char* format, ...) {
    // Determine the length of the resulting string
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    // Allocate memory for the resulting string
    char* result = malloc(len + 1);
    if (result == NULL) {
        // Memory allocation failed
        return NULL;
    }

    // Format the string
    va_start(args, format);
    vsnprintf(result, len + 1, format, args);
    va_end(args);

    return result;
}
void w_s(char *pr, char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        pr[i] = str[i];
    }
    pr[strlen(str)] = '\0';
}
struct par{
    int num;
    char *str;

};
%}


%union{
    int num;
    struct par pr;
}

%token <num> NUMBER
%token ADD SUB MUL DIV ABS
%token EOL
%token OP CP

%type <pr> calclist
%type <pr> exp
%type <pr> factor
%type <pr> term
%%
calclist: %empty {printf("0\n");}
| calclist exp EOL {   
                        printf("= %d\n", $2.num);
                        FILE *fp = fopen("output.txt", "a");
                        fprintf(fp, "(%s) = %d\n", $2.str,$2.num);
                        fclose(fp);
                    }
| calclist EOL {}
;
exp: factor 
| exp ADD factor { $$.num = $1.num + $3.num;$$.str =  format_string("(%s,%s)+",$1.str, $3.str);}
| exp SUB factor { $$.num = $1.num - $3.num;$$.str =  format_string("(%s,%s)-",$1.str, $3.str);}
;
factor: term 
| factor MUL term { $$.num = $1.num * $3.num;$$.str =  format_string("(%s,%s)*",$1.str, $3.str);}
| factor DIV term { $$.num = $1.num / $3.num;$$.str =  format_string("(%s,%s)/",$1.str, $3.str);}
;
term: NUMBER {$$.num = $1;$$.str =  format_string("%d",$1);}
| ABS term { $$.num = $2.num >= 0? $2.num : - $2.num;$$.str =  format_string("abs(%s)",$2.str); }
|OP exp CP { $$.num = (char)$2.num;$$.str =  format_string("%s",$2.str);}
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