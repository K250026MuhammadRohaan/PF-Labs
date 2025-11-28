#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

void reverseWord(char word[], int index)
{
    if (index < 0) return;

    printf("%c", word[index]);
    reverseWord(word, index - 1);
}

int isPalindrome(char word[], int left, int right)
{
    if (left >= right) return 1;

    if (word[left] != word[right]) return 0;

    return isPalindrome(word, left + 1, right - 1);
}

int main()
{
    int n;
    char words[MAX_WORDS][MAX_LENGTH];

    printf("\nEnter number of words: ");
    scanf("%d", &n);

    for (int i=0 ; i<n ; i++)
    {
        printf("Enter word %d: ", i+1);
        scanf("%s", words[i]);
    }

    printf("\n\n==========  WORD ANALYSIS  ==========\n");

    for (int i=0 ; i<n ; i++)
    {
        char *w = words[i];
        int len = strlen(w);

        printf("\nWord %d: %s\n", i+1, w);

        printf("Reversed: ");
        reverseWord(w, len-1);
        printf("\n");

        if (isPalindrome(w, 0, len - 1)) printf("Palindrome: YES\n");
        else printf("Palindrome: NO\n");
    }

    getch();
    return 0;
}
