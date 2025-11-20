#include <stdio.h>
#include <string.h>

#define MAX_LEVELS 10
#define MAX_LEN 200


void loadLevels(char arr[][MAX_LEN], int *count);
void saveLevels(char arr[][MAX_LEN], int count);
int countWords(char str[]);
void addLevel(char arr[][MAX_LEN], int *count);
void deleteLevel(char arr[][MAX_LEN], int *count);
void updateLevel(char arr[][MAX_LEN], int count);
void searchLevel(char arr[][MAX_LEN], int count);


int main() {
    char levels[MAX_LEVELS][MAX_LEN];
    int count = 0;

    loadLevels(levels, &count);

    int choice;

    while (1) {
        printf("\n--- LEVEL TRACKER MENU ---\n");
        printf("1. Add Level\n");
        printf("2. Delete Level\n");
        printf("3. Update Level\n");
        printf("4. Search Level\n");
        printf("Enter -1 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == -1)
            break;

        switch (choice) {
            case 1: addLevel(levels, &count); break;
            case 2: deleteLevel(levels, &count); break;
            case 3: updateLevel(levels, count); break;
            case 4: searchLevel(levels, count); break;
            default: printf("Invalid choice!\n");
        }
    }

    saveLevels(levels, count);
    printf("All changes saved to levels.txt\n");

    return 0;
}


void loadLevels(char arr[][MAX_LEN], int *count) {
    FILE *fp = fopen("levels.txt", "r");
    if (!fp) return;

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(arr[*count], line);
        (*count)++;
        if (*count == MAX_LEVELS) break;
    }
    fclose(fp);
}


void saveLevels(char arr[][MAX_LEN], int count) {
    FILE *fp = fopen("levels.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", arr[i]);
    }
    fclose(fp);
}


int countWords(char str[]) {
    int words = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\0')) {
            words++;
        }
    }
    return words;
}


void addLevel(char arr[][MAX_LEN], int *count) {
    if (*count == MAX_LEVELS) {
        printf("Level list full!\n");
        return;
    }

    char temp[MAX_LEN];
    printf("Enter new level description (max 7 words): ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    int w = countWords(temp);

    if (w == 0 || w > 7) {
        printf("Invalid! Description must have NO MORE than 7 words.\n");
        return;
    }

    strcpy(arr[*count], temp);
    (*count)++;

    printf("Level added!\n");
}


void deleteLevel(char arr[][MAX_LEN], int *count) {
    if (*count == 0) {
        printf("No levels to delete.\n");
        return;
    }

    char target[MAX_LEN];
    printf("Enter level to delete: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    for (int i = 0; i < *count; i++) {
        if (strcmp(arr[i], target) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(arr[j], arr[j + 1]);
            }
            (*count)--;
            printf("Level deleted!\n");
            return;
        }
    }

    printf("Level not found.\n");
}


void updateLevel(char arr[][MAX_LEN], int count) {
    if (count == 0) {
        printf("No levels to update.\n");
        return;
    }

    char target[MAX_LEN];
    printf("Enter existing level to update: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(arr[i], target) == 0) {

            char newLevel[MAX_LEN];
            printf("Enter new description (max 7 words): ");
            fgets(newLevel, sizeof(newLevel), stdin);
            newLevel[strcspn(newLevel, "\n")] = '\0';

            int w = countWords(newLevel);
            if (w == 0 || w > 7) {
                printf("Invalid! Must be NO MORE than 7 words.\n");
                return;
            }

            strcpy(arr[i], newLevel);

            printf("Level updated!\n");
            return;
        }
    }

    printf("Level not found.\n");
}


void searchLevel(char arr[][MAX_LEN], int count) {
    if (count == 0) {
        printf("No levels to search.\n");
        return;
    }

    char target[MAX_LEN];
    printf("Enter level to search: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(arr[i], target) == 0) {
            printf("FOUND: %s\n", arr[i]);
            return;
        }
    }

    printf("Not found.\n");
}