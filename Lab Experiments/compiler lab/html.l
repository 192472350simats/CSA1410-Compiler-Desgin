
%{
#include <stdio.h>
int tags = 0;
%}

%%
"<"[^>]*">" {
    tags++;
    printf("%s\n", yytext);
}
.|\n { }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    char file[100];

    printf("Enter File Name: ");
    scanf("%99s", file);

    yyin = fopen(file, "r");

    if (yyin == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    yylex();

    printf("Number of HTML tags: %d\n", tags);

    fclose(yyin);
    return 0;
}
