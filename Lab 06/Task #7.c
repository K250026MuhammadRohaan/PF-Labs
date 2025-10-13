#include <stdio.h>
#include <conio.h>

int main()
{
    int num, originalNum, reversedNum = 0, remainder;

	printf("\n\t\t\t========================  LIBRARY CODE SYSTEM  ========================\n\n");

    printf("Enter an integer:  ");
    scanf("%d", &num);

    originalNum = num;

    while (num != 0)
	{
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder; 
        num /= 10;
    }

    if (originalNum == reversedNum)
        printf("\nThe number %d IS a Palindrome\n", originalNum);
    else
        printf("\nThe number %d is NOT a Palindrome\n", originalNum);

	getch();
    return 0;
}

