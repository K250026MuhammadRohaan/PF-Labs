#include <stdio.h>
#include <conio.h>

int main()
{
	int depChoice, csChoice, eeChoice, bbaChoice;
	printf("\n\t\t\t\t------------ UNIVERSITY COURSE REGISTRATION SYSTEM ------------\n");
	
	printf("\nPlease select a department: \n1. CS \n2. EE \n3. BBA\n\n");	
	scanf("%d", &depChoice);
	
	switch(depChoice)
	{
		case 1:
			printf("\n\nPlease select one of the courses listed below: \n1. Data Structures & Algorithms \n2. Programming Languages \n3. Database Management\n\n");
			scanf("%d", &csChoice);
			
			switch(csChoice)
			{
				case 1: printf("\n\n[Chosen Course:  Data Structures and Algorithms]"); break;
				case 2: printf("\n\n[Chosen Course:  Programming Languages]"); break;
				case 3: printf("\n\n[Chosen Course:  Database Management]"); break;
				
				default:
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
		
		case 2:
			printf("\n\nPlease select one of the courses listed below: \n1. Embedded Systems & Internet of Things (IoT) \n2. Power System Analysis \n3. Very Large Scale Integration (VLSI) Design\n\n");
			scanf("%d", &eeChoice);
			
			switch(eeChoice)
			{
				case 1: printf("\n\n[Chosen Course:  Embedded Systems & Internet of Things (IoT)]"); break;
				case 2: printf("\n\n[Chosen Course:  Power System Analysis]"); break;
				case 3: printf("\n\n[Chosen Course:  Very Large Scale Integration (VLSI) Design]"); break;
				
				default:
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
			
		case 3:
			printf("\n\nPlease select one of the courses listed below: \n1. Marketing Management \n2. Financial Accounting \n3. Human Resource Management\n\n");
			scanf("%d", &bbaChoice);
			
			switch(bbaChoice)
			{
				case 1: printf("\n\n[Chosen Course:  Marketing Management]"); break;
				case 2: printf("\n\n[Chosen Course:  Financial Accounting]"); break;
				case 3: printf("\n\n[Chosen Course:  Human Resource Management]"); break;
				
				default:
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
			
			
		default:
			printf("\n\nINVALID INPUT");
			break;
	}
	
	printf("\n");
	getch();
	return 0;
}
