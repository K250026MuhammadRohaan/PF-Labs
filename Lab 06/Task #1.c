#include <stdio.h>
#include <conio.h>

int main()
{
	int n1, n2, temp_n3;
	
	printf("\n\nEnter your first number (a):  ");
	scanf(" %d", &n1);
	
	printf("\nEnter your second number (b):  ");
	scanf(" %d", &n2);
	
	printf("\n\n\n\nBefore Swapping:  a = %d,  b = %d", n1,n2);
	
	if( n1 > n2)
	{
	temp_n3 = n1;
	n1 = n2;
	n2 = temp_n3;
	}
	
	printf("\n\nAfter Swapping:  a = %d,  b = %d\n", n1,n2);
	
	getch();
	return 0;
}
