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

//функция возвращает ссылку на озданный узел
ast *newast(ast t = {})
{
    struct ast *a = new ast;

    if (!a)
    {
        std::cout << "cant create ast note" << std::endl;
        exit(0);
    }
    if (t.first_column)
    {
        a->first_column = t.first_column;
    }
    if (t.last_column)
    {
        a->last_column = t.last_column;
    }
    if (t.type)
    {
        a->type = t.type;
    }
    if (t.value != "")
    {
        a->value = t.value;
    }
    if (t.name != "")
    {
        a->name = t.name;
    }

    if (t.left_child)
    {
        ast *tmp = t.left_child;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->left_child = tmp;
        tmp->parent = a;

        t.left_child->parent = a;
    }
    if (t.right_child)
    {
        a->right_child = t.right_child;
        t.right_child->parent = a;
    }
    if (t.in_level)
    {
        ast *tmp = t.in_level;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->in_level = tmp;
    }
    if (t.args)
    {
        ast *tmp = t.args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;
    }
    if (t.next)
    {
        a->next = t.next;
        t.next->prev = a;
    }
    if (t.prev)
    {
        a->prev = t.prev;
        t.prev->next = a;
    }
    if (t.init)
    {
        ast *tmp = t.init;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->init = tmp;
    }
    if (t.cond)
    {
        a->cond = t.cond;
    }
    if (t.change)
    {
        ast *tmp = t.change;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->change = tmp;
    }
    return a;
}

//без вот этой штуки ничего не работает не спрашивай что она делает
extern int yylex(void);
extern int yycolumn;
//без этой тоже
void yyerror(struct ast *endroot, const char *s);



%}
%locations
%parse-param{struct ast *endroot}
//перечисление типов токенов без него ничего не работает
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
%type <a> exp  explist level cr_class cr_func new_class condition cycle name command return 
/*%start parse*/

/*
struct ast *a = new ast;
                  
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
                  
                  a->last_column = @$.last_column;
                  a->first_column = @$.first_column;
                          a->type=Command;
                          $$ = a;} // $$ - NAME(до:) $1 - NAME(после:) $2 - "." $3 - name

*/
%%
command:        {
        
    $$=newast({.first_column = (yylloc).first_column,.last_column =(yylloc).last_column, .type = StartLvl,});

    if((yylloc).first_column == 1){endroot->next = $$;
                            endroot->type = Error;
                            $$->type = Root;
                            $$->prev = endroot;
                            }

                  

}

|command ';'            {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = EmptyLine,.prev=$1});
}
|command new_class ';'  {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column,.type = Command, .left_child = $2,.prev=$1});
}
|command cr_class ';'   {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Command,.left_child = $2,.prev=$1});
}
|command cr_func ';'    {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Command,.left_child = $2,.prev=$1});
}
|command exp ';'        {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Command,.left_child = $2,.prev=$1});
}
|command return ';'        {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Command,.left_child = $2,.prev=$1});
}
|command level  {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Command,.left_child = $2,.prev=$1});
}
|command cycle  { 
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Command,.left_child = $2,.prev=$1});
}
|command condition  {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Command,.left_child = $2,.prev=$1});
}
|command EF  {    
    (yylloc).first_column =1;                       
    YYACCEPT;                         
};



name: NAME  {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Name,.name=$1});
}
|name NAME  {
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Name,.name=$2,.left_child = $1,});
    $1->type = Type;
}

| name '.' NAME   { 
    $$=newast({.first_column = @2.first_column,.last_column = @2.last_column, .type = Name,.name=$3,.left_child = $1,});
}
| NAME '[' explist ']'    {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = ArrMember,.name=$1,.args = $3,});
}
| NAME '['']'    {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Arr,.name=$1});
}
;

return: RET exp {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Return,.left_child = $2,}); 
}
new_class: name  '=' NEW name '(' explist ')' {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Ex_of_class,.value = $4->name,.name=$1->name,.args = $6,});
}
|name  '=' NEW name '('  ')' {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Ex_of_class,.value = $4->name,.name=$1->name,});
}
;

cr_class: CLASS name  level  {
$$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Class,.name=$2->name,.in_level = $3});
}
|CLASS name '('  ')'   level            {
$$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Class,.name=$2->name,.in_level = $5});
}
;

cr_func: DEF name '(' explist ')' level     {
$$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Funk,.name=$2->name,.in_level = $6,.args = $4,});
}
|DEF name '('  ')' level           {
$$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Funk,.name=$2->name,.in_level = $5});
}
;

condition: IF '(' exp ')'   level         {
                                           
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = ConditionIF,.in_level = $5,.cond=$3,});
}
| ELSE   level                                 {
                                            
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = ConditionELSE,.in_level = $2});
}
;

cycle: FOR '('exp ';' exp ';' exp  ')'  level         { 
                                                      
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = For,.in_level = $9,.init = $3,.cond=$5,.change = $7});
}
| FOR '('name ':' exp ')'   level                     {
                                                       
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = For,.in_level = $7,.init = $3,.cond=$5,});
}
| WHILE '(' exp ')'     level                         {
                                                        
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = While,.in_level = $5,.cond=$3,});
}
;

level: '{'command '}' {
 
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Lvl,.left_child = $2,});
}
;

exp: exp CMP exp            {
  
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Cmp,.left_child = $1,.right_child = $3});
}
  | exp AND exp             {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = And,.left_child = $1,.right_child = $3});
}
  | exp OR exp              {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Or,.left_child = $1,.right_child = $3});
}
  | exp '+' exp             {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Add,.left_child = $1,.right_child = $3});
}
  | exp '-' exp             {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Sub,.left_child = $1,.right_child = $3});
}
  | exp '*' exp             {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Mull,.left_child = $1,.right_child = $3});
}
  | exp '/' exp             {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Div,.left_child = $1,.right_child = $3});
}
  | '(' exp ')'             { 
    
    $$ = $2;
}
  | '-' exp %prec UMINUS    {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type =Unminus,.left_child = $2,});
}
  | NUMBER                  {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Digit,.value = $1});
}
  | name '=' exp                {
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Eq,.left_child = $1,.right_child = $3});
}
  | STRING                  { 
    
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = String,.value = $1});
}
  | name                    {
                              
    $$ = $1;
}
|NAME '('')' {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Name,.name = $1});
}

| NAME '(' explist ')'  {
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = CallfunkName,.name = $1,.args = $3});
}
;

explist: exp {
                
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Arg,.left_child=$1});
}
  | explist ',' exp {
                     
    $$=newast({.first_column = @$.first_column,.last_column = @$.last_column, .type = Arg,.left_child =$3,.prev = $1,});
}
;



%%
void yyerror(struct ast *endroot,const char *s)
{
        endroot->first_column=(yylloc).first_column;
        endroot->last_column=(yylloc).last_column;
        
        (yylloc).first_column=1;
        (yylloc).last_column=1;
        yycolumn = 1;
 

}