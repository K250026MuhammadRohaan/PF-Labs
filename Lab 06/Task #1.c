#include <stdio.h>
#include <conio.h>

int main()
{
    int pin, digit, lenCheck=0, originalPin, sum=0;

	printf("\n\t\t\t========================  ATM PIN CHECK  ========================\n\n");

    printf("Enter a 4-digit PIN:  ");
    scanf("%d", &pin);
   	printf("\n");
   
   	originalPin = pin;
    while (pin != 0)
	{
        digit = pin % 10;
        lenCheck++;
        pin /= 10;
    }
    pin = originalPin;
    
    if(lenCheck > 4 || lenCheck < 4)
    {
    	printf("\nINVALID PIN. 4-digit PIN is required. EXITTING...\n");
	}
	
	originalPin = pin;
    while (pin != 0)
	{
        digit = pin % 10;
        sum += digit;
        pin /= 10;
    }
    pin = originalPin;
    
    if(sum > 10)
    	printf("\nThe Entered PIN: %d is a STRONG PIN.\n", pin);
    else
    	printf("\nThe Entered PIN: %d is a WEAK PIN.\n", pin);
	
	
    printf("\n");
	getch();
    return 0;
}

