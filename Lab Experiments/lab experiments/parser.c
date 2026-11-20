#include <stdio.h>
#include <string.h>

char input[50];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();

int E()
{
    if (T())
        return EP();
    return 0;
}

int EP()
{
    if (input[i] == '+')
    {
        i++;
        if (T())
            return EP();
        return 0;
    }
    return 1;
}

int T()
{
    if (F())
        return TP();
    return 0;
}

int TP()
{
    if (input[i] == '*')
    {
        i++;
        if (F())
            return TP();
        return 0;
    }
    return 1;
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E() && input[i] == ')')
        {
            i++;
            return 1;
        }
        return 0;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }
    return 0;
}

int main()
{
    printf("Enter the string: ");
    scanf("%49s", input);

    if (E() && input[i] == '\0')
        printf("String is accepted");
    else
        printf("String is not accepted");

    return 0;
}