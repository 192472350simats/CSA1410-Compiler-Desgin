#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    int i, flag = 0;

    printf("Grammar: S->aS, S->Sb, S->ab\n");
    printf("Enter the string: ");
    scanf("%49s", str);

    if (str[0] != 'a')
    {
        printf("String not accepted");
        return 0;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'b')
            flag = 1;
        else if (str[i] == 'a' && flag == 1)
        {
            printf("String not accepted");
            return 0;
        }
    }

    if (flag)
        printf("String accepted");
    else
        printf("String not accepted");

    return 0;
}