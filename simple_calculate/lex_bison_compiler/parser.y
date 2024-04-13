

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
%}

%union { 
    struct ast a;
    double num;
    char *str;
}

/* declare tokens */
%token <str> NUMBER
%token <str> NAME STRING


%token IF ELSE WHILE FOR DEF CLASS NEW AND OR EF

%nonassoc <str> CMP
%right '='
%left AND OR
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS

%type <a> exp  explist level cr_class cr_func new_class condition cycle name command

/*%start parse*/

%%
command:        {$$.type="command";
                  $$.next=0;
                  $$.prev=0;
                  printf("%s\n",$$.type); //debug
}
|command ';'            {$$.type="empty line";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
}
|command new_class ';'  {$$.type="command";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
}
|command cr_class ';'   {$$.type="command";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
}
|command cr_func ';'    {$$.type="command";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
}
|command exp ';'        {$$.type="command";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
}
|command level  {$$.type="command";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
}
|command cycle  { $$.type="command";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
                }
|command condition  { $$.type="command";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
                    }
|command EF  {$$.type="EOF";
                          $$.next=0;
                          $$.prev=&$1;
                          $1.next=&$$;
                          printf("%s\n",$$.type); //debug
            }
;

name: NAME  { $$.type = "Name";
              $$.name = $1;
              printf("%s\n",$$.name); //debug
            }
|name NAME  {$$.type = "Name";
            printf("%s\n",$$.type); //debug  
            $$.name = $2;
            $1.type = "type";
            $1.parent = &$$;
            
            }
|name '('')' {
                $$.type = "Callfunk";
                printf("%s\n",$$.type); //debug
                $$.name = concat_strings($1.name, "()");
                $$.args = 0;
                
             }
| name '.' NAME   { 
                  $$.type = "Name";
                  printf("%s\n",$$.type); //debug 
                  $$.name = concat_strings($3, $1.name); 
                  
                  }
| name '(' explist ')'  {
                        $$.type="Callfunk";
                        printf("%s\n",$$.type); //debug
                        $$.name=$1.name;
                        $$.args = &$3;
                        
                        }
| name '[' explist ']'    {
                            $$.type="arr_member";
                            printf("%s\n",$$.type); //debug
                            $$.name=$1.name;
                            $$.args = &$3;
                            }
;

new_class: name  '=' NEW name '(' explist ')' {
                                              $$.type=concat_strings("ex_of_class",$4.name);
                                              printf("%s\n",$$.type); //debug
                                              $$.name=$1.name;
                                              }
|name  '=' NEW name '('  ')' {
                              $$.type=concat_strings("ex_of_class",$4.name);
                              printf("%s\n",$$.type); //debug
                              $$.name=$1.name;
                              
                              }
;

cr_class: CLASS name'(' explist ')'  level  {
                                            $$.type=concat_strings("class",$2.name); 
                                            printf("%s\n",$$.type); //debug
                                            $$.name = $2.name;
                                            $$.in_level = &$6;
                                            $$.args = &$4;
                                            }
|CLASS name '('  ')'   level            {
                                            $$.type=concat_strings("class",$2.name); 
                                            printf("%s\n",$$.type); //debug
                                            $$.name = $2.name;
                                            $$.in_level = &$5;
                                            $$.args = 0;
                                        }
;

cr_func: DEF name '(' explist ')' level     {
                                            $$.type=concat_strings("func",$4.name); 
                                            printf("%s\n",$$.type); //debug
                                            $$.name = $2.name;
                                            $$.in_level = &$6;
                                            $$.args = &$4;
                                            }
|DEF name '('  ')' level           {
                                    $$.type=concat_strings("func",$2.name); 
                                    printf("%s\n",$$.type); //debug
                                    $$.name = $2.name;
                                    $$.in_level = &$5;
                                    $$.args = 0;
                                    }
;

condition: IF '(' exp ')'   level         {
                                            $$.type="conditionIF"; 
                                            printf("%s\n",$$.type); //debug
                                            $$.in_level = &$5;
                                            $$.cond = &$3;
                                          }
