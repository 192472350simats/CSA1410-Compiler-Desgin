#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n;
char production[10][10];
char follow[20];

void add(char ch)
{
    int i;
    for (i = 0; follow[i] != '\0'; i++)
        if (follow[i] == ch)
            return;

    follow[i] = ch;
    follow[i + 1] = '\0';
}

void FIRST(char ch, char result[])
{
    int i, j;

    if (!isupper(ch))
    {
        result[0] = ch;
        result[1] = '\0';
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (production[i][0] == ch)
        {
            if (production[i][2] == '$')
                strcat(result, "$");
            else
            {
                j = 2;
                while (production[i][j] != '\0')
                {
                    if (!isupper(production[i][j]))
                    {
                        strncat(result, &production[i][j], 1);
                        break;
                    }
                    j++;
                }
            }
        }
    }
}

void FOLLOW(char ch)
{
    int i, j;
    char temp[20];

    if (ch == production[0][0])
        add('$');

    for (i = 0; i < n; i++)
    {
        for (j = 2; production[i][j] != '\0'; j++)
        {
            if (production[i][j] == ch)
            {
                if (production[i][j + 1] != '\0')
                {
                    temp[0] = '\0';
                    FIRST(production[i][j + 1], temp);

                    for (int k = 0; temp[k] != '\0'; k++)
                        if (temp[k] != '$')
                            add(temp[k]);
                }
                else if (production[i][0] != ch)
                {
                    FOLLOW(production[i][0]);
                }
            }
        }
    }
}

int main()
{
    int i;
    char ch;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter production %d: ", i + 1);
        scanf("%9s", production[i]);
    }

    do
    {
        follow[0] = '\0';

        printf("Enter non-terminal: ");
        scanf(" %c", &ch);

        FOLLOW(ch);

        printf("FOLLOW(%c) = { ", ch);
        for (i = 0; follow[i] != '\0'; i++)
            printf("%c ", follow[i]);
        printf("}\n");

        printf("Continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}