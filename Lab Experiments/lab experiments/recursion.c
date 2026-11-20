#include <stdio.h>
#include <string.h>

int main()
{
    char nt, alpha[20], beta[20];
    char production[50];
    int i = 3, j = 0, k = 0;

    printf("Enter production (example E->E-A|B): ");
    scanf("%49s", production);

    nt = production[0];

    if (production[3] == nt)
    {
        i = 4;

        while (production[i] != '|' && production[i] != '\0')
            alpha[j++] = production[i++];

        alpha[j] = '\0';

        if (production[i] == '|')
        {
            i++;
            while (production[i] != '\0')
                beta[k++] = production[i++];

            beta[k] = '\0';

            printf("Grammar without left recursion:\n");
            printf("%c->%s%c'\n", nt, beta, nt);
            printf("%c'->%s%c'|$\n", nt, alpha, nt);
        }
        else
            printf("Cannot eliminate left recursion");
    }
    else
        printf("Grammar is not left recursive");

    return 0;
}