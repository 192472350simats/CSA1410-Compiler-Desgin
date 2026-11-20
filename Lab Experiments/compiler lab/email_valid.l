
%{
#include <stdio.h>
%}

%%
^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\r?$ {
    printf("Accepted\n");
}
^[^\n]+ {
    printf("Not Accepted\n");
}
\n { }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    printf("Enter Email Address:\n");
    yylex();
    return 0;
}
