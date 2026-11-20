#include <stdio.h>
#include <string.h>

int main()
{
    char gram[50], part1[25], part2[25];
    char common[25], newgram[50];
    int i, j = 0, k = 0, pos = 0;

    printf("Enter production (example S->iEtS|iEtSeS): ");
    scanf("%49s", gram);

    for (i = 3; gram[i] != '|' && gram[i] != '\0'; i++)
        part1[j++] = gram[i];
    part1[j] = '\0';

    j = 0;
    i++;

    while (gram[i] != '\0')
        part2[j++] = gram[i++];
    part2[j] = '\0';

    while (part1[k] != '\0' && part1[k] == part2[k])
    {
        common[k] = part1[k];
        k++;
    }
    common[k] = '\0';
    pos = k;

    if (pos == 0)
    {
        printf("No common prefix found");
        return 0;
    }

    printf("%c->%sX\n", gram[0], common);
    printf("X->%s|%s\n", part1 + pos, part2 + pos);

    return 0;
}