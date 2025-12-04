#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int n = 0, i;
    int *ratings = NULL;
    int total, maxIndex, updateIndex;
    float average;

    while (1) {
        printf("\n1. Enter number of categories and allocate memory");
        printf("\n2. Enter rating count for each category");
        printf("\n3. Show total, average, and highest rating category");
        printf("\n4. Update rating of any category");
        printf("\n5. Display all ratings");
        printf("\n6. Free memory and exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of movie categories: ");
                scanf("%d", &n);
                ratings = (int*)malloc(n * sizeof(int));
                break;

            case 2:
                if (ratings == NULL) break;
                for (i = 0; i < n; i++) {
                    printf("Enter rating count for category %d: ", i);
                    scanf("%d", &ratings[i]);
                }
                break;

            case 3:
                if (ratings == NULL) break;
                total = 0;
                maxIndex = 0;
                for (i = 0; i < n; i++) {
                    total += ratings[i];
                    if (ratings[i] > ratings[maxIndex]) maxIndex = i;
                }
                average = (float)total / n;
                printf("Total ratings: %d\n", total);
                printf("Average ratings: %.2f\n", average);
                printf("Category with highest rating: %d\n", maxIndex);
                break;

            case 4:
                if (ratings == NULL) break;
                printf("Enter category index to update: ");
                scanf("%d", &updateIndex);
                if (updateIndex >= 0 && updateIndex < n) {
                    printf("Enter new rating count: ");
                    scanf("%d", &ratings[updateIndex]);
                }
                break;

            case 5:
                if (ratings == NULL) break;
                for (i = 0; i < n; i++) {
                    printf("Category %d: %d\n", i, ratings[i]);
                }
                break;

            case 6:
                if (ratings != NULL) free(ratings);
                return 0;
        }
    }
}