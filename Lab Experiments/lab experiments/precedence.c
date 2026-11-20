#include <stdio.h>
#include <string.h>

char input[50], stack[50];
int top = 0, i = 0;

char prec[9][9] = {
    {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '>', 'e', 'e', '>', '>'},
    {'<', '<', '<', '<', '<', '<', '<', '>', 'e'},
    {'>', '>', '>', '>', '>', 'e', 'e', '>', '>'},
    {'<', '<', '<', '<', '<', '<', '<', '<', '>'}
};

int getindex(char ch)
{
    switch (ch)
    {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '^': return 4;
        case 'i': return 5;
        case '(': return 6;
        case ')': return 7;
        case '$': return 8;
    }
    return -1;
}

int main()
{
    char relation;
    int a, b;

    printf("Enter expression using i for identifiers: ");
    scanf("%49s", input);

    strcat(input, "$");
    stack[0] = '$';

    printf("\nStack\tInput\tAction\n");

    while (1)
    {
        a = getindex(stack[top]);
        b = getindex(input[i]);

        if (a == -1 || b == -1)
        {
            printf("Invalid symbol\n");
            break;
        }

        relation = prec[a][b];

        if (relation == '<' || relation == '=')
        {
            stack[++top] = input[i++];
            stack[top + 1] = '\0';
            printf("%s\t%s\tShift\n", stack, input + i);
        }
        else if (relation == '>')
        {
            if (stack[top] == 'i' || stack[top] == ')')
            {
                while (top > 0 && stack[top] != '(' &&
                       stack[top] != '$')
                    top--;
                if (stack[top] == '(')
                    top--;
            }
            else
                top--;

            stack[++top] = 'E';
            stack[top + 1] = '\0';
            printf("%s\t%s\tReduce\n", stack, input + i);
        }
        else
        {
            printf("String rejected\n");
            break;
        }

        if (stack[0] == '$' && stack[1] == 'E' &&
            input[i] == '$')
        {
            printf("String accepted\n");
            break;
        }
    }

    return 0;
}