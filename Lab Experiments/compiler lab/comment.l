
%{
#include <stdio.h>
#include <stdlib.h>
int com = 0;
%}

%%
"/*"    { com++; }
"//".*  { com++; }
.|\n    { fprintf(yyout, "%s", yytext); }
%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: comment.exe input.c output.c\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    if (yyin == NULL || yyout == NULL)
    {
        printf("File error\n");
        return 1;
    }

    yylex();
    printf("Number of comments = %d\n", com);

    fclose(yyin);
    fclose(yyout);
    return 0;
}
