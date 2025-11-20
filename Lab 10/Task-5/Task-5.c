#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_LEN 200


int countWords(char *str) {
    int count = 0, inWord = 0;

    while (*str != '\0') {
        if (*str != ' ' && *str != '\t' && *str != '\n') {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
        str++;
    }
    return count;
}


void addTag(char tags[][MAX_LEN], int *count) {
    if (*count >= MAX) {
        printf("\nList is full!\n\n");
        return;
    }

    char temp[MAX_LEN];

    printf("Enter new tag (5 to 7 words): ");
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    if (countWords(temp) < 5 || countWords(temp) > 7) {
        printf("\nInvalid tag! Must be 5 to 7 words.\n\n");
        return;
    }

    strcpy(*(tags + *count), temp); 
    (*count)++;

    printf("\nTag added successfully!\n\n");
}


void deleteTag(char tags[][MAX_LEN], int *count) {
    if (*count == 0) {
        printf("\nNo tags to delete.\n\n");
        return;
    }

    int num;
    printf("Enter tag number to delete: ");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > *count) {
        printf("\nInvalid number!\n\n");
        return;
    }

    for (int i = num - 1; i < *count - 1; i++) {
        strcpy(*(tags + i), *(tags + i + 1));   
    }

    (*count)--;

    printf("\nTag deleted!\n\n");
}


void updateTag(char tags[][MAX_LEN], int count) {
    if (count == 0) {
        printf("\nNo tags to update.\n\n");
        return;
    }

    int num;
    char temp[MAX_LEN];

    printf("Enter tag number to update: ");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > count) {
        printf("\nInvalid number!\n\n");
        return;
    }

    printf("Enter new tag (5 to 7 words): ");
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    if (countWords(temp) < 5 || countWords(temp) > 7) {
        printf("\nInvalid tag! Must be 5 to 7 words.\n\n");
        return;
    }

    strcpy(*(tags + (num - 1)), temp);
    printf("\nUpdated!\n\n");
}


void searchTags(char tags[][MAX_LEN], int count) {
    char key[MAX_LEN];
    printf("Enter text to search: ");
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';

    int found = 0;

    printf("\n--- SEARCH RESULTS ---\n");

    for (int i = 0; i < count; i++) {
        if (strstr(*(tags + i), key) != NULL) {
            printf("%d. %s\n", i + 1, *(tags + i));
            found = 1;
        }
    }

    if (!found)
        printf("No matching tags found!\n");

    printf("-----------------------\n\n");
}


void displayTags(char tags[][MAX_LEN], int count) {
    printf("\n--- CURRENT TAGS ---\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, *(tags + i));
    printf("---------------------\n\n");
}


void sortTags(char tags[][MAX_LEN], int count) {
    char temp[MAX_LEN];

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(*(tags + i), *(tags + j)) > 0) {
                strcpy(temp, *(tags + i));
                strcpy(*(tags + i), *(tags + j));
                strcpy(*(tags + j), temp);
            }
        }
    }
}


int main() {
    char tags[MAX][MAX_LEN];
    int count = 0;

    FILE *file;

    
    file = fopen("tags.txt", "r");
    if (file != NULL) {
        while (fgets(tags[count], MAX_LEN, file) != NULL) {
            tags[count][strcspn(tags[count], "\n")] = '\0';
            count++;
        }
        fclose(file);
    }

    int choice;

    while (1) {
        printf("\n--- CAMERA TAG MENU ---\n");
        printf("1. Add Tag\n");
        printf("2. Delete Tag\n");
        printf("3. Update Tag\n");
        printf("4. Search Tags\n");
        printf("5. Display Tags\n");
        printf("Enter -1 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == -1)
            break;

        switch (choice) {
            case 1: addTag(tags, &count); break;
            case 2: deleteTag(tags, &count); break;
            case 3: updateTag(tags, count); break;
            case 4: searchTags(tags, count); break;
            case 5: displayTags(tags, count); break;
            default: printf("\nInvalid choice!\n\n");
        }
    }


    sortTags(tags, count);
    file = fopen("tags.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(file, "%s\n", tags[i]);
    fclose(file);

    printf("\nAll changes saved. Goodbye!\n");

    return 0;
}