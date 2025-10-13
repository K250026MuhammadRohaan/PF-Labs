#include <stdio.h>
#include <conio.h>

int main()
{
	int num;
	
	printf("\n\t\t\t========================  CLASSROOM APP  ========================\n\n");
	
	printf("\nEnter a number:  ");
	scanf("%d", &num);
	
	printf("\n\nMultiplication Table of %d:\n", num);
	
	for(int i=1; i<=10; i++)
	{
		printf("\n%d x %d = %d", num, i, num*i);
	}
	printf("\n");
	
	getch();
	return 0;
}
