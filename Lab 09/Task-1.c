#include <stdio.h>
#include <conio.h>

void inputData(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter total no. of patients for DAY %d:  ", i + 1);
        scanf("%d", &arr[i]);
    }
}

float averagePatients(int arr[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    float avgP = total / n;
    return avgP;
}

int busiestDay(int arr[], int n)
{
    int busyDay = 0, busyDay_Patients = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > busyDay_Patients)
        {
            busyDay_Patients = arr[i];
            busyDay = i + 1;
        }
    }

    printf("\n\nBusiest Day: Day %d (%d patients)", busyDay, busyDay_Patients);
}

int slowestDay(int arr[], int n)
{
    int slowDay = 1;
    int slowDay_Patients = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < slowDay_Patients)
        {
            slowDay_Patients = arr[i];
            slowDay = i + 1;
        }
    }
    printf("\n\nSlowest Day: Day %d (%d patients)", slowDay, slowDay_Patients);
}

int main()
{
    int arr[7];

    inputData(arr, 7);

    float avgPatients = averagePatients(arr, 7);
    printf("\n\nAverage Patients per Day:  %.2f", avgPatients);

    busiestDay(arr, 7);

    slowestDay(arr, 7);

	printf("\n");
    getch();
    return 0;
}
