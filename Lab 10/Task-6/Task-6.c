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


int countWordInAll(char notes[][MAX_LEN], int total, char *word) {
    int totalCount = 0;

    for (int i = 0; i < total; i++) {
        char *p = *(notes + i);

        while ((p = strstr(p, word)) != NULL) {
            totalCount++;
            p++;   
        }
    }
    return totalCount;
}


void addNote(char notes[][MAX_LEN], int *total) {
    if (*total >= MAX) {
        printf("\nList full!\n\n");
        return;
    }

    char temp[MAX_LEN];
    printf("Enter new note title: ");
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    strcpy(*(notes + *total), temp);
    (*total)++;

    printf("\nNote added!\n\n");
}


void deleteNote(char notes[][MAX_LEN], int *total) {
    if (*total == 0) {
        printf("\nNo notes to delete.\n\n");
        return;
    }

    int num;
    printf("Enter note number to delete: ");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > *total) {
        printf("\nInvalid number!\n\n");
        return;
    }

    for (int i = num - 1; i < *total - 1; i++) {
        strcpy(*(notes + i), *(notes + i + 1));
    }

    (*total)--;
    printf("\nNote removed!\n\n");
}


void editNote(char notes[][MAX_LEN], int total) {
    if (total == 0) {
        printf("\nNo notes to edit.\n\n");
        return;
    }

    int num;
    char temp[MAX_LEN];

    printf("Enter note number to edit: ");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > total) {
        printf("\nInvalid number!\n\n");
        return;
    }

    printf("Enter updated text: ");
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    strcpy(*(notes + (num - 1)), temp);
    printf("\nUpdated!\n\n");
}


void searchNotes(char notes[][MAX_LEN], int total) {
    char key[MAX_LEN];
    printf("Enter search text: ");
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';

    int found = 0;

    printf("\n--- SEARCH RESULTS ---\n");

    for (int i = 0; i < total; i++) {
        if (strstr(*(notes + i), key) != NULL) {
            printf("%d. %s\n", i + 1, *(notes + i));
            found = 1;
        }
    }

    if (!found)
        printf("No matches found!\n");

    printf("-----------------------\n\n");
}


void displayNotes(char notes[][MAX_LEN], int total) {
    printf("\n--- CURRENT NOTES ---\n");
    for (int i = 0; i < total; i++)
        printf("%d. %s\n", i + 1, *(notes + i));
    printf("----------------------\n\n");
}


int main() {
    char notes[MAX][MAX_LEN];
    int total = 0;
    FILE *file;

    
    file = fopen("episodes.txt", "r");
    if (file != NULL) {
        while (fgets(notes[total], MAX_LEN, file) != NULL) {
            notes[total][strcspn(notes[total], "\n")] = '\0';
            total++;
        }
        fclose(file);
    }

    int choice;

    while (1) {
        printf("\n--- PODCAST NOTES MENU ---\n");
        printf("1. Add Note\n");
        printf("2. Delete Note\n");
        printf("3. Edit Note\n");
        printf("4. Search Notes\n");
        printf("5. Display All Notes\n");
        printf("6. Count a Word Across All Notes\n");
        printf("Enter -1 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == -1)
            break;

        switch (choice) {
            case 1: addNote(notes, &total); break;
            case 2: deleteNote(notes, &total); break;
            case 3: editNote(notes, total); break;
            case 4: searchNotes(notes, total); break;
            case 5: displayNotes(notes, total); break;
            case 6: {
                char word[MAX_LEN];
                printf("Enter word to count across all notes: ");
                fgets(word, MAX_LEN, stdin);
                word[strcspn(word, "\n")] = '\0';

                int result = countWordInAll(notes, total, word);

                printf("\n--- WORD COUNT ---\n");
                printf("The word '%s' appears %d times.\n", word, result);
                printf("-------------------\n\n");
                break;
            }
            default:
                printf("\nInvalid choice!\n\n");
        }
    }


    file = fopen("episodes.txt", "w");
    for (int i = 0; i < total; i++)
        fprintf(file, "%s\n", notes[i]);
    fclose(file);

    printf("\nAll notes saved. Goodbye!\n");

    return 0;
}