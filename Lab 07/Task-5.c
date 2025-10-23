#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\n\t\t\t====================   MERGING TWO ARRAYS INTO ONE NEW ARRAY   ====================\n\n");

    int num_sensor1;
    printf("\nEnter no. of Hours of readings for Sensor 1:-  ");
    scanf("%d", &num_sensor1);

    int sensor1[num_sensor1];
    for (int i=0 ; i<num_sensor1 ; i++)
    {
        printf("- Enter Sensor 1 Reading for HOUR no.%3d:-  ", i+1);
        scanf("%d", &sensor1[i]);
    }


    int num_sensor2;
    printf("\nEnter no. of Hours of readings for Sensor 2:-  ");
    scanf("%d", &num_sensor2);

    int sensor2[num_sensor2];
    for (int i=0 ; i<num_sensor2 ; i++)
    {
        printf("- Enter Sensor 2 Reading for HOUR no.%3d:-  ", i+1);
        scanf("%d", &sensor2[i]);
    }

    
    int combinedReadings[num_sensor1+num_sensor2];

    for (int i=0 ; i<num_sensor1+num_sensor2 ; i++)
    {
        if(i<num_sensor1) combinedReadings[i] = sensor1[i];
        else combinedReadings[i] = sensor2[i-num_sensor1];
    }


    printf("\n\n\n-> READINGS (MERGED into ONE New Array):- \n");

    for (int i=0 ; i<num_sensor1+num_sensor2 ; i++)
    {
        printf("\n  - Reading no. %d in array:-\t%d", i+1, combinedReadings[i]);
    }
    printf("\n");

    getch();
    return 0;
}
