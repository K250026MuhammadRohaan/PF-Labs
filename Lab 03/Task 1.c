#include <stdio.h>
#include <conio.h>
int main (void)
{
	int Sub1, Sub2, Sub3, Total;
	float percent;
	
	printf("\n\t\t\t----------  TOTAL & PERCENTAGE CALCULATOR  ----------\n\n\n");
	
	printf("Enter marks of Subject #1 (out of 100):  ");
	scanf("%d", &Sub1);
	
	printf("Enter marks of Subject #2 (out of 100):  ");
	scanf("%d", &Sub2);
	
	printf("Enter marks of Subject #3 (out of 100):  ");
	scanf("%d", &Sub3);
	
	Total = Sub1 + Sub2 + Sub3;
	percent = ((float)(Total)/300) * 100;
	
	printf("\n\nTotal Marks (out of 300):  %d marks", Total);
	printf("\nPercentage (out of 100):  %.2f %%", percent);
	
	getch();
	return 0;
}
