#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdarg.h>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct ast
{
    int first_line = 0;
    int last_line = 0;
    int first_column = 0;
    int last_column = 0;
    std::string type = "";
    std::string value = "";
    std::string name = "";
    struct ast *parent = nullptr;
    struct ast *left_child = 0;
    struct ast *right_child = 0;
    struct ast *in_level = 0; // последняя command в {}
    struct ast *args = 0;     // последний arg в ()
    struct ast *next = 0;     // next arg/command for arg/command
    struct ast *prev = 0;     // prev arg/command for arg/command
    struct ast *init = 0;     // 1 ard in cycle for
    struct ast *cond = 0;     // 2 in for, 1 in if and while
    struct ast *change = 0;   // 3 in for
};
// struct ast *endroot;

#endif