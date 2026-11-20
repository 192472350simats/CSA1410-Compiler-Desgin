%{
#include <stdio.h>
%}

%%
[0-9]+ {
    printf("Valid digit\n");
}

.* {
    printf("Invalid digit\n");
}
%%

int main()
{
    printf("Enter input: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}