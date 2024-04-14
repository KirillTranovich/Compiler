

%{
  #include <cstdio>
    #include <string>
    /*#include <iostream>
    
    using namespace std;
    #define YYSTYPE string
    #define YYERROR_VERBOSE 1
    
    int  wrapRet = 1;
    
    int yylex(void);
    extern "C" {
        int yywrap( void ) {
            return wrapRet;
        }
    }*/

    
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>
extern int yylex(void);
void yyerror(const char *s);
//int main();
struct ast *endroot;
void allNull(struct ast *a)
{
    a->type = 0;
    a->value = 0;
    a->name = 0;
    a->parent = 0;
    a->left_child = 0;
    a->right_child = 0;
    a->in_level = 0;
    a->args = 0;
    a->next = 0;
    a->prev = 0;
    a->init = 0;
    a->cond = 0;
    a->change = 0;
}
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
    struct ast *a;
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
command:        {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                  a->type="root";
                  printf("%s\n","emptyline");
                  a->next=0;
                  a->prev=0;
                  $$=a;
                  
                  //root = *$$;
                  //printf("%s\n",root.type); //debug
}
|command ';'            {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="empty line";
                          a->next=0;
                          a->prev=$1;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->prev->prev->type); //debug
}
|command new_class ';'  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->type); //debug
}
|command cr_class ';'   {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->type); //debug
}
|command cr_func ';'    {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->type); //debug
}
|command exp ';'        {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="command";
                          a->next=0;
                          a->left_child = $2;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->type); //debug
}
|command level  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->type); //debug
}
|command cycle  { struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->type); //debug
                }
|command condition  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          printf("%s\n",a->type); //debug
                    }
|command EF  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                          a->type="EO";
                          a->next=0;
                          a->prev=$1;
                          $$=a;
                          $1->next=$$;
                          endroot = $$;
                          printf("%s\n",endroot->prev->type); //debug
                          
                          
            }
;

name: NAME  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
              a->type = "Name";
              a->name = $1;
              printf("%s\n",a->name); //debug
              $$=a;
            }
|name NAME  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
            a->type = "Name";
            printf("%s\n",a->type); //debug  
            a->name = $2;
            $$=a;
            $1->type = "type";
            $1->parent = $$;
            
            }
|name '('')' {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                a->type = "Callfunk";
                printf("%s\n",a->type); //debug
                a->name = concat_strings($1->name, "()");
                a->args = 0;
                $$=a;
             }
| name '.' NAME   { struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                  a->type = "Name";
                  printf("%s\n",a->type); //debug 
                  a->name = concat_strings($3, $1->name); 
                  $$=a;
                  }
| name '(' explist ')'  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                        a->type="Callfunk";
                        printf("%s\n",a->type); //debug
                        a->name=$1->name;
                        a->args = $3;
                        $$=a;
                        }
| name '[' explist ']'    {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                            a->type="arr_member";
                            printf("%s\n",a->type); //debug
                            a->name=$1->name;
                            a->args = $3;
                            $$=a;
                            }
;

new_class: name  '=' NEW name '(' explist ')' {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                              a->type=concat_strings("ex_of_class",$4->name);
                                              printf("%s\n",a->type); //debug
                                              a->name=$1->name;
                                              $$=a;
                                              }
|name  '=' NEW name '('  ')' {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type=concat_strings("ex_of_class",$4->name);
                              printf("%s\n",a->type); //debug
                              a->name=$1->name;
                              $$=a;
                              }
;

cr_class: CLASS name'(' explist ')'  level  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                            a->type=concat_strings("class",$2->name); 
                                            printf("%s\n",a->type); //debug
                                            a->name = $2->name;
                                            a->in_level = $6;
                                            a->args = $4;
                                            $$=a;
                                            }
|CLASS name '('  ')'   level            {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                            a->type=concat_strings("class",$2->name); 
                                            printf("%s\n",a->type); //debug
                                            a->name = $2->name;
                                            a->in_level = $5;
                                            a->args = 0;
                                            $$=a;
                                        }
;

cr_func: DEF name '(' explist ')' level     {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                            a->type=concat_strings("func",$4->name); 
                                            printf("%s\n",a->type); //debug
                                            a->name = $2->name;
                                            a->in_level = $6;
                                            a->args = $4;
                                            $$=a;
                                            }
