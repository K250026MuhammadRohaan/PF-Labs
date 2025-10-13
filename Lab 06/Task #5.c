#include <stdio.h>
#include <conio.h>

int main()
{
	int num, fact=1;
	
	printf("\n\t\t\t========================  GAME SCORE MULTIPLIER  ========================\n\n");
	
	printf("\nEnter a number:  ");
	scanf("%d", &num);
	
	for(int i=1; i<=num; i++)
	{
		fact *= i;
	}
	
	printf("\n\nThe factorial of the number %d is:  %d\n", num, fact);
	
	getch();
	return 0;
}
