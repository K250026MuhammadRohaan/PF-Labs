#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int category(char c) {
    if (isupper(c)) return 1;
    if (islower(c)) return 2;
    if (isdigit(c)) return 3;
    return 4;
}

float similarity(char *pattern, char *attempt) {
    int len = strlen(pattern) < strlen(attempt) ? strlen(pattern) : strlen(attempt);
    int match = 0;
    for (int i = 0; i < len; i++) {
        if (category(pattern[i]) == category(attempt[i])) match++;
    }
    return ((float)match / strlen(pattern)) * 100;
}

int main() {
    int choice;
    int n = 0, i;
    char **passwords = NULL;
    char *pattern = NULL;
    float score, maxScore;
    int maxIndex;
    int participantsSet = 0, patternSet = 0, passwordsSet = 0;

    while (1) {
        printf("\n1. Enter number of participants");
        printf("\n2. Enter password pattern");
        printf("\n3. Input participant passwords and calculate similarity");
        printf("\n4. Display passwords and similarity, highest similarity");
        printf("\n5. Free memory and exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter number of participants: ");
                scanf("%d", &n);
                getchar();
                passwords = (char**)malloc(n * sizeof(char*));
                participantsSet = 1;
                break;

            case 2:
                pattern = (char*)malloc(100);
                printf("Enter password pattern: ");
                fgets(pattern, 100, stdin);
                pattern[strcspn(pattern, "\n")] = '\0';
                patternSet = 1;
                break;

            case 3:
                if (!participantsSet) {
                    printf("Please enter the number of participants first (Option 1).\n");
                    break;
                }
                if (!patternSet) {
                    printf("Please enter the password pattern first (Option 2).\n");
                    break;
                }
                for (i = 0; i < n; i++) {
                    char temp[100];
                    printf("Enter password attempt %d: ", i);
                    fgets(temp, sizeof(temp), stdin);
                    temp[strcspn(temp, "\n")] = '\0';
                    passwords[i] = (char*)malloc(strlen(temp) + 1);
                    strcpy(passwords[i], temp);
                }
                passwordsSet = 1;
                break;

            case 4:
                if (!passwordsSet) {
                    printf("Please input participant passwords first (Option 3).\n");
                    break;
                }
                maxScore = -1;
                maxIndex = -1;
                for (i = 0; i < n; i++) {
                    score = similarity(pattern, passwords[i]);
                    printf("%s: %.2f%% similarity\n", passwords[i], score);
                    if (score > maxScore) {
                        maxScore = score;
                        maxIndex = i;
                    }
                }
                if (maxIndex != -1) {
                    printf("Highest similarity password: %s (%.2f%%)\n", passwords[maxIndex], maxScore);
                }
                break;

            case 5:
                if (pattern != NULL) free(pattern);
                if (passwords != NULL) {
                    for (i = 0; i < n; i++) free(passwords[i]);
                    free(passwords);
                }
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}