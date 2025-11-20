#include <stdio.h>
#include <string.h>

#define MAX_RECIPES 40
#define MAX_LEN 200


void loadRecipes(char arr[][MAX_LEN], int *count);
void saveRecipes(char arr[][MAX_LEN], int count);
void sortRecipes(char arr[][MAX_LEN], int count);
void addRecipe(char arr[][MAX_LEN], int *count);
void modifyRecipe(char arr[][MAX_LEN], int count);
void removeRecipe(char arr[][MAX_LEN], int *count);
void searchRecipe(char arr[][MAX_LEN], int count);


int main() {
    char recipes[MAX_RECIPES][MAX_LEN];
    int count = 0;

    loadRecipes(recipes, &count);

    int choice;

    while (1) {
        printf("\n--- COOKING ASSISTANT MENU ---\n");
        printf("1. Add Recipe\n");
        printf("2. Modify Recipe\n");
        printf("3. Remove Recipe\n");
        printf("4. Search Recipe\n");
        printf("Enter -1 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == -1)
            break;

        switch (choice) {
            case 1: addRecipe(recipes, &count); break;
            case 2: modifyRecipe(recipes, count); break;
            case 3: removeRecipe(recipes, &count); break;
            case 4: searchRecipe(recipes, count); break;
            default: printf("Invalid choice!\n");
        }
    }

    sortRecipes(recipes, count);
    saveRecipes(recipes, count);

    printf("\nRecipes sorted and saved to recipes.txt\n");

    return 0;
}


void loadRecipes(char arr[][MAX_LEN], int *count) {
    FILE *fp = fopen("recipes.txt", "r");
    if (!fp) return;

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(arr[*count], line);
        (*count)++;
        if (*count == MAX_RECIPES) break;
    }

    fclose(fp);
}

void saveRecipes(char arr[][MAX_LEN], int count) {
    FILE *fp = fopen("recipes.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s\n", arr[i]);
    fclose(fp);
}


void sortRecipes(char arr[][MAX_LEN], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[MAX_LEN];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}


void addRecipe(char arr[][MAX_LEN], int *count) {
    if (*count == MAX_RECIPES) {
        printf("Recipe list full!\n");
        return;
    }

    char temp[MAX_LEN];
    printf("Enter new recipe name: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    strcpy(arr[*count], temp);
    (*count)++;

    printf("Recipe added!\n");
}


void modifyRecipe(char arr[][MAX_LEN], int count) {
    if (count == 0) {
        printf("No recipes to modify.\n");
        return;
    }

    char target[MAX_LEN];
    printf("Enter recipe to modify: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(arr[i], target) == 0) {

            char newName[MAX_LEN];
            printf("Enter new recipe name: ");
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = '\0';

            strcpy(arr[i], newName);

            printf("Recipe updated!\n");
            return;
        }
    }

    printf("Recipe not found.\n");
}


void removeRecipe(char arr[][MAX_LEN], int *count) {
    if (*count == 0) {
        printf("No recipes to remove.\n");
        return;
    }

    char target[MAX_LEN];
    printf("Enter recipe to remove: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    for (int i = 0; i < *count; i++) {
        if (strcmp(arr[i], target) == 0) {

            for (int j = i; j < *count - 1; j++) {
                strcpy(arr[j], arr[j + 1]);
            }

            (*count)--;

            printf("Recipe removed!\n");
            return;
        }
    }

    printf("Recipe not found.\n");
}


void searchRecipe(char arr[][MAX_LEN], int count) {
    if (count == 0) {
        printf("No recipes to search.\n");
        return;
    }

    char target[MAX_LEN];
    printf("Enter keyword or full recipe: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    int found = 0;

    printf("\n");

    for (int i = 0; i < count; i++) {
        if (strstr(arr[i], target) != NULL) {
            printf("FOUND: %s\n", arr[i]);
            found = 1;
        }
    }

    if (!found)
        printf("NOT FOUND\n");

    printf("\n");
}