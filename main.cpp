#include "main.h"
#include "parser.hpp"
#include "lexer.h"
#include <iostream>
#include <typeinfo>

void printType(Types type)
{
    switch (type)
    {
    case Root:
        std::cout << "Root" << std::endl;
        break;
    case Command:
        std::cout << "Command" << std::endl;
        break;

    case StartLvl:
        std::cout << "StartLvl" << std::endl;
        break;
    case Error:
        std::cout << "Error" << std::endl;
        break;
    case EmptyLine:
        std::cout << "EmptyLine" << std::endl;
        break;
    case Name:
        std::cout << "Name" << std::endl;
        break;
    case Arr:
        std::cout << "Arr" << std::endl;
        break;
    case ArrMember:
        std::cout << "ArrMember" << std::endl;
        break;
    case Return:
        std::cout << "Return" << std::endl;
        break;
    case Ex_of_class:
        std::cout << "Ex_of_class" << std::endl;
        break;
    case Class:
        std::cout << "Class" << std::endl;
        break;
    case Funk:
        std::cout << "Funk" << std::endl;
        break;
    case ConditionIF:
        std::cout << "ConditionIF" << std::endl;
        break;
    case ConditionELSE:
        std::cout << "ConditionELSE" << std::endl;
        break;
    case For:
        std::cout << "For" << std::endl;
        break;
    case While:
        std::cout << "While" << std::endl;
        break;
    case Lvl:
        std::cout << "Lvl" << std::endl;
        break;
    case And:
        std::cout << "And" << std::endl;
        break;
    case Cmp:
        std::cout << "Cmp" << std::endl;
        break;
    case Or:
        std::cout << "Or" << std::endl;
        break;
    case Add:
        std::cout << "Add" << std::endl;
        break;
    case Sub:
        std::cout << "Sub" << std::endl;
        break;
    case Mull:
        std::cout << "Mull" << std::endl;
        break;
    case Div:
        std::cout << "Div" << std::endl;
        break;
    case Unminus:
        std::cout << "Unminus" << std::endl;
        break;
    case Digit:
        std::cout << "Digit" << std::endl;
        break;
    case Eq:
        std::cout << "Eq" << std::endl;
        break;
    case String:
        std::cout << "String" << std::endl;
        break;
    case CallfunkName:
        std::cout << "CallfunkName" << std::endl;
        break;
    case Arg:
        std::cout << "Arg" << std::endl;
        break;
    case Type:
        std::cout << "Type" << std::endl;
        break;
    default:
        std::cout << "Unknown type" << std::endl;
        break;
    }
}
void printlvl(int lvl)
{
    std::cout << "\n";
    for (int i = 0; i < lvl; i++)
    {
        std::cout << "    ";
    }
}
void freeTree(struct ast *a, int lvl)
{
    printlvl(lvl);
    printType(a->type);
    std::cout
        << " " << a->name << " " << a->value << " "
        << a->first_column << " " << a->last_column << " "
        << "\n(";
    ++lvl;
    if (a->left_child != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his left_child: ";
        freeTree(a->left_child, lvl);
    }
    if (a->right_child != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his right_child: ";
        freeTree(a->right_child, lvl);
    }
    if (a->in_level != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his in_level: ";
        freeTree(a->in_level, lvl);
    }
    if (a->args != 0)
    {

        printlvl(lvl);

        std::cout
            << " "
            << "his args: ";
        freeTree(a->args, lvl);
    }

    if (a->init != 0)
    {

        printlvl(lvl);

        std::cout
            << " "
            << "his init: ";
        freeTree(a->init, lvl);
    }
    if (a->cond != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his cond: ";
        freeTree(a->cond, lvl);
    }
    if (a->change != 0)
    {

        printlvl(lvl);

        std::cout
            << " "
            << "his change: ";
        freeTree(a->change, lvl);
    }
    if (a->next != 0)
    {
        printlvl(lvl);

        std::cout
            << " "
            << "his next: ";
        freeTree(a->next, lvl);
    }

    --lvl;
    printlvl(lvl);
    std::cout << ")";

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

    char string[] = "print(1);;e;EOF";

    ast *root = give_me_tree(string);

    if (root)
    {
        freeTree(root, 0);
    }
    else
        std::cout << ("%s", "noroot") << std::endl;
}