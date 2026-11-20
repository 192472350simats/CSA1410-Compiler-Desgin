
%{
#include <stdio.h>
int line = 0;
%}

%%
^[^\n]*\n {
    printf("%4d\t%s", ++line, yytext);
}
^[^\n]+ {
    printf("%4d\t%s\n", ++line, yytext);
}
%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: addlinenos.exe sample.c\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");

    if (yyin == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    yylex();
    fclose(yyin);
    return 0;
}
