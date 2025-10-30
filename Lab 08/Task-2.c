#include <stdio.h>
#include <conio.h>

int main()
{
    char names[5][20];

    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter Name of Student no. %d:   ", i+1);
        scanf("%s", names[i]);
    }

    printf("\n\n\n->  Entered Names of Students:-\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nStudent no. %d:   %s", i+1, names[i]);
    }

	printf("\n");
    getch();
    return 0;
}
