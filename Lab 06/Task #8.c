#include <stdio.h>
#include <conio.h>

unsigned long long fact(int num)
{
    unsigned long long fact = 1;
    
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int num;
    printf("\n\t\t\t========================  CATALAN SERIES  ========================\n\n");

    printf("Enter the no. of terms of Catalan Series:  ");
    scanf("%d", &num);
    printf("\n");

    for (int i=1; i <= num; i++)
    {
        unsigned long long catalanTerm = fact(2 * i) / (fact(i + 1) * fact(i));
        
        if (i == 1)
            printf("%llu", catalanTerm);
        else
            printf(", %llu", catalanTerm);
    }

	printf("\n");
    getch();
    return 0;
}

