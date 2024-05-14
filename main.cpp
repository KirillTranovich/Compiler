#include "main.h"
#include "parser.hpp"
#include "lexer.h"
#include <iostream>
#include <typeinfo>

ast *give_me_tree(char *s)
{
    char *tmp = s;
    strcat(tmp, "EOF");
    struct ast *root = new ast;
    YY_BUFFER_STATE buffer = yy_scan_string(tmp);
    buffer->yy_bs_lineno = 1;
    buffer->yy_bs_column = 0;
    yyparse(root);
    yy_delete_buffer(buffer);
    return root;
}
int main()
{

    char string[] = "print(1);;e;";

    ast *root = give_me_tree(string);

    if (root)
    {
        ast::freeTree(root, 0);
    }
    else
        std::cout << ("%s", "noroot") << std::endl;
}