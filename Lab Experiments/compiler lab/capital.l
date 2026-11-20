
%{
#include <stdio.h>
%}

%%
[A-Z]+    { printf("%s is a capital word\n", yytext); }
.|\n      { }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    printf("Enter String:\n");
    yylex();
    return 0;
}