|DEF name '('  ')' level           {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                    a->type=concat_strings("func",$2->name); 
                                    printf("%s\n",a->type); //debug
                                    a->name = $2->name;
                                    a->in_level = $5;
                                    a->args = 0;
                                    $$ = a;
                                    }
;

condition: IF '(' exp ')'   level         {
                                            struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                            a->type="conditionIF"; 
                                            printf("%s\n",a->type); //debug
                                            a->in_level = $5;
                                            a->cond = $3;
                                            $$ = a;
                                          }
| ELSE   level                                 {
                                            struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                            a->type="conditionELSE"; 
                                            printf("%s\n",a->type); //debug
                                            a->in_level = $2;
                                            a->cond = 0;
                                            $$  = a;
}
;

cycle: FOR '('exp ';' exp ';' exp  ')'  level         { 
                                                        struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                                        a->type="FOR"; 
                                                        printf("%s\n",a->type); //debug
                                                        a->in_level = $9;
                                                        a->init = $3;
                                                        a->cond = $5;
                                                        a->change = $7;
                                                        $$=a;
                                                      }
| FOR '('name ':' exp ')'   level                     {
                                                        struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                                        a->type="FOR:"; 
                                                        printf("%s\n",a->type); //debug
                                                        a->in_level = $7;
                                                        a->init = $3;
                                                        a->cond = $5;
                                                        $$ = a;
                                                      }
| WHILE '(' exp ')'     level                         {
                                                        struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                                        a->type="WHILE"; 
                                                        printf("%s\n",a->type); //debug
                                                        a->in_level = $5;
                                                        a->cond = $3;
                                                        $$=a;
                                                      }
;

level: '{'command '}' {
  struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                        a->type = "lvl";
                        printf("%s\n",a->type); //debug
                        a->left_child=$2;
                        $$=a;
                        $2->parent=$$;
                        }
;

exp: exp CMP exp            {
  struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type=$2;
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$;
                              $3->parent = $$;

                            }
  | exp AND exp             {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="and";  
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              }
  | exp OR exp              {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="or";  
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                              }
  | exp '+' exp             {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="+"; 
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                              }
  | exp '-' exp             {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="-";  
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              printf("%s\n",a->left_child->value); //debug
                              $$ =a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                              }
  | exp '*' exp             {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="*";  
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                              }
  | exp '/' exp             {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="/"; 
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$ = a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                            }
  | '(' exp ')'             { 
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type=concat_strings(concat_strings("(",$2->type),")"); 
                              printf("%s\n",a->type); //debug
                              a->left_child = $2;
                              $$ = a;
                              $2->parent = $$; 
                              
                            }
  | '-' exp %prec UMINUS    {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type=concat_strings("-",$2->type);  
                              printf("%s\n",a->type); //debug
                              a->left_child = $2;
                              $$ = a;
                              $2->parent = $$; 
                              
                            }
  | NUMBER                  {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type = "Digit"; 
                              printf("%s\n",a->type); //debug
                              a->value = $1; 
                              $$ = a;
                              
                            }
  | name '=' exp            {
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="="; 
                              printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$ = a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                            }
  | STRING                  { 
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type = "String"; 
                              printf("%s\n",a->type); //debug
                              a->value = $1; 
                              $$ = a;
                            }
  | name                    {
                              struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type=$1->type; 
                              printf("%s\n",a->type); //debug
                              a->value = "extern value"; 
                              a->name=$1->name;a->left_child = $1;
                              $$ = a;
                              $1->parent = $$;
                            }
;

explist: exp {
                struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                a->type="arg";
                printf("%s\n",a->type); //debug
                a->left_child =$1;
                $1->parent = a;
                $$=a;
                
              }
  | explist ',' exp {
                      struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);allNull(a);
                      $1->type="arg";
                      a->type="args";
                      printf("%s\n",a->type); //debug
                      a->prev=$1;
                      $$=a;
                      a->left_child=$3;
                      $3->parent = $$;
                      
                      $1->next = $3;
                      }
;







%%
void yyerror(const char *s)
{
fprintf(stderr, "error: %s\n", s);
}