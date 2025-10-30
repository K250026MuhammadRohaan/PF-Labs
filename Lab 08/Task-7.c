#include <stdio.h>
#include <conio.h>

#define SECTIONS 2
#define SHELVES 3
#define ITEMS 4

int main ()
{
    printf("\n\t\t\t====================   INVENTORY MANAGEMENT SYSTEM - 3D ARRAYS   ====================\n\n");
    int inventory[SECTIONS][SHELVES][ITEMS];


    // INPUT CODE
    printf("\n---->  ENTER VALUES FOR ITEMS IN INVENTORY:-");

    for (int i=0 ; i<SECTIONS ; i++)
    {
        printf("\n\n\n\n\t\t\t\t\t\t-->  Section: %d  <--\n", i+1);

        for (int j=0 ; j<SHELVES ; j++)
        {
            printf("\n> Shelf no. %d\n", j+1);

            for (int k=0 ; k< ITEMS ; k++)
            {
                printf("\t- Item #%d:  ", k+1);
                scanf("%d", &inventory[i][j][k]);
            }
        }
    }


    // TOTAL ITEMS IN EACH SECTION
    printf("\n\n\n---->  TOTAL ITEMS IN EACH SECTION:-\n");
    int totalItems;

    for (int i=0 ; i<SECTIONS ; i++)
    {
        totalItems = 0;

        for (int j=0 ; j<SHELVES ; j++)
        {
            for (int k=0 ; k< ITEMS ; k++)
            {
                totalItems += inventory[i][j][k];
            }
        }

        printf("\n  > Total Items in Section no. %d:\t%d", i+1, totalItems);
    }


    printf("\n\n\n\n---->  SHELF WITH HIGHEST TOTAL QUANTITY:-\n");
    
    int maxItemTotal=0, maxItemSection=0, maxItemShelf=0, shelfTotal;
    
    for (int i=0 ; i<SECTIONS ; i++)
    {
        for (int j=0 ; j<SHELVES ; j++)
        {
            shelfTotal = 0;

            for (int k=0 ; k<ITEMS ; k++)
            {
                shelfTotal += inventory[i][j][k];
            }

            if (shelfTotal > maxItemTotal)
            {
                maxItemTotal = shelfTotal;
                maxItemSection = i;
                maxItemShelf = j;
            }
        }
    }
    
    printf("\n  > HIGHEST:-  Section-%d, Shelf-%d, with %d Items TOTAL\n\n", maxItemSection + 1, maxItemShelf + 1, maxItemTotal);


    getch();
    return 0;
}