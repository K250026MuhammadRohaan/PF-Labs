#include <stdio.h>
#include <conio.h>

int main()
{
	int character;
	
	printf("\n\nEnter your character:  ");
	scanf(" %c", &character);
	
	if(character >= 48 && character <= 57)
		printf("\n\nThe entered character is: A DIGIT!\n");
	else if(character >= 65 && character <= 90)
		printf("\n\n\nThe entered character is: An UPPERCASE LETTER!\n");
	else if(character >= 97 && character <= 122)
		printf("\n\n\nThe entered character is: A LOWERCASE LETTER!\n");
	else if(!(character >= 48 && character <= 57) && !(character >= 65 && character <= 90) && !(character >= 97 && character <= 122))
		printf("\n\n\nThe entered character is: A SPECIAL SYMBOL!\n");
	else
		printf("\n\nThe entered character is: NOT a letter, digit, or a special symbol.\n");
	
	getch();
	return 0;
}
