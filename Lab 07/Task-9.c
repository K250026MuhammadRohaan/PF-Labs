#include <stdio.h>
#include <conio.h>

#define STRING_LENGTH 96

int main()
{
    printf("\n\t\t\t====================   LONGEST WORD IN STRING FINDER   ====================\n\n");

    int maxWordLength=0, index=0, wordLength=0, lastIndex=0, firstIndex=0;
    int longest_FirstIndex=0, longest_LastIndex=0;
    char str[STRING_LENGTH], longestWord[STRING_LENGTH];
    
    printf("\nEnter your string:\t");
    scanf(" %[^\n]", str);
    getchar();

    while( str[firstIndex] != '\0' )
    {
        wordLength = 0;

        while( str[index] != ' ' && str[index] != '\0' )
        {
            wordLength++;
            index++;
        }

        lastIndex = index;

        if (wordLength > maxWordLength)
        {
            maxWordLength = wordLength;
            longest_FirstIndex = firstIndex;
            longest_LastIndex = lastIndex;
        }

        firstIndex = index + 1;
        index = firstIndex;
    }

    int j=0;
    for (int i=longest_FirstIndex ; i<longest_LastIndex ; i++)
    {
        longestWord[j] = str[i];
        j++;
    }
    longestWord[j] = '\0';

    //printf("\n\n%d", wordLength);

    printf("\n\nThe LONGEST WORD in your sentence is: \"%s\", with a length of:  %d letters!\n", longestWord, maxWordLength);

    getch();
    return 0;
}
