#include <stdio.h>
#include <conio.h>

int main()
{
    int num, digit, evenNum=0, oddNum=0;

	printf("\n\t\t\t========================  ELECTRICITY BILLING SYSTEM  ========================\n\n");

    printf("Enter your Electricity meter reading:  ");
    scanf("%d", &num);

    while (num != 0)
	{
        digit = num % 10;
        
        if(digit % 2 == 0)
        	evenNum++;
        else
        	oddNum++;
        
        num /= 10;
    }
    
    printf("\n\nYour number (meter reading) has %d EVEN digits, and %d ODD digits.\n", evenNum, oddNum);

	getch();
    return 0;
}

