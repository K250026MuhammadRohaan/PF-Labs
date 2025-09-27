#include <stdio.h>
#include <conio.h>

int main()
{
	int categoryChoice, foodChoice, drinkChoice;
	printf("\n\t\t\t\t------------ ONLINE FOOD ORDERING SYSTEM ------------\n");
	
	printf("\nEnter what do you want to order?  ");
	
	printf("\n1. Fast Food");
	printf("\n2. Drinks\n\n");
	
	scanf("%d", &categoryChoice);
	
	switch(categoryChoice)
	{
		case 1:
			printf("\n\nChoose from our selection of Fast food \n1. [Pasta] \n2. [Burger] \n3. [Pizza] \n4. [French Fries]\n\n");
			scanf("%d", &foodChoice);
			
			switch(foodChoice)
			{
				case 1: printf("\n\n[PASTA ORDERED]"); break;
				case 2: printf("\n\n[BURGER ORDERED]"); break;
				case 3: printf("\n\n[PIZZA ORDERED]"); break;
				case 4: printf("\n\n[FRENCH FRIES ORDERED]"); break;
				
				default:
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
		
		case 2:
			printf("\n\nChoose from our selection of Drinks \n1. [Coca Cola] \n2. [Pepsi] \n3. [Doctor Pepper] \n4. [Mountain Dew]\n\n");
			scanf("%d", &drinkChoice);
			
			switch(drinkChoice)
			{
				case 1: printf("\n\n[COCA COLA ORDERED]"); break;
				case 2: printf("\n\n[PEPSI ORDERED]"); break;
				case 3: printf("\n\n[DOCTOR PEPPER ORDERED]"); break;
				case 4: printf("\n\n[MOUNTAIN DEW ORDERED]"); break;
				
				default:
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
			
		default:
			printf("\n\nINVALID INPUT");
			break;
	}
	
	getch();
	return 0;
}
