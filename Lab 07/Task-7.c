#include <stdio.h>
#include <conio.h>

#define STRING_LENGTH 48

int main()
{
    printf("\n\t\t\t====================   VOWEL & CONSONANT COUNTER   ====================\n\n");

    int vowelCount=0, consonantCount=0;
    char str[STRING_LENGTH];
    
    printf("\nEnter your string/code:  ");
    scanf(" %[^\n]", str);
    getchar();

    for (int i=0 ; i<STRING_LENGTH ; i++)
    {
        switch (str[i])
        {
            case 'A': str[i] = 'a'; break;
            case 'B': str[i] = 'b'; break;
            case 'C': str[i] = 'c'; break;
            case 'D': str[i] = 'd'; break;
            case 'E': str[i] = 'e'; break;
            case 'F': str[i] = 'f'; break;
            case 'G': str[i] = 'g'; break;
            case 'H': str[i] = 'h'; break;
            case 'I': str[i] = 'i'; break;
            case 'J': str[i] = 'j'; break;
            case 'K': str[i] = 'k'; break;
            case 'L': str[i] = 'l'; break;
            case 'M': str[i] = 'm'; break;
            case 'N': str[i] = 'n'; break;
            case 'O': str[i] = 'o'; break;
            case 'P': str[i] = 'p'; break;
            case 'Q': str[i] = 'q'; break;
            case 'R': str[i] = 'r'; break;
            case 'S': str[i] = 's'; break;
            case 'T': str[i] = 't'; break;
            case 'U': str[i] = 'u'; break;
            case 'V': str[i] = 'v'; break;
            case 'W': str[i] = 'w'; break;
            case 'X': str[i] = 'x'; break;
            case 'Y': str[i] = 'y'; break;
            case 'Z': str[i] = 'z'; break;
        }
    }

    printf("\n\nThe sentence in LOWERCASE is:  %s", str);

    for (int i=0 ; i<STRING_LENGTH ; i++)
    {
        if (str[i] == '\0') break;

        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowelCount++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            consonantCount++;
        }
    }

    printf("\n\nThe sentence: \"%s\" has:- \n  -%d VOWELS\n  -%d CONSONANTS\n", str, vowelCount, consonantCount);

    getch();
    return 0;
}
