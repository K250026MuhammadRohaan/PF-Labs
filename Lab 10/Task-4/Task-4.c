#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_LEN 200


int countWords(char str[]) {
    int count = 0, inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}


void sortAffirmations(char arr[][MAX_LEN], int n) {
    char temp[MAX_LEN];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}


void display(char arr[][MAX_LEN], int count) {
    printf("\n--- CURRENT AFFIRMATIONS ---\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, arr[i]);
    printf("----------------------------\n\n");
}


int main() {
    char affirmations[MAX][MAX_LEN];
    int count = 0;
    FILE *file;

    file = fopen("affirm.txt", "r");
    if (file != NULL) {
        while (fgets(affirmations[count], MAX_LEN, file) != NULL) {
            affirmations[count][strcspn(affirmations[count], "\n")] = '\0';
            count++;
        }
        fclose(file);
    }

    int choice;
    char text[MAX_LEN];

    while (1) {
        printf("\n--- AFFIRMATION MENU ---\n");
        printf("1. Add New Affirmation\n");
        printf("2. Update Affirmation\n");
        printf("3. Delete Affirmation\n");
        printf("4. Search\n");
        printf("Enter -1 to Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == -1)
            break;

        switch (choice) {

        case 1: // Add
            if (count >= MAX) {
                printf("\nList Full!\n\n");
                break;
            }

            printf("Enter new affirmation (max 7 words): ");
            fgets(text, MAX_LEN, stdin);
            text[strcspn(text, "\n")] = '\0';

            if (countWords(text) > 7) {
                printf("\nInvalid! Too many words.\n\n");
                break;
            }

            strcpy(affirmations[count], text);
            count++;

            printf("\nAdded successfully!\n\n");
            break;

        case 2: // Update
            display(affirmations, count);

            printf("Enter affirmation number to update: ");
            int num;
            scanf("%d", &num);
            getchar();

            if (num < 1 || num > count) {
                printf("\nInvalid number!\n\n");
                break;
            }

            printf("Enter new text (max 7 words): ");
            fgets(text, MAX_LEN, stdin);
            text[strcspn(text, "\n")] = '\0';

            if (countWords(text) > 7) {
                printf("\nInvalid! Too many words.\n\n");
                break;
            }

            strcpy(affirmations[num - 1], text);
            printf("\nUpdated!\n\n");
            break;

        case 3: // Delete
            display(affirmations, count);

            printf("Enter number to delete: ");
            scanf("%d", &num);
            getchar();

            if (num < 1 || num > count) {
                printf("\nInvalid number!\n\n");
                break;
            }

            for (int i = num - 1; i < count - 1; i++)
                strcpy(affirmations[i], affirmations[i + 1]);

            count--;

            printf("\nDeleted!\n\n");
            break;

        case 4: // Search
            printf("Enter text to search: ");
            fgets(text, MAX_LEN, stdin);
            text[strcspn(text, "\n")] = '\0';

            int found = 0;

            printf("\n--- SEARCH RESULTS ---\n");

            for (int i = 0; i < count; i++) {
                if (strstr(affirmations[i], text) != NULL) {
                    printf("%d. %s\n", i + 1, affirmations[i]);
                    found = 1;
                }
            }

            if (!found)
                printf("NO MATCH FOUND!\n");

            printf("-----------------------\n\n");
            break;

        default:
            printf("\nInvalid choice!\n\n");
        }
    }


    file = fopen("affirm.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(file, "%s\n", affirmations[i]);
    fclose(file);

    printf("\nAll changes saved. Goodbye!\n");

    return 0;
}
