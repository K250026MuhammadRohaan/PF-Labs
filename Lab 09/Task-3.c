#include <stdio.h>
#include <conio.h>

#define MAX_LIMIT 100

int targetCountCheck(int arr[], int totalRoadNum, int target, int *firstRoad, int *secondRoad)
{
    for (int i=0 ; i<totalRoadNum ; i++)
    {
        for (int j=i+1 ; j<totalRoadNum ; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                *firstRoad = i;
                *secondRoad = j;
                return 1;
            }
        }
    }
    return 0;
}

int main ()
{
    int n, roadVehicleCount[MAX_LIMIT], targetVehicleCount, firstRoad, secondRoad;

    printf("\nEnter no. of roads in the city:  ");
    scanf("%d", &n);
    printf("\n");

    for (int i=0 ; i<n ; i++)
    {
        printf("Enter Vehicle Count of Road no. %d:  ", i+1);
        scanf("%d", &roadVehicleCount[i]);
    }

    printf("\n\nEnter Target Vehicle Count:  ");
    scanf("%d", &targetVehicleCount);

    int hasFoundRoads = targetCountCheck(roadVehicleCount, n, targetVehicleCount, &firstRoad, &secondRoad);

    if (hasFoundRoads == 1)
    {
        printf("\n\n-->  The Two Roads whose Combined Vehicle Count is equal to the Target Count is:\n\n- Road no. %d\n- Road no. %d\n", firstRoad+1, secondRoad+1);
    }
    else
    {
        printf("\n\n-->  NO Two Roads FOUND, whose Combined Vehicle Count is equal to the Target Count\n");
    }

    getch();
    return 0;
}