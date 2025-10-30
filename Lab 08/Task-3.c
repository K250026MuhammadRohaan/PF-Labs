#include <stdio.h>
#include <conio.h>

#define WORD 3
#define LETTER 10

int main ()
{
    printf("\n\t\t\t====================   VOWEL COUNTER IN 2D-ARRAY   ====================\n\n");

    int vowelCount=0;
    char str[WORD][LETTER];
    
    for (int i=0 ; i<WORD ; i++)
    {
            printf("\nEnter your Word no. %d (MAX %d LETTER):  ", i+1, LETTER);
            scanf(" %[^\n]", str[i]);
    }

    for (int i=0 ; i<WORD ; i++)
    {
        for (int j=0 ; j<LETTER ; j++)
        {
            if (str[i][j] == 'a' || str[i][j] == 'e' || str[i][j] == 'i' || str[i][j] == 'o' || str[i][j] == 'u' || str[i][j] == 'A' || str[i][j] == 'E' || str[i][j] == 'I' || str[i][j] == 'O' || str[i][j] == 'U')
            {
                vowelCount++;
            }
        }
    }

    printf("\n\n\n->  The Total Number of VOWELS present in your sentence (%d Words) are:  %d Vowels\n", WORD, vowelCount);

    getch();
    return 0;
}