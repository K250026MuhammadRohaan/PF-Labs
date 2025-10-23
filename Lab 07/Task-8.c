#include <stdio.h>
#include <conio.h>

#define LENGTH 48

int main()
{
    char str1[LENGTH], str2[LENGTH];

    printf("\n\t\t\t====================   TWO STRINGS COMPARER   ====================\n\n");
 
    printf("\nEnter your first string:  ");
    scanf(" %[^\n]", str1);
    getchar();
    printf("\nEnter your second string:  ");
    scanf(" %[^\n]", str2);

    for (int i=0 ; i<LENGTH ; i++)
    {
        if (str1[i] == '\0' && str2[i] == '\0')
        {
            break;
        }

        if (str1[i] == '\0' || str2[i] == '\0')
        {
            printf("\n\n\nEnd of String REACHED at index: %d !\n", i);
            return -2;
        }
        
        if (str1[i] != str2[i])
        {
            printf("\n\n\nCharacter MISMATCH DETECTED at Common Index: %d\n", i);
            return -3;
        }
    }

    printf("\n\n\nBoth the Strings are the SAME!\n");
   	
    getch();
    return 0;
}
