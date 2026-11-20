%{
#include <stdio.h>
%}

%%
[0-9]+[ \t]+[0-9]+ {
    int a, b;
    sscanf(yytext, "%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
}
%%

int main()
{
    printf("Enter two integers: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}