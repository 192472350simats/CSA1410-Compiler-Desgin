#include <stdio.h>

int main()
{
    int n, i;
    char a[50][50];

    printf("Enter number of intermediate codes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter three address code %d: ", i + 1);
        scanf("%49s", a[i]);
    }

    printf("\nGenerated target code:\n");

    for (i = 0; i < n; i++)
    {
        printf("MOV %c, R%d\n", a[i][2], i);

        if (a[i][3] == '+')
            printf("ADD %c, R%d\n", a[i][4], i);
        else if (a[i][3] == '-')
            printf("SUB %c, R%d\n", a[i][4], i);
        else if (a[i][3] == '*')
            printf("MUL %c, R%d\n", a[i][4], i);
        else if (a[i][3] == '/')
            printf("DIV %c, R%d\n", a[i][4], i);

        printf("MOV R%d, %c\n\n", i, a[i][0]);
    }

    return 0;
}