/*
root
|                     - something...
command---something -
|                     - something...
command---something...
|
emptyline
|
command
.
.
.
|
EOF
//это примерный пример того как я себе представляю структуру аст(... озночает возможный пропуск дальнейших элементов)
*/

%{
//тут валяется структура аст дерева
#include "main.h"
//это я не использую делая все ручками без функци но вообще можно задействовать
struct ast *newast(char *type = 0,

                   char *value = 0,
                   char *name = 0,
                   struct ast *parent = 0,
                   struct ast *left_child = 0,
                   struct ast *right_child = 0,
                   struct ast *in_level = 0, // последняя command в {}
                   struct ast *args = 0,     // последний arg в ()
                   struct ast *next = 0,     // next arg/command for arg/command
                   struct ast *prev = 0,     // prev arg/command for arg/command
                   struct ast *init = 0,     // 1 ard in cycle for
                   struct ast *cond = 0,     // 2 in for, 1 in if and while
                   struct ast *change = 0)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));

    if (!a)
    {
        exit(0);
    }

    a->type = type;
    a->value = value;
    a->name = name;
    a->parent = parent;
    a->left_child = left_child;
    a->right_child = right_child;
    a->in_level = in_level;
    a->args = args;
    a->next = next;
    a->prev = prev;
    a->init = init;
    a->cond = cond;
    a->change = change;
    return a;
}
//без вот этой штуки ничего не работает не спрашивай что она делает
extern int yylex(void);
//без этой тоже
void yyerror(const char *s);


struct ast *endroot; //сюда я сложу последний узел дерева
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
//перечисление типов токенов без него(не зн поч) ничего не работает
%union { 
    struct ast *a;
    double num;
    char *str;
}

/* обьявление токенов(базовые неделимые элементы программы) и их типов в <> */
%token <str> NUMBER
%token <str> NAME STRING


%token IF ELSE WHILE FOR DEF CLASS NEW AND OR EF

%nonassoc <str> CMP
%right '='
%left AND OR
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS
//обьявление типов(по сути что то что собирается из токенов или других типов - усложненные элементы программы)
%type <a> exp  explist level cr_class cr_func new_class condition cycle name command

/*%start parse*/

/*
struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a); - выделение памяти под узел a

a->b - альтернатива a.b у указателей(то есть в строчках такого типа я просто заполняю содержимое
созданного узла инормацией)

как вообще понимать логику всех выражений: читайте про BNF 
конструкции вида 
<определяемый символ> : <посл.1>.a  <посл.1>.b <посл.1>.c ...| <посл.2> | . . . | <посл.n> прямиком оттуда
причем в данном ниже коде $$ - <определяемый символ>
                          $1 - <посл.1>.a
                          $2 - <посл.1>.b
                          и т.д.
пример: 
NAME: NAME "." name {} // $$ - NAME(до:) $1 - NAME(после:) $2 - "." $3 - name

*/
%%
command:        {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                  a->type="root";
                  printf("%s\n","emptyline"); //debug
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
                          a->type="EOF";
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
            a->left_child=$1;
            $$=a;
            $1->type = "type";
            $1->parent = $$;
            
            }
|name '('')' {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                a->type = "Name";
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
                                              a->type="ex_of_class";
                                              a->value = $4->name;
                                              printf("%s\n",a->type); //debug
                                              a->name=$1->name;
                                              a->args = $6;
                                              $$=a;
                                              }
|name  '=' NEW name '('  ')' {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                              a->type="ex_of_class";
                              a->value = $4->name;
                              printf("%s\n",a->type); //debug
                              a->name=$1->name;
                              $$=a;
                              }
;

cr_class: CLASS name'(' explist ')'  level  {struct ast *a = (struct ast *)malloc(sizeof(struct ast));allNull(a);
                                            a->type="class"; 
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
                                    a->type="func"; 
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
                      a->type="arg";
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