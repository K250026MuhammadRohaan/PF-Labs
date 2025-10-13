#include <stdio.h>
#include <conio.h>

int main()
{
    int n;
    
    printf("\n\t\t\t========================  LED BANNER MAKER  ========================\n\n");
    
    printf("Enter the half-height of diamond (+ve integer):  ");
    scanf("%d", &n);
    printf("\n\n");
    
    if (n<=0)
	{
        printf("INVALID INPUT. Please enter a positive integer.\n");
        return 1;
    }

	// Top Portion
    for (int i=1 ; i<=n ; i++)
	{
        int outer = n - i;       
        int inner = (2 * i) - 3;

        for (int j=0 ; j<outer ; j++)
			printf(" ");

        printf("*");

        if (i > 1)
		{
            for (int j=0 ; j<inner ; j++)
				printf(" ");
            printf("*");
        }

        printf("\n");
    }


	// Bottom Portion
    for (int i=n - 1 ; i>=1 ; i--)
	{
        int outer = n - i;
        int inner = (2 * i) - 3;

        for (int j=0 ; j<outer ; j++)
			printf(" ");		
        printf("*");
        
        if (i > 1)
		{
            for (int j=0 ; j<inner ; j++)
				printf(" ");
            printf("*");
        }
        printf("\n");
    }

	printf("\n");
	getch();
    return 0;
}

