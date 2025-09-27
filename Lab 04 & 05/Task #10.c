#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	int age, movieChoice;
	char ticketType[25], movieType[10];
	printf("\n\t\t\t\t----------  MOVIE TICKET SYSTEM  ----------\n\n");
	
	printf("\nEnter your age: ");
	scanf(" %d", &age);
	
	if((age <= 0))
	{
		printf("\nINVALID AGE ENTRY, EXITTED.");
		return -1;
	}
	else
	{
		if(age < 12)
		{
			strcpy(ticketType, "Child Ticket");
			printf("\n[CHOSEN: CHILD TICKET]");
		}
		else if( age >= 12 && age <= 60)
		{
			strcpy(ticketType, "Adult Ticket");
			printf("\n[CHOSEN: ADULT TICKET]");
		}
		else if(age > 60)
		{
			strcpy(ticketType, "Senior Citizen Ticket");
			printf("\n[CHOSEN: SENIOR CITIZEN TICKET]");
		}
	}
	
	printf("\n\n\nEnter the type of Movie you want to watch:\n1. Action\n2. Comedy\n3. Horror\n\n");
	scanf(" %d", &movieChoice);
		
	switch(movieChoice)
	{
		case 1:
			printf("\n[CHOSEN: ACTION MOVIE]");
			strcpy(movieType, "Action");
			break;
		
		case 2:
			printf("\n[CHOSEN: COMEDY MOVIE]");
			strcpy(movieType, "Comedy");
			break;
			
		case 3:
			printf("\n[CHOSEN: HORROR MOVIE]");
			strcpy(movieType, "Horror");
			break;
		
		default:
			printf("\nINVALID MOVIE CHOICE, EXITTED.");
			return -1;
	}
	
	printf("\n\n\n\n\tYou Chose:  %s - %s Movie\n", ticketType, movieType);
	
	getch();
	return 0;
}
