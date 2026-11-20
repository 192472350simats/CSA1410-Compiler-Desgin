#include <stdio.h>

int main()
{
    char str[500];
    int words = 0, lines = 0, characters = 0;
    int i;

    printf("Enter text (press ~ to stop):\n");
    scanf("%[^~]", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            words++;
        else if (str[i] == '\n')
        {
            lines++;
            words++;
        }
        else
            characters++;
    }

    if (characters > 0)
    {
        words++;
        lines++;
    }

    printf("Total number of words: %d\n", words);
    printf("Total number of lines: %d\n", lines);
    printf("Total number of characters: %d\n", characters);

    return 0;
}