#include <stdio.h>
#include <ctype.h>

int n;
char production[10][10];

void add(char result[], char ch)
{
    int i;
    for (i = 0; result[i] != '\0'; i++)
        if (result[i] == ch)
            return;

    result[i] = ch;
    result[i + 1] = '\0';
}

void FIRST(char result[], char ch)
{
    int i, j, k, epsilon;
    char temp[20];

    result[0] = '\0';

    if (!isupper(ch))
    {
        add(result, ch);
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (production[i][0] == ch)
        {
            if (production[i][2] == '$')
                add(result, '$');
            else
            {
                j = 2;
                while (production[i][j] != '\0')
                {
                    epsilon = 0;
                    FIRST(temp, production[i][j]);

                    for (k = 0; temp[k] != '\0'; k++)
                    {
                        add(result, temp[k]);
                        if (temp[k] == '$')
                            epsilon = 1;
                    }

                    if (!epsilon)
                        break;
                    j++;
                }
            }
        }
    }
}

int main()
{
    int i;
    char ch, result[20];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter production %d: ", i + 1);
        scanf("%9s", production[i]);
    }

    do
    {
        printf("Find FIRST of: ");
        scanf(" %c", &ch);

        FIRST(result, ch);

        printf("FIRST(%c) = { ", ch);
        for (i = 0; result[i] != '\0'; i++)
            printf("%c ", result[i]);
        printf("}\n");

        printf("Continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}