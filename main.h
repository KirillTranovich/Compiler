#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdarg.h>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

enum Types
{

    Root,
    Command,
    StartLvl,
    Error,
    EmptyLine,
    Name,
    Arr,
    ArrMember,
    Return,
    Ex_of_class,
    Class,
    Funk,
    ConditionIF,
    ConditionELSE,
    For,
    While,
    Lvl,
    And,
    Cmp,
    Or,
    Add,
    Sub,
    Mull,
    Div,
    Unminus,
    Digit,
    Eq,
    String,
    CallfunkName,
    Arg,
    Type

};

struct ast
{
    int first_column = 0;
    int last_column = 0;
    Types type;
    std::string value = "";
    std::string name = "";
    ast *parent = 0;
    ast *left_child = 0;
    ast *right_child = 0;
    ast *in_level = 0; //  command в {}
    ast *args = 0;     //  arg в ()
    ast *next = 0;     //  next arg/command for arg/command
    ast *prev = 0;     //  prev arg/command for arg/command
    ast *init = 0;     //  1 arg in cycle for
    ast *cond = 0;     //  2 in for, 1 in if and while
    ast *change = 0;   //  3 in for

public:
    ~ast()
    {
        // Освобождение памяти для указателей
        /*
        delete left_child;
        delete right_child;
        delete in_level;
        delete args;
        delete next;
        delete prev;
        delete init;
        delete cond;
        delete change;*/
    }
    static ast *getNext(ast *root)
    {
        return root->next;
    }
    static std::vector<ast *> getAllPointers(ast *root)
    {
        std::vector<ast *> pointers;
        if ((root) == nullptr)
        {
            return;
        }

        pointers.push_back(root->next);

        pointers.push_back(root->left_child);
        pointers.push_back(root->right_child);
        pointers.push_back(root->in_level);
        pointers.push_back(root->args);
        pointers.push_back(root->init);
        pointers.push_back(root->cond);
        pointers.push_back(root->change);
        return pointers;
    }

    // функция возвращает ссылку на cозданный узел
    static ast *newast(ast t)
    {
        struct ast *a = new ast();

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
    static void printType(Types type)
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
    static void printlvl(int lvl)
    {
        std::cout << "\n";
        for (int i = 0; i < lvl; i++)
        {
            std::cout << "    ";
        }
    }
    static void freeTree(struct ast *a, int lvl)
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

private:
    static void getAllPointersRecursive(ast *node, std::vector<ast *> &pointers)
    {
        if (node == nullptr)
        {
            return;
        }

        getAllPointersRecursive(node->next, pointers);

        getAllPointersRecursive(node->left_child, pointers);
        getAllPointersRecursive(node->right_child, pointers);
        getAllPointersRecursive(node->in_level, pointers);
        getAllPointersRecursive(node->args, pointers);
        getAllPointersRecursive(node->init, pointers);
        getAllPointersRecursive(node->cond, pointers);
        getAllPointersRecursive(node->change, pointers);
    }
};

#endif