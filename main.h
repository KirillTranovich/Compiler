#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdarg.h>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
struct ast
{

    char *type;
    char *value;
    char *name;
    struct ast *parent;
    struct ast *left_child;
    struct ast *right_child;
    struct ast *in_level; // последняя command в {}
    struct ast *args;     // последний arg в ()
    struct ast *next;     // next arg/command for arg/command
    struct ast *prev;     // prev arg/command for arg/command
    struct ast *init;     // 1 ard in cycle for
    struct ast *cond;     // 2 in for, 1 in if and while
    struct ast *change;   // 3 in for
};
// struct ast *endroot;

#endif