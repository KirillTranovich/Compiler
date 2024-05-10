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
//это примерный пример того как я себе представляю структуру аст
//(... озночает возможный пропуск дальнейших элементов)
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
void yyerror(struct ast *endroot, const char *s);


//struct ast *endroot; //сюда я сложу последний узел дерева
void allNull(struct ast *a)
{
    a->type = "";
    a->value = "";
    a->name = "";
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

%}
%locations
%parse-param{struct ast *endroot}
//перечисление типов токенов без него(не зн поч) ничего не работает
%union { 
    struct ast *a;
    double num;
    char* str;
}

/* обьявление токенов(базовые неделимые элементы программы) и их типов в <> */
%token <str> NUMBER ERR
%token <str> NAME STRING


%token IF ELSE WHILE FOR DEF CLASS NEW AND OR EF RET

%nonassoc <str> CMP
%right '='
%left AND OR
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS
//обьявление типов(по сути что то что собирается из токенов или других типов - усложненные элементы программы)
%type <a> exp  explist level cr_class cr_func new_class condition cycle name command err return
/*%start parse*/

/*
struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column; - выделение памяти под узел a

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
NAME: NAME "." name {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          $$ = a;} // $$ - NAME(до:) $1 - NAME(после:) $2 - "." $3 - name

*/
%%
command:        {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                  a->type="root";
                  printf("%s\n","emptyline"); //debug
                  a->next=0;
                  a->prev=0;
                  $$=a;

                  
                  //root = *$$;
                  ////printf("%s\n",root.type); //debug
}
|command err {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          std::cout<<"error\n";}
|command ';'            {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          //printf("%s\n","ok");
                          a->type="empty line";
                          a->next=0;
                          a->prev=$1;
                          $$=a;
                          $1->next=$$;
                          //printf("%s\n",a->prev->type); //debug
}
|command new_class ';'  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          //printf("%s\n",a->type); //debug
}
|command cr_class ';'   {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          //printf("%s\n",a->type); //debug
}
|command cr_func ';'    {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          //printf("%s\n",a->type); //debug
}
|command exp ';'        {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->left_child = $2;
                          a->prev=$1;
                          
                          $$=a;
                          $1->next=$$;
                          std::cout<<a->type; //debug
}
|command return ';'        {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->left_child = $2;
                          a->prev=$1;
                          
                          $$=a;
                          $1->next=$$;
                          std::cout<<a->type; //debug
}
|command level  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          //printf("%s\n",a->type); //debug
}
|command cycle  { struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          //printf("%s\n",a->type); //debug
                }
|command condition  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="command";
                          a->next=0;
                          a->prev=$1;
                          a->left_child = $2;
                          $$=a;
                          $1->next=$$;
                          //printf("%s\n",a->type); //debug
                    }
|command EF  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="EOF";
                          a->next=0;
                          a->prev=$1;
                          $$=a;
                          $1->next=$$;
                          endroot->next = $$;
                          //printf("%s\n","EOF"); //debug
                          
                          
            }
;

name: NAME  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
              a->type = "Name";
              a->name = $1;
              printf("%s\n",$1); //debug
              $$=a;
            }
|name NAME  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
            a->type = "Name";
            printf("%s\n","nameagain"); //debug  
            a->name = $2;
            a->left_child=$1;
            $$=a;
            $1->type = "type";
            $1->parent = $$;
            
            }

| name '.' NAME   { struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                  a->type = "Name";
                  //printf("%s\n",a->type); //debug 
                  a->name = $3; 
                  a->left_child=$1;
                  $$=a;
                  $1->type = "name";
                  }
| NAME '[' explist ']'    {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                            a->type="arr_member";
                            //printf("%s\n",a->type); //debug
                            a->name=$1;
                            a->args = $3;
                            $$=a;
                            }
| NAME '['']'    {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                            a->type="arr";
                            //printf("%s\n",a->type); //debug
                            a->name=$1;
                            
                            $$=a;
                            }
;

