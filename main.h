#ifndef MAIN_H
#define MAIN_H
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

/*struct ast *newast(char *type ,

                   char *value ,
                   char *name ,
                   struct ast *parent ,
                   struct ast *left_child ,
                   struct ast *right_child ,
                   struct ast *in_level , // последняя command в {}
                   struct ast *args ,     // последний arg в ()
                   struct ast *next ,     // next arg/command for arg/command
                   struct ast *prev ,     // prev arg/command for arg/command
                   struct ast *init ,     // 1 ard in cycle for
                   struct ast *cond ,     // 2 in for, 1 in if and while
                   struct ast *change )
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));

    if (!a)
    {
        exit(0);
    }

    a->type = type;
    a->value = value;
    a->name = name;
    a->parent = parent;
    a->left_child = left_child;
    a->right_child = right_child;
    a->in_level = in_level;
    a->args = args;
    a->next = next;
    a->prev = prev;
    a->init = init;
    a->cond = cond;
    a->change = change;
    return a;
}
*/
#endif