#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, choice, i;
    int *stock = NULL;
    int total, minIndex, updateIndex;
    float average;

    while (1) {
        printf("\n1. Enter number of categories and allocate memory");
        printf("\n2. Enter stock for each category");
        printf("\n3. Show total, average, and lowest stock category");
        printf("\n4. Update stock of any category");
        printf("\n5. Display all stock values");
        printf("\n6. Free memory and exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of categories: ");
                scanf("%d", &n);
                stock = (int*)malloc(n * sizeof(int));
                break;

            case 2:
                if (stock == NULL) break;
                for (i = 0; i < n; i++) {
                    printf("Enter stock for category %d: ", i);
                    scanf("%d", &stock[i]);
                }
                break;

            case 3:
                if (stock == NULL) break;
                total = 0;
                minIndex = 0;
                for (i = 0; i < n; i++) {
                    total += stock[i];
                    if (stock[i] < stock[minIndex]) minIndex = i;
                }
                average = (float)total / n;
                printf("Total stock: %d\n", total);
                printf("Average stock: %.2f\n", average);
                printf("Lowest stock category index: %d\n", minIndex);
                break;

            case 4:
                if (stock == NULL) break;
                printf("Enter category index to update: ");
                scanf("%d", &updateIndex);
                if (updateIndex >= 0 && updateIndex < n) {
                    printf("Enter new stock value: ");
                    scanf("%d", &stock[updateIndex]);
                }
                break;

            case 5:
                if (stock == NULL) break;
                for (i = 0; i < n; i++) {
                    printf("Category %d: %d\n", i, stock[i]);
                }
                break;

            case 6:
                free(stock);
                return 0;
        }
    }
}