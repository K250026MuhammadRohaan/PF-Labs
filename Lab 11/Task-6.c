#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item
{
    char name[50];
    char category[50];
    int quantity;
};

void filterByCategory(struct Item *ptr, int n, char *target)
{
    printf("\n> Items in category '%s':\n", target);
    int found = 0;

    for (int i=0 ; i<n ; i++)
    {
        struct Item *current = ptr + i;

        if (strcmp(current->category, target) == 0)
        {
            printf("\nName: %s\nCategory: %s\nQuantity: %d\n", current->name, current->category, current->quantity);
            found = 1;
        }
    }

    if (!found) printf("No items found in this category.\n");
}

void filterByQuantity(struct Item *ptr, int n, int minQty)
{
    printf("\n> Items with quantity >= %d:\n", minQty);
    int found = 0;

    for (int i=0 ; i<n ; i++)
    {
        struct Item *current = ptr + i;

        if (current->quantity >= minQty)
        {
            printf("\nName: %s\nCategory: %s\nQuantity: %d\n", current->name, current->category, current->quantity);
            found = 1;
        }
    }

    if (!found) printf("No items meet this minimum quantity.\n");
}

int main()
{
    struct Item inventory[MAX_ITEMS];
    int n;

    printf("\nEnter number of items: ");
    scanf("%d", &n);

    for (int i=0 ; i<n ; i++)
    {
        printf("\n\n------  Item %d  ------\n", i+1);

        printf("Enter name: ");
        scanf("%s", inventory[i].name);

        printf("Enter category: ");
        scanf("%s", inventory[i].category);

        printf("Enter quantity: ");
        scanf("%d", &inventory[i].quantity);
    }
    printf("\n");

    struct Item *ptr = inventory;

    char targetCategory[50];
    printf("\n--> Enter category to filter: ");
    scanf("%s", targetCategory);
    filterByCategory(ptr, n, targetCategory);

    int minQty;
    printf("\n\n--> Enter minimum quantity: ");
    scanf("%d", &minQty);
    filterByQuantity(ptr, n, minQty);

    getch();
    return 0;
}
