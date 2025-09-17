#include <stdio.h>
#include <conio.h>
int main (void)
{
	int a, b, swap;
	
	printf("\n\t\t\t----------  TWO INTEGERS SWAPPER  ----------\n\n\n");
	
	printf("Enter first integer:  ");
	scanf("%d", &a);
	
	printf("Enter second integer:  ");
	scanf("%d", &b);
	
	printf("\n\nInput -> a = %d, b = %d", a, b);
	
	swap = a;
	a = b;
	b = swap;
	
	printf("\nOutput -> a = %d, b = %d", a, b);
	
	getch();
	return 0;
}
