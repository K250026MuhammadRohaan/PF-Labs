#include <stdio.h>
#include <conio.h>

#define LIMIT 10

void analyzeData(int *arr, int n, int *max, int *min, float *avg)
{
    for(int i=0 ; i<n ; i++)
    {
        if (arr[i] > *max) *max = arr[i];
    }

    for(int i=0 ; i<n ; i++)
    {
        if (arr[i] < *min) *min = arr[i];
    }

    float sum=0;
    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i];
    }
    *avg = sum/n;
}

int main ()
{
    int temp[LIMIT];

    for (int i=0; i<LIMIT; i++)
    {
        printf("\nEnter temperature reading no. %d:  ", i+1);
        scanf("%d", &temp[i]);
    }

    int len = sizeof(temp)/sizeof(temp[0]);

    int max=temp[0], min=temp[0];
    float avg=0;

    analyzeData(temp, len, &max, &min, &avg);

    printf("\n\nMaximum Temperature = %d", max);
    printf("\nMinimum Temperature = %d", min);
    printf("\nAverage Temperature = %.2f\n", avg);

    getch();
    return 0;
}