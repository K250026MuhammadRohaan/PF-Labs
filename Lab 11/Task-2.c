#include <stdio.h>
#include <conio.h>

void countdown(int days)
{
    if (days == 0)
    {
        printf("0  -  EVENT DAY!\n");
        return;
    }

    printf("%d\n", days);
    countdown(days - 1);
}

int main()
{
    int n;

    printf("\nEnter number of events: ");
    scanf("%d", &n);

    int daysLeft[n];

    for (int i=0 ; i<n ; i++)
    {
        printf("Enter days remaining for Event %d: ", i+1);
        scanf("%d", &daysLeft[i]);
    }

    printf("\n\n==========  Countdown for All Events  ==========\n");

    for (int i=0 ; i<n ; i++)
    {
        printf("\nEvent %d Countdown:\n", i+1);
        countdown(daysLeft[i]);
    }

    getch();
    return 0;
}
