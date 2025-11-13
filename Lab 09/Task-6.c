#include <stdio.h>
#include <conio.h>
#include <string.h>

char* formatName(char *first, char *last)
{
    static char fullName[100];

    strcpy(fullName, first);
    strcat(fullName, " ");
    strcat(fullName, last);

    return fullName;
}

int main()
{
    char firstName[50], lastName[50];

    printf("\nEnter your First Name:  ");
    scanf(" %[^\n]", firstName);

    printf("\nEnter your Last Name:  ");
    scanf(" %[^\n]", lastName);

    char* fullName = formatName(firstName, lastName);
    
    printf("\n\nYour Formatted Full Name is:  %s\n", fullName);

    getch();
    return 0;
}
