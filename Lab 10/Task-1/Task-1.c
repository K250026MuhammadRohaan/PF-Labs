#include <stdio.h>
#include <string.h>

#define MAX_SONGS 10
#define MAX_TITLE_LEN 200


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int countWords(char *str) {
    int count = 0, inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && inWord == 0) {
            inWord = 1;
            count++;
        }
        else if (str[i] == ' ') {
            inWord = 0;
        }
    }
    return count;
}


void loadPlaylist(char playlist[][MAX_TITLE_LEN], int *count) {
    FILE *fp = fopen("playlist.txt", "r");
    if (!fp) {
        *count = 0;
        return;
    }

    *count = 0;
    while (*count < MAX_SONGS && fgets(playlist[*count], MAX_TITLE_LEN, fp)) {
        playlist[*count][strcspn(playlist[*count], "\n")] = 0;
        (*count)++;
    }

    fclose(fp);
}


void savePlaylist(char playlist[][MAX_TITLE_LEN], int count) {
    FILE *fp = fopen("playlist.txt", "w");
    if (!fp) return;

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", playlist[i]);
    }

    fclose(fp);
}


void addSong(char playlist[][MAX_TITLE_LEN], int *count) {
    if (*count >= MAX_SONGS) {
        printf("Playlist full!\n");
        return;
    }

    char title[MAX_TITLE_LEN];

    printf("Enter new song title (5 to 7 words): ");
    clearInputBuffer();
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0;

    int words = countWords(title);

    if (words < 5 || words > 7) {
        printf("Invalid title! Must be 5 to 7 words.\n");
        return;
    }

    strcpy(playlist[*count], title);
    (*count)++;

    savePlaylist(playlist, *count);
    printf("Song added!\n");
}


void deleteSong(char playlist[][MAX_TITLE_LEN], int *count) {
    if (*count == 0) {
        printf("Playlist empty!\n");
        return;
    }

    char title[MAX_TITLE_LEN];

    printf("Enter song title to delete: ");
    clearInputBuffer();
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(playlist[i], title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        strcpy(playlist[i], playlist[i + 1]);
    }

    (*count)--;

    savePlaylist(playlist, *count);
    printf("Song deleted.\n");
}


void updateSong(char playlist[][MAX_TITLE_LEN], int count) {
    if (count == 0) {
        printf("Playlist empty!\n");
        return;
    }

    char oldTitle[MAX_TITLE_LEN];
    char newTitle[MAX_TITLE_LEN];

    printf("Enter song title to update: ");
    clearInputBuffer();
    fgets(oldTitle, MAX_TITLE_LEN, stdin);
    oldTitle[strcspn(oldTitle, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(playlist[i], oldTitle) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found!\n");
        return;
    }

    printf("Enter new title (5 to 7 words): ");
    fgets(newTitle, MAX_TITLE_LEN, stdin);
    newTitle[strcspn(newTitle, "\n")] = 0;

    int words = countWords(newTitle);

    if (words < 5 || words > 7) {
        printf("Invalid title! Must be 5 to 7 words.\n");
        return;
    }

    strcpy(playlist[index], newTitle);

    savePlaylist(playlist, count);
    printf("Song updated.\n");
}


void searchSong(char playlist[][MAX_TITLE_LEN], int count) {
    if (count == 0) {
        printf("Playlist empty!\n");
        return;
    }

    char query[MAX_TITLE_LEN];

    printf("Enter search text: ");
    clearInputBuffer();
    fgets(query, MAX_TITLE_LEN, stdin);
    query[strcspn(query, "\n")] = 0;

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(playlist[i], query) != NULL) {
            printf("Found: %s\n", playlist[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No matching songs.\n");
}


void sortPlaylist(char playlist[][MAX_TITLE_LEN], int count) {
    char temp[MAX_TITLE_LEN];

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(playlist[i], playlist[j]) > 0) {
                strcpy(temp, playlist[i]);
                strcpy(playlist[i], playlist[j]);
                strcpy(playlist[j], temp);
            }
        }
    }
}


int main() {
    char playlist[MAX_SONGS][MAX_TITLE_LEN];
    int count = 0;

    loadPlaylist(playlist, &count);

    int choice;

    while (1) {
        printf("\n--- MUSIC PLAYLIST MENU ---\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Update Song\n");
        printf("4. Search Song\n");
        printf("Enter -1 to exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if (choice == -1)
            break;

        switch (choice) {
            case 1: addSong(playlist, &count); break;
            case 2: deleteSong(playlist, &count); break;
            case 3: updateSong(playlist, count); break;
            case 4: searchSong(playlist, count); break;
            default: printf("Invalid choice!\n");
        }
    }

    printf("\nFinal Playlist (Alphabetical):\n");
    sortPlaylist(playlist, count);

    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, playlist[i]);
    }

    savePlaylist(playlist, count);
    return 0;
}
