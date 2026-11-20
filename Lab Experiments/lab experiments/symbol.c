#include <stdio.h>
#include <string.h>

struct symbol
{
    char label[20];
    int addr;
} sy[50];

int count = 0;

int search(char name[])
{
    int i;
    for (i = 0; i < count; i++)
        if (strcmp(sy[i].label, name) == 0)
            return i;
    return -1;
}

int main()
{
    int ch, addr, pos;
    char name[20];

    do
    {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Modify\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter label: ");
                scanf("%19s", name);

                if (search(name) != -1)
                    printf("Duplicate symbol\n");
                else
                {
                    strcpy(sy[count].label, name);
                    printf("Enter address: ");
                    scanf("%d", &sy[count].addr);
                    count++;
                }
                break;

            case 2:
                for (int i = 0; i < count; i++)
                    printf("%s\t%d\n", sy[i].label, sy[i].addr);
                break;

            case 3:
                printf("Enter label: ");
                scanf("%19s", name);
                pos = search(name);

                if (pos != -1)
                    printf("Label found\n");
                else
                    printf("Label not found\n");
                break;

            case 4:
                printf("Enter label: ");
                scanf("%19s", name);
                pos = search(name);

                if (pos == -1)
                    printf("No such symbol\n");
                else
                {
                    printf("Enter new address: ");
                    scanf("%d", &addr);
                    sy[pos].addr = addr;
                    printf("Address modified\n");
                }
                break;
        }
    } while (ch != 5);

    return 0;
}