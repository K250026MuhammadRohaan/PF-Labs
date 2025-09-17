#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
int main (void)
{
	int age;
	char name[50], course[30], result[6];
	
	printf("\nEnter your Name:  ");
	scanf(" %[^\n]", name);
	
	printf("Enter your Age:  ");
	scanf(" %d", &age);
	
	printf("Enter your Course:  ");
	scanf(" %[^\n]", course);
	
	printf("Enter your Result:  ");
	scanf(" %[^\n]", result);
	
	printf("\n\n---------------------------------------------------------------------------------------------------------\n\n");
	
	printf("Name: %s\n\n", name);
	printf("Age: %d\n\n", age);
	printf("Course: \"%s\"\n\n", course);
	printf("Result: %s\n\n", result);
	
	getch();
	return 0;
}
