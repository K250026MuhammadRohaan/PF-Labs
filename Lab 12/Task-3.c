#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int containsDigit(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            return 1;
        i++;
    }
    return 0;
}

int main() {
    int choice;
    int n = 0, i;
    char **users = NULL;

    while (1) {
        printf("\n1. Enter number of usernames");
        printf("\n2. Input usernames");
        printf("\n3. Display usernames without digits");
        printf("\n4. Free memory and exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                printf("Enter number of usernames: ");
                scanf("%d", &n);
                getchar();
                users = (char**)malloc(n * sizeof(char*));
                break;

            case 2:
                if (users == NULL) break;
                for (i = 0; i < n; i++) {
                    char temp[200];
                    printf("Enter username %d: ", i);
                    fgets(temp, sizeof(temp), stdin);
                    temp[strcspn(temp, "\n")] = '\0';
                    users[i] = (char*)malloc(strlen(temp) + 1);
                    strcpy(users[i], temp);
                }
                break;

            case 3:
                if (users == NULL) break;
                printf("Usernames without digits:\n");
                for (i = 0; i < n; i++) {
                    if (!containsDigit(users[i])) {
                        printf("%s\n", users[i]);
                    }
                }
                break;

            case 4:
                if (users != NULL) {
                    for (i = 0; i < n; i++) {
                        free(users[i]);
                    }
                    free(users);
                }
                return 0;
        }
    }
}