#include <stdio.h>
#include <string.h>

int main()
{
    char input[30], stack[30];
    int i, top = -1, len;

    printf("Grammar: E->E+E, E->E*E, E->E/E, E->a/b\n");
    printf("Enter the input: ");
    scanf("%29s", input);

    len = strlen(input);

    printf("\nStack\tInput\tAction\n");
    printf("$\t%s$\t--\n", input);

    for (i = 0; i < len; i++)
    {
        stack[++top] = input[i];
        stack[top + 1] = '\0';

        printf("$%s\t", stack);
        printf("%s$\tShift %c\n", input + i + 1, input[i]);

        if (stack[top] == 'a' || stack[top] == 'b')
        {
            stack[top] = 'E';
            printf("$%s\t%s$\tReduce E->%c\n",
                   stack, input + i + 1, input[i]);
        }

        if (top >= 2 &&
            stack[top - 2] == 'E' &&
            (stack[top - 1] == '+' ||
             stack[top - 1] == '*' ||
             stack[top - 1] == '/') &&
            stack[top] == 'E')
        {
            char op = stack[top - 1];
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';

            printf("$%s\t%s$\tReduce E->E%cE\n",
                   stack, input + i + 1, op);
        }
    }

    if (top == 0 && stack[0] == 'E')
        printf("$E\t$\tACCEPT\n");
    else
        printf("String rejected\n");

    return 0;
}