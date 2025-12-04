#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int choice;
    int n = 0, i;
    char **feedback = NULL;
    int totalChars;
    int longestIndex;

    while (1) {
        printf("\n1. Enter number of feedback entries");
        printf("\n2. Input all feedback messages");
        printf("\n3. Count total characters");
        printf("\n4. Find longest feedback");
        printf("\n5. Display all feedback and longest");
        printf("\n6. Free memory and exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                printf("Enter number of feedback entries: ");
                scanf("%d", &n);
                getchar();
                feedback = (char**)realloc(feedback, n * sizeof(char*));
                break;

            case 2:
                if (feedback == NULL) break;
                for (i = 0; i < n; i++) {
                    char temp[500];
                    printf("Enter feedback %d: ", i);
                    fgets(temp, sizeof(temp), stdin);
                    temp[strcspn(temp, "\n")] = '\0';
                    feedback[i] = (char*)malloc(strlen(temp) + 1);
                    strcpy(feedback[i], temp);
                }
                break;

            case 3:
                if (feedback == NULL) break;
                totalChars = 0;
                for (i = 0; i < n; i++) {
                    totalChars += strlen(feedback[i]);
                }
                printf("Total characters: %d\n", totalChars);
                break;

            case 4:
                if (feedback == NULL) break;
                longestIndex = 0;
                for (i = 1; i < n; i++) {
                    if (strlen(feedback[i]) > strlen(feedback[longestIndex]))
                        longestIndex = i;
                }
                printf("Longest feedback index: %d\n", longestIndex);
                break;

            case 5:
                if (feedback == NULL) break;
                for (i = 0; i < n; i++) {
                    printf("%d: %s\n", i, feedback[i]);
                }
                longestIndex = 0;
                for (i = 1; i < n; i++) {
                    if (strlen(feedback[i]) > strlen(feedback[longestIndex]))
                        longestIndex = i;
                }
                printf("Longest feedback: %s\n", feedback[longestIndex]);
                break;

            case 6:
                if (feedback != NULL) {
                    for (i = 0; i < n; i++) {
                        free(feedback[i]);
                    }
                    free(feedback);
                }
                return 0;
        }
    }
}