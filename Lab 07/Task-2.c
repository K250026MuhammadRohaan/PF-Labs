#include <stdio.h>
#include <conio.h>

int main()
{
    int num;
	float readings[24], sum=0, average=0;
    
    printf("\n\t\t\t====================   1 DAY - POWER USAGE CALCULATOR   ====================\n\n\n");
    
   	for (int i=0 ; i<24 ; i++)
   	{
   		printf("Enter reading in HOUR %d:  ", i+1);
   		scanf("%f", &readings[i]);
   		
   		sum += readings[i];
	}
	
	average = sum / 24;
   	
   	printf("\n\nThe Total Usage for the Day (24 hrs) is:  %.2f watts", sum);
	printf("\n\nThe Average Usage for the Day is:  %.2f watts / hr\n", average);

    getch();
    return 0;
}
