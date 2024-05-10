#include "main.h"
#include "parser.hpp"
#include "lexer.h"
#include <iostream>

// extern struct ast *endroot;
void printlvl(int lvl)
{
    std::cout << "\n";
    for (int i = 0; i < lvl; i++)
    {
        std::cout << "    ";
    }
}
void running(struct ast *a, int lvl)
{
    printlvl(lvl);

    std::cout
        << " " << a->name << " " << a->type << " " << a->value << " "
        << a->first_column << " " << a->last_column << " "
        << a->first_line << " " << a->last_line << "\n(";
    ++lvl;
    /*if (a->parent != 0)
    {
        running(a->parent);
    }*/
    // printf("(");
    if (a->left_child != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his left_child: ";
        running(a->left_child, lvl);
    }
    if (a->right_child != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his right_child: ";
        running(a->right_child, lvl);
    }
    if (a->in_level != 0)
    {
        ast *tmp = a->args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;
        delete tmp;
        tmp = 0;
        printlvl(lvl);

        std::cout
            << " "
            << "his in_level: ";
        running(a->in_level, lvl);
    }
    if (a->args != 0)
    {
        ast *tmp = a->args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;
        delete tmp;
        tmp = 0;
        printlvl(lvl);

        std::cout
            << " "
            << "his args: ";
        running(a->args, lvl);
    }
    /*if (a->next != 0)
    {
        running(a->next);
    }*/

    if (a->init != 0)
    {
        ast *tmp = a->args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;
        delete tmp;
        tmp = 0;
        printlvl(lvl);

        std::cout
            << " "
            << "his init: ";
        running(a->init, lvl);
    }
    if (a->cond != 0)
    {
        ast *tmp = a->args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;
        delete tmp;
        tmp = 0;
        printlvl(lvl);

        std::cout
            << " "
            << "his cond: ";
        running(a->cond, lvl);
    }
    if (a->change != 0)
    {
        ast *tmp = a->args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;
        delete tmp;
        tmp = 0;
        printlvl(lvl);

        std::cout
            << " "
            << "his change: ";
        running(a->change, lvl);
    }
    if (a->next != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his next: ";
        running(a->next, lvl);
    }

    --lvl;
    printlvl(lvl);
    std::cout
        << ")";

    // printf(")");
    delete a;
    a = 0;
}
int main()
{
    struct ast endrootnotaptr = {};
    char string[] = "int a = \"adfadf''''45r1231><===adf\";EOF";
    YY_BUFFER_STATE buffer = yy_scan_string(string);
    yyparse(&endrootnotaptr);
    struct ast *endroot = endrootnotaptr.next;
    yy_delete_buffer(buffer);
    if (endroot)
    {

        std::cout
            << " " << endroot->type << " "
            << "lol";
    }
    else
        printf("%s", "no");

    // yyparse(); // вызвал парсинг
    //  все что ниже на данный момент просто дебаг

    while (endroot->prev != 0)
    {
        endroot = endroot->prev;
        // printf("%s\nhis change: ", endroot->type);
    }
    // printf("\n");
    /*while (endroot->next != 0)
    {
        endroot = endroot->next;
        // printf("%s\nhis change: ", endroot->type);
    }*/

    running(endroot, 0);
}