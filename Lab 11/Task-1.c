#include <stdio.h>
#include <conio.h>

#define MAX_GIFTS 100

struct Gift
{
    char name[50];
    char type[50];
    float price;
    int quantity;
};

int main()
{
    struct Gift gifts[MAX_GIFTS];
    int num;

    printf("\nEnter number of gifts:  ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\n--------- Gift %d ---------\n", i + 1);

        printf("Enter gift name: ");
        scanf("%s", gifts[i].name);

        printf("Enter gift type: ");
        scanf("%s", gifts[i].type);

        printf("Enter price: ");
        scanf("%f", &gifts[i].price);

        printf("Enter quantity: ");
        scanf("%d", &gifts[i].quantity);
    }


    float priceLimit;
    printf("\nEnter a price to filter gifts ABOVE this value:  ");
    scanf("%f", &priceLimit);

    printf("\nGifts with price above %.2f:\n", priceLimit);
    int foundPrice = 0;

    for (int i = 0; i < num; i++)
    {
        if (gifts[i].price > priceLimit)
        {
            printf("\nName: %s", gifts[i].name);
            printf("\nType: %s", gifts[i].type);
            printf("\nPrice: %.2f", gifts[i].price);
            printf("\nQuantity: %d\n", gifts[i].quantity);
        
            foundPrice = 1;
        }
    }

    if (!foundPrice) printf("No gifts found above this price.\n");


    int qtyLimit;
    printf("\nEnter a quantity to filter gifts ABOVE this amount: ");
    scanf("%d", &qtyLimit);

    printf("\nGifts with quantity above %d:\n", qtyLimit);
    int foundQty = 0;

    for (int i = 0; i < num; i++)
    {
        if (gifts[i].quantity > qtyLimit)
        {
            printf("\nName: %s", gifts[i].name);
            printf("\nType: %s", gifts[i].type);
            printf("\nPrice: %.2f", gifts[i].price);
            printf("\nQuantity: %d\n", gifts[i].quantity);
            
            foundQty = 1;
        }
    }

    if (!foundQty) printf("No gifts found above this quantity.\num");

    getch();
    return 0;
}
