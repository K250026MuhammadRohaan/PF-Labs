#include <stdio.h>
#include <conio.h>

void PassByValue(int num, int change)
{
    num = change;
}

void PassByReference(int *num, int change)
{
    *num = change;
}

int main ()
{
    int num, change;

    printf("\nEnter a number:  ");
    scanf("%d", &num);

    printf("\nEnter a number to change the previous entered number into:  ");
    scanf("%d", &change);

    printf("\n\nBefore updateValue:  %d", num);
    PassByValue(num, change);
    printf("\nAfter updateValue:  %d  (no change)", num);

    printf("\n\nBefore updateReference:  %d", num);
    PassByReference(&num, change);
    printf("\nAfter updateReference:  %d  (updated successfully)\n", num);

    getch();
    return 0;
}