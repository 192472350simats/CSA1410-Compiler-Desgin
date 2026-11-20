%{
#include <stdio.h>
#include <stdlib.h>

int f1 = 0, f2 = 0;
char oper;
float op1 = 0, op2 = 0, ans = 0;

void eval();
%}

DIGIT [0-9]
NUM {DIGIT}+(\.{DIGIT}+)?
OP [*/+-]

%%
{NUM} {
    if (f1 == 0)
    {
        op1 = atof(yytext);
        f1 = 1;
    }
    else if (f2 == -1)
    {
        op2 = atof(yytext);
        f2 = 1;
    }

    if (f1 == 1 && f2 == 1)
    {
        eval();
        f1 = 0;
        f2 = 0;
    }
}

{OP} {
    oper = yytext[0];
    f2 = -1;
}

[ \t]+ ;

\n ;
%%

int main()
{
    printf("Enter expression (example: 20 + 30):\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

void eval()
{
    switch (oper)
    {
        case '+':
            ans = op1 + op2;
            break;

        case '-':
            ans = op1 - op2;
            break;

        case '*':
            ans = op1 * op2;
            break;

        case '/':
            if (op2 == 0)
            {
                printf("ERROR: Division by zero\n");
                return;
            }
            ans = op1 / op2;
            break;
    }

    printf("The answer is = %f\n", ans);
}