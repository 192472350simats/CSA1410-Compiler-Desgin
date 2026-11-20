#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[50];
    int i, flag = 1;

    printf("Enter an identifier: ");
    scanf("%49s", str);

    if (!isalpha(str[0]) && str[0] != '_')
        flag = 0;

    for (i = 1; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Valid identifier");
    else
        printf("Not a valid identifier");

    return 0;
}