#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	int pass;
	char user[25];
	printf("\n\t\t\t\t------------ LOGIN SYSTEM ------------\n\n");
	
	printf("\nEnter username:  ");
	scanf(" %s", user);
    
	printf("\nEnter password:  ");
	scanf(" %d", &pass);
	
	if(strcmp(user, "admin") == 0)
	{
		if(pass == 1234)
		{
			printf("\n\nLogin Successful\n");
		}
		else
		{
			printf("\n\n[ERROR: INCORRECT PASSWORD]\n");
		}
	}
	else
	{
		printf("\n\n[ERROR: INCORRECT USERNAME]\n");
	}
	
	getch();
	return 0;
}
