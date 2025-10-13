#include <stdio.h>
#include <conio.h>

int main()
{
	int i = 1, num, nos=0;
	float avg=0, total=0;
	
	printf("\n\t\t\t========================  MARKS ENTRY SYSTEM  ========================\n\n");
	
	while(1)
	{
		printf("\nEnter marks of Subject #%d (enter -1 to stop entering):  ", i);
		scanf(" %d", &num);
		
		if(num == -1) break;
		
		total += num;
		i++;
		nos++;
	}
	
	printf("\n\n\nThe average of all the marks of Subjects is:  %.2f\n", total/nos);
	
	getch();
	return 0;
}
