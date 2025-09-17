#include <stdio.h>
#include <conio.h>
int main (void)
{
	printf("\n\t\t\t----------  INTEGER ASCII CODE PRINTER  ----------\n\n");
	
	int num_int;
	char num_1dig, num_2dig;
	
	try_again:
	
	printf("\nEnter a two-digit integer between 65 and 90:  ");
	num_1dig = getche();
	num_2dig = getchar();
	getchar();
	
	num_int = (num_1dig - '0') * 10 + (num_2dig - '0');
	
	if( num_int < 65 || num_int > 90 )
	{
		printf("\nThat's NOT in range, Try Again.");
		goto try_again;
	}
	
	printf("\n\n\nInput -> %c%c", num_1dig, num_2dig);
	printf("\nOutput -> %c%c = %d %d", num_1dig, num_2dig, num_1dig, num_2dig);
	
	getch();
	return 0;
}
