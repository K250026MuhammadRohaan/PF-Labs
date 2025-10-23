#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\n\t\t\t====================   REMOVAL OF A VALUE FROM ENTIRE ARRAY   ====================\n\n");

    int number_Readings, i, updatedSize=0, numToRemove=0, value;

    printf("\nEnter no. of readings you want to take:-  ");
    scanf("%d", &number_Readings);
    printf("\n");

    int readings[number_Readings];

    for (i=0 ; i<number_Readings ; i++)
    {
        printf("Enter Reading no. %d:-\t", i+1);
        scanf("%d", &readings[i]);
    }

    printf("\n\nEnter a value to remove from the array:  ");
    scanf("%d", &value);

    updatedSize = number_Readings;

    for (i=0 ; i<number_Readings ; i++)
    {
        if(readings[i] == value)
        {
            int index = i;
            for (int j=index; j<number_Readings ; j++)
            {
                readings[j] = readings[j+1];
            }
            updatedSize--;
            i--;
        }
    }

    printf("\n\n\n-> UPDATED READINGS ARRAY of SIZE: %d (with value: %d REMOVED):- \n", updatedSize, value);

    for (i=0 ; i<updatedSize ; i++)
    {
        printf("\n  - Reading no. %d in array:-\t%d", i+1, readings[i]);
    }
    printf("\n");

    getch();
    return 0;
}
