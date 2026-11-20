#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], result[20];
    char temp[10];
    int i, j = 1;

    printf("Enter expression (example: out=in1+in2+in3): ");
    scanf("%99s", input);

    char *p = strchr(input, '=');

    if (p == NULL)
        return 0;

    *p = '\0';
    strcpy(result, input);

    char *rhs = p + 1;
    char *token = strtok(rhs, "+-");

    if (token == NULL)
        return 0;

    strcpy(temp, token);

    while ((token = strtok(NULL, "+-")) != NULL)
    {
        char op = rhs[strlen(temp)];

        printf("t%d=%s%c%s\n", j, temp, op, token);
        sprintf(temp, "t%d", j);
        j++;
    }

    printf("%s=%s\n", result, temp);

    return 0;
}