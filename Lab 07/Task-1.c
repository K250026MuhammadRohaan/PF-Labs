#include <stdio.h>
#include <conio.h>

int main()
{
	printf("\n\t\t\t====================   TEMP MAX AND MIN VALUES   ====================\n\n");
	
	int readings, i=0;

	printf("\nEnter how many readings you want to store:  ");
	scanf("%d", &readings);

	int temp[readings];

	for (i=0; i<readings; i++)
	{
		printf("- Enter Temperature reading #%d: ", i+1);
		scanf("%d", &temp[i]);
	}

    int max_temp=temp[0], min_temp=temp[0], max_index=0, min_index=0;
    
    for (i=0 ; i<readings ; i++)
    {
    	if (temp[i] >= max_temp)
    	{
    		max_temp = temp[i];
    		max_index = i;
		}
	}
	
	for (i=0 ; i<readings ; i++)
	{
		if (temp[i] <= min_temp)
    	{
    		min_temp = temp[i];
    		min_index = i;
		}
	}

	printf("\n----------------------------------------------------------\n");
    printf("\nThe MAX Temperature is: %d Degress Fahrenheit, at index=%d\n", max_temp, max_index);
    printf("\nThe MIN Temperature is: %d Degress Fahrenheit, at index=%d\n", min_temp, min_index);

    getch();
    return 0;
}
