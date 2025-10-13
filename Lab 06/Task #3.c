#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

bool isPrime(int num)
{
    if (num < 2)
        return false;
    
    for (int i=2 ; i*i <= num ; i++)
	{
        if (num%i == 0)
        	return false;
    }
    return true;
}

int main()
{
    int n;
    
    printf("\n\t\t\t========================  ID VALIDATION  ========================\n\n");

    printf("Enter your Student ID (number) :  ");
    scanf("%d", &n);

    if (isPrime(n))
        printf("\n%d is a valid student ID (prime number).\n", n);
    else
        printf("\n%d is NOT a valid student ID (NOT a prime number).\n", n);

    printf("\nPrime numbers from 1 to %d are:\n", n);
    
    for (int i=1 ; i<=n ; i++)
	{
        if (isPrime(i))
            printf("%d ", i);
    }

    printf("\n");
    getch();
    return 0;
}

