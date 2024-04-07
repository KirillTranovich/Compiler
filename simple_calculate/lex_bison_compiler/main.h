#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    struct ast *line;
    struct Node *next;
    struct Node *prev;
};
struct ast
{
    char *type;
    char *value;
    char *name;
    struct ast *parent;
    struct ast *left_child;
    struct ast *right_child;
    struct Node *in_level;
    struct Node *args;
};
