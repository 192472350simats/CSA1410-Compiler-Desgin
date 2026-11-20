
%{
#include <stdio.h>
%}

%%
[6-9][0-9]{9} {
    printf("Mobile Number Valid\n");
}
[^\n]+ {
    printf("Mobile Number Invalid\n");
}
\n { }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    printf("Enter Mobile Number: ");
    yylex();
    return 0;
}
