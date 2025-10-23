#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\n\t\t\t====================   RECENT TO FIRST POSITION - SHIFTING ARRAY   ====================\n\n");

    int numberReadings, i;

    printf("\nEnter no. of readings you want to take:-  ");
    scanf("%d", &numberReadings);
    printf("\n");

    int readings[numberReadings], temp;

    for (i=0 ; i<numberReadings ; i++)
    {
        printf("Enter Reading no. %d:-  ", i+1);
        scanf("%d", &readings[i]);
    }

    temp = readings[numberReadings - 1];

    for (i=numberReadings-1 ; i>0 ; i--)
    {
        readings[i] = readings[i-1];
    }

    readings[0] = temp;

    printf("\n\n\n-> READINGS (with RECENT Reading moved to FIRST position):- \n");

    for (i=0 ; i<numberReadings ; i++)
    {
        printf("\n  - Reading no. %d in array:-  %d", i+1, readings[i]);
    }
    printf("\n");

    getch();
    return 0;
}
