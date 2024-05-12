#include "main.h"
#include "parser.hpp"
#include "lexer.h"
#include <iostream>

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
    if (t.type != "")
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
        // a->left_child = t.left_child;
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
        /*ast *tmp = t.cond;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->cond = tmp;

        */
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
        << "\n(";
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
        /*ast *tmp = a->args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;

        */
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

        printlvl(lvl);

        std::cout
            << " "
            << "his init: ";
        running(a->init, lvl);
    }
    if (a->cond != 0)
    {
        /*ast *tmp = a->args;
        while (tmp->prev)
        {
            tmp = tmp->prev;
        }
        a->args = tmp;

        */
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

ast *give_me_tree(char *s)
{

    struct ast *root = new ast;
    YY_BUFFER_STATE buffer = yy_scan_string(s);
    buffer->yy_bs_lineno = 1;
    buffer->yy_bs_column = 0;
    yyparse(root);
    yy_delete_buffer(buffer);
    return root;
}
int main()
{

    char string[] = "print(1);int i = 1;===EOF";

    // printf("%s", "norm");
    for (int i = 1; i < 3; ++i)
    {
        ast *root = give_me_tree(string);

        if (root)
        {

            std::cout
                << " " << root->type << " "
                << "lol";
        }
        else
            printf("%s", "no");

        // yyparse(); // вызвал парсинг
        //  все что ниже на данный момент просто дебаг

        running(root, 0);
    }
}