| ELSE   level                                 {
                                            $$.type="conditionELSE"; 
                                            printf("%s\n",$$.type); //debug
                                            $$.in_level = &$2;
                                            $$.cond = 0;
}
;

cycle: FOR '('exp ';' exp ';' exp  ')'  level         { $$.type="FOR"; 
                                                        printf("%s\n",$$.type); //debug
                                                        $$.in_level = &$9;
                                                        $$.init = &$3;
                                                        $$.cond = &$5;
                                                        $$.change = &$7;
                                                      }
| FOR '('name ':' exp ')'   level                     {$$.type="FOR:"; 
                                                        printf("%s\n",$$.type); //debug
                                                        $$.in_level = &$7;
                                                        $$.init = &$3;
                                                        $$.cond = &$5;
                                                      }
| WHILE '(' exp ')'     level                         {$$.type="WHILE"; 
                                                        printf("%s\n",$$.type); //debug
                                                        $$.in_level = &$5;
                                                        $$.cond = &$3;
                                                      }
;

level: '{'command '}' {
                        $$.type = "lvl";
                        printf("%s\n",$$.type); //debug
                        $$.left_child=&$2;$2.parent=&$$;
                        }
;

exp: exp CMP exp            {
                              $$.type=$2;
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              $1.parent = &$$;
                              $3.parent = &$$;

                            }
  | exp AND exp             {
                              $$.type="and";  
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              $1.parent = &$$; 
                              $3.parent = &$$; 
                              }
  | exp OR exp              {
                              $$.type="or";  
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              $1.parent = &$$; 
                              $3.parent = &$$; 
                              
                              }
  | exp '+' exp             {
                              $$.type="+"; 
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              $1.parent = &$$; 
                              $3.parent = &$$; 
                              
                              }
  | exp '-' exp             {
                              $$.type="-";  
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              printf("%s\n",$$.left_child->value); //debug
                              $1.parent = &$$; 
                              $3.parent = &$$; 
                              
                              }
  | exp '*' exp             {
                              $$.type="*";  
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              $1.parent = &$$; 
                              $3.parent = &$$; 
                              
                              }
  | exp '/' exp             {
                              $$.type="/"; 
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              $1.parent = &$$; 
                              $3.parent = &$$; 
                              
                            }
  | '(' exp ')'             { 
                              $$.type=concat_strings(concat_strings("(",$2.type),")"); 
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$2;
                              $2.parent = &$$; 
                              
                            }
  | '-' exp %prec UMINUS    {
                              $$.type=concat_strings("-",$2.type);  
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$2;
                              $2.parent = &$$; 
                              
                            }
  | NUMBER                  {
                              $$.type = "Digit"; 
                              printf("%s\n",$$.type); //debug
                              $$.value = $1; 
                              
                            }
  | name '=' exp            {
                              $$.type="="; 
                              printf("%s\n",$$.type); //debug
                              $$.left_child = &$1; 
                              $$.right_child = &$3;
                              $1.parent = &$$; 
                              $3.parent = &$$; 
                              
                            }
  | STRING                  { 
                              $$.type = "String"; 
                              printf("%s\n",$$.type); //debug
                              $$.value = $1; 
                            }
  | name                    {
                              $$.type=$1.type; 
                              printf("%s\n",$$.type); //debug
                              $$.value = "extern value"; 
                              $$.name=$1.name;$$.left_child = &$1;
                              $1.parent = &$$;
                            }
;

explist: exp {
                $$.type="arg";
                printf("%s\n",$$.type); //debug
                $$.left_child =&$1;
                $1.parent = &$$;
                
              }
  | explist ',' exp {
                      $1.type="arg";
                      $$.type="args";
                      printf("%s\n",$$.type); //debug
                      $$.left_child=&$3;
                      $3.parent = &$$;
                      $$.prev=&$1;
                      $1.next = &$3;
                      }
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