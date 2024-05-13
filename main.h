#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdarg.h>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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
    struct ast *parent = 0;
    struct ast *left_child = 0;
    struct ast *right_child = 0;
    struct ast *in_level = 0; //  command в {}
    struct ast *args = 0;     //  arg в ()
    struct ast *next = 0;     //  next arg/command for arg/command
    struct ast *prev = 0;     //  prev arg/command for arg/command
    struct ast *init = 0;     //  1 arg in cycle for
    struct ast *cond = 0;     //  2 in for, 1 in if and while
    struct ast *change = 0;   //  3 in for
};

#endif