return: RET exp {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                  a->type="return";
                  a->left_child = $2;
                  $2->parent = a;
                  $$ = a; }
new_class: name  '=' NEW name '(' explist ')' {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                              a->type="ex_of_class";
                                              a->value = $4->name;
                                              //printf("%s\n",a->type); //debug
                                              a->name=$1->name;
                                              a->args = $6;
                                              $$=a;
                                              }
|name  '=' NEW name '('  ')' {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="ex_of_class";
                              a->value = $4->name;
                              //printf("%s\n",a->type); //debug
                              a->name=$1->name;
                              $$=a;
                              }
;

cr_class: CLASS name  level  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                            a->type="class"; 
                                            //printf("%s\n",a->type); //debug
                                            a->name = $2->name;
                                            a->in_level = $3;
                                            
                                            $$=a;
                                            }
|CLASS name '('  ')'   level            {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                            a->type="class"; 
                                            //printf("%s\n",a->type); //debug
                                            a->name = $2->name;
                                            a->in_level = $5;
                                            a->args = 0;
                                            $$=a;
                                        }
;

cr_func: DEF name '(' explist ')' level     {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                            a->type="func"; 
                                            //printf("%s\n",a->type); //debug
                                            a->name = $2->name;
                                            a->in_level = $6;
                                            a->args = $4;
                                            $$=a;
                                            }
|DEF name '('  ')' level           {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                    a->type="func"; 
                                    //printf("%s\n",a->type); //debug
                                    a->name = $2->name;
                                    a->in_level = $5;
                                    a->args = 0;
                                    $$ = a;
                                    }
;

condition: IF '(' exp ')'   level         {
                                            struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                            a->type="conditionIF"; 
                                            //printf("%s\n",a->type); //debug
                                            a->in_level = $5;
                                            a->cond = $3;
                                            $$ = a;
                                          }
| ELSE   level                                 {
                                            struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                            a->type="conditionELSE"; 
                                            //printf("%s\n",a->type); //debug
                                            a->in_level = $2;
                                            a->cond = 0;
                                            $$  = a;
}
;

cycle: FOR '('exp ';' exp ';' exp  ')'  level         { 
                                                        struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                                        a->type="FOR"; 
                                                        //printf("%s\n",a->type); //debug
                                                        a->in_level = $9;
                                                        a->init = $3;
                                                        a->cond = $5;
                                                        a->change = $7;
                                                        $$=a;
                                                      }
| FOR '('name ':' exp ')'   level                     {
                                                        struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                                        a->type="FOR:"; 
                                                        //printf("%s\n",a->type); //debug
                                                        a->in_level = $7;
                                                        a->init = $3;
                                                        a->cond = $5;
                                                        $$ = a;
                                                      }
| WHILE '(' exp ')'     level                         {
                                                        struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                                                        a->type="WHILE"; 
                                                        //printf("%s\n",a->type); //debug
                                                        a->in_level = $5;
                                                        a->cond = $3;
                                                        $$=a;
                                                      }
;

level: '{'command '}' {
  struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                        a->type = "lvl";
                        //printf("%s\n",a->type); //debug
                        a->left_child=$2;
                        $$=a;
                        $2->parent=$$;
                        }
;

