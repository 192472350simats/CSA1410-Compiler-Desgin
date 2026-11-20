%{
#include <stdio.h>

int nmacro = 0;
int nheader = 0;
%}

%%

^#define     { nmacro++; }
^#include    { nheader++; }
.|\n         ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    char file[20];
    FILE *f;

    printf("Enter File Name : ");
    scanf("%s", file);

    f = fopen(file, "r");
    yyin = f;

    yylex();

    printf("Number of macros defined = %d\n", nmacro);
    printf("Number of header files included = %d\n", nheader);

    fclose(yyin);

    return 0;
}