#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\n\t\t\t====================   REVERSAL OF READINGS IN ARRAY   ====================\n\n");

    int numberReadings;

    printf("\nEnter no. of readings you want to take:-  ");
    scanf("%d", &numberReadings);
    printf("\n");

    int readings[numberReadings], temp;

    for (int i=0 ; i<numberReadings ; i++)
    {
        printf("Enter Reading no. %d:-  ", i+1);
        scanf("%d", &readings[i]);
    }

    for (int i=0 ; i < numberReadings/2 ; i++)
    {
        temp = readings[i];
        readings[i] = readings[numberReadings-i-1];
        readings[numberReadings-i-1] = temp;
    }

    printf("\n\n\n-> Readings in REVERSE CHRONOLOGICAL ORDER:- \n");

    for (int i=0 ; i<numberReadings ; i++)
    {
        printf("\n  - Reading no. %d:-  %d", i+1, readings[i]);
    }
    printf("\n");

    getch();
    return 0;
}