exp: exp CMP exp            {
  struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type=$2;
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$;
                              $3->parent = $$;

                            }
  | exp AND exp             {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="and";  
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              }
  | exp OR exp              {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="or";  
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                              }
  | exp '+' exp             {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="+"; 
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              printf("%d  %d  %d  %d\n",@$.first_line,@$.last_line,@$.first_column,@$.last_column);
                              
                              }
  | exp '-' exp             {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="-";  
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              //printf("%s\n",a->left_child->value); //debug
                              $$ =a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                              }
  | exp '*' exp             {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="*";  
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$=a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                              }
  | exp '/' exp             {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="/"; 
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$ = a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                            }
  | '(' exp ')'             { 
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="(exp)"; 
                              //printf("%s\n",a->type); //debug
                              a->left_child = $2;
                              $$ = a;
                              $2->parent = $$; 
                              
                            }
  | '-' exp %prec UMINUS    {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="uminus";  
                              //printf("%s\n",a->type); //debug
                              a->left_child = $2;
                              $$ = a;
                              $2->parent = $$; 
                              
                            }
  | NUMBER                  {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type = "Digit"; 
                              //printf("%s\n",a->type); //debug
                              a->value = $1; 
                              $$ = a;
                              
                            }
  | name '=' exp            {
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type="="; 
                              //printf("%s\n",a->type); //debug
                              a->left_child = $1; 
                              a->right_child = $3;
                              $$ = a;
                              $1->parent = $$; 
                              $3->parent = $$; 
                              
                            }
  | STRING                  { 
    struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type = "String"; 
                              printf("%s\n","String"); //debug
                              a->value = $1; 
                              $$ = a;
                            }
  | name                    {
                              /*struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                              a->type=$1->type; */
                              printf("%s\n","Nameinexpr"); //debug
                              //a->value = "names value"; 
                              //a->name=$1->name;a->left_child = $1;
                              $$ = $1;
                              //$1->parent = $$;
                            }
|NAME '('')' {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                a->type = "Name()";
                //printf("%s\n",a->type); //debug
                a->name = $1;
                a->args = 0;
                $$=a;
             }

| NAME '(' explist ')'  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                        a->type="Callfunk_name";
                        //printf("%s\n",a->type); //debug
                        a->name=$1;
                        a->args = $3;
                        $$=a;
                        }
;

explist: exp {
                struct ast *a = new ast;
                a->first_line = @$.first_line;
                a->last_line = @$.last_line;
                a->last_column = @$.last_column;
                a->first_column = @$.first_column;
                std::cout<< @$.first_line;
                std::cout<< a->first_line;
                a->type="arg";
                //printf("%s\n",a->type); //debug
                a->left_child =$1;
                $1->parent = a;
                $$=a;
                
              }
  | explist ',' exp {
                      struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                      $1->type="arg";
                      a->type="arg";
                      //printf("%s\n",a->type); //debug
                      a->prev=$1;
                      $$=a;
                      a->left_child=$3;
                      $3->parent = $$;
                      
                      $1->next = $$;
                      }
;

err: {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
|err ERR{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
|  exp err{struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @2.last_column;
                  a->first_column = @2.first_column;
                          a->type="error";
                          $$ = a;}
|explist  err {struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @2.last_column;
                  a->first_column = @2.first_column;
                          a->type="error";
                          $$ = a;}
| level   err {struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @2.last_column;
                  a->first_column = @2.first_column;
                          a->type="error";
                          $$ = a;}
| cr_class err  {struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @2.last_column;
                  a->first_column = @2.first_column;
                          a->type="error";
                          $$ = a;} 
| cr_func   err {struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @2.last_column;
                  a->first_column = @2.first_column;
                          a->type="error";
                          $$ = a;}
| new_class  err  {struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @2.last_column;
                  a->first_column = @2.first_column;
                          a->type="error";
                          $$ = a;}
| condition  err {struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;} 
| cycle  err  {struct ast *a = new ast;
                  a->first_line = @2.first_line;
                  a->last_line = @2.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}

| IF  err  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| ELSE  err  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| WHILE  err {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;} 
| FOR   err {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| DEF  err  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| CLASS  err  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| NEW  err  {struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}

| CMP err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| '=' err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| AND err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| OR err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| '+' err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| '-' err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| '*' err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| '/' err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| ';' err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| '|'  err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| UMINUS err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| NUMBER err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| NAME err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}
| STRING err{struct ast *a = new ast;
                  a->first_line = @$.first_line;
                  a->last_line = @$.last_line;
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type="error";
                          $$ = a;}

;





%%
void yyerror(struct ast *endroot,const char *s)
{
//printf(stderr, "err: %s\n", s);
}