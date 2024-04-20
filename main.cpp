#include "main.h"
#include "parser.tab.h"
#include <iostream>
extern struct ast *endroot;
void running(struct ast *a)
{
    printf("name:%s,type:%s,value:%s", a->name, a->type, a->value);
    /*if (a->parent != 0)
    {
        running(a->parent);
    }*/
    printf("(");
    if (a->left_child != 0)
    {
        printf("\nhis left_child: ");
        running(a->left_child);
    }
    if (a->right_child != 0)
    {
        printf("\nhis right_child: ");
        running(a->right_child);
    }
    if (a->in_level != 0)
    {
        printf("\nhis in_level: ");
        running(a->in_level);
    }
    if (a->args != 0)
    {
        printf("\nhis args: ");
        running(a->args);
    }
    /*if (a->next != 0)
    {
        running(a->next);
    }*/
    if (a->prev != 0)
    {
        printf("\nhis prev: ");
        running(a->prev);
    }
    if (a->init != 0)
    {
        printf("\nhis init: ");
        running(a->init);
    }
    if (a->cond != 0)
    {
        printf("\nhis cond: ");
        running(a->cond);
    }
    if (a->change != 0)
    {
        printf("\nhis change: ");
        running(a->change);
    }
    printf(")");
    free(a);
}
int main()
{

    yyparse(); // вызвал парсинг
    // все что ниже на данный момент просто дебаг
    while (endroot->prev != 0)
    {
        endroot = endroot->prev;
        printf("%s\nhis change: ", endroot->type);
    }
    printf("\n");
    while (endroot->next != 0)
    {
        endroot = endroot->next;
        printf("%s\nhis change: ", endroot->type);
    }

    // running(endroot);
}