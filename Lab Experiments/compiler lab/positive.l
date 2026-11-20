%{
#include <stdio.h>
%}

%%
[0-9]+      { printf("Positive number\n"); }
-[0-9]+     { printf("Negative number\n"); }
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}