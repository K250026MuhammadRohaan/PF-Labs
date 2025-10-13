#include <stdio.h>
#include <conio.h>

int main()
{
    int num, digit;

	printf("\n\t\t\t========================  TICKET NUMBER REVERSAL  ========================\n\n");

    printf("Enter your ticket number (integer):  ");
    scanf("%d", &num);
    
	printf("\n\nThe Reverse of your integer (ticket number) is:   ");
    while (num != 0)
	{
        digit = num % 10;
        printf("%d", digit);
        num /= 10;
    }
    
    printf("\n");
	getch();
    return 0;
}

