#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_USERS 50


typedef struct
{
    char luckyColor[20];
    int luckyNumber;
    char advice[100];
} Forecast;

typedef struct {
    char signName[20];
    Forecast forecast;
} Zodiac;

typedef struct {
    char name[50];
    int day, month;
    Zodiac zodiac;
} User;


Zodiac zodiacList[12] =
{
    {"Aries", {"Red", 9, "Take bold steps today."}},
    {"Taurus", {"Green", 6, "Stay calm and focused."}},
    {"Gemini", {"Yellow", 5, "Communication brings luck."}},
    {"Cancer", {"White", 2, "Trust your emotions."}},
    {"Leo", {"Gold", 1, "Your confidence will shine."}},
    {"Virgo", {"Brown", 8, "Pay attention to details."}},
    {"Libra", {"Pink", 7, "Balance will bring peace."}},
    {"Scorpio", {"Black", 4, "Be brave and decisive."}},
    {"Sagittarius", {"Purple", 3, "Adventure awaits today."}},
    {"Capricorn", {"Grey", 10, "Hard work pays off."}},
    {"Aquarius", {"Blue", 11, "Think outside the box."}},
    {"Pisces", {"Sea Green", 12, "Stay connected to creativity."}}
};


int getZodiacIndex(int day, int month)
{
    if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) return 0;
    if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) return 1;
    if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) return 2;
    if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) return 3;
    if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) return 4;
    if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) return 5;
    if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) return 6;
    if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) return 7;
    if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) return 8;
    if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) return 9;
    if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) return 10;
    return 11;
}


void inputUser(User *u)
{
    printf("\nEnter name: ");
    scanf(" %[^\n]", u->name);

    printf("Enter birth day: ");
    scanf("%d", &u->day);

    printf("Enter birth month: ");
    scanf("%d", &u->month);

    int zodiacIndex = getZodiacIndex(u->day, u->month);
    u->zodiac = zodiacList[zodiacIndex];
}

void displayHoroscope(User *u)
{
    printf("\n------  Personalized Horoscope  ------\n");
    printf("Name: %s\n", u->name);
    printf("Zodiac Sign: %s\n", u->zodiac.signName);
    printf("Lucky Color: %s\n", u->zodiac.forecast.luckyColor);
    printf("Lucky Number: %d\n", u->zodiac.forecast.luckyNumber);
    printf("Advice: %s\n", u->zodiac.forecast.advice);
}

void updateForecast()
{
    char sign[20];
    printf("\nEnter zodiac name to update: ");
    scanf(" %[^\n]", sign);

    for (int i=0 ; i<12 ; i++)
    {
        if (strcasecmp(sign, zodiacList[i].signName) == 0)
        {

            printf("Enter new lucky color: ");
            scanf(" %[^\n]", zodiacList[i].forecast.luckyColor);

            printf("Enter new lucky number: ");
            scanf("%d", &zodiacList[i].forecast.luckyNumber);

            printf("Enter new advice: ");
            scanf(" %[^\n]", zodiacList[i].forecast.advice);

            printf("Forecast updated successfully.\n");
            return;
        }
    }

    printf("Zodiac sign not found.\n");
}


int main()
{
    User users[MAX_USERS];
    int userCount = 0;
    int choice;

    while (1)
    {
        printf("\n\n==================  ASTROLOGY APP  ==================\n");
        printf("1. Add New User\n");
        printf("2. Display Horoscope for User\n");
        printf("3. Update Zodiac Forecast\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            inputUser(&users[userCount]);
            userCount++;
            printf("User added successfully.\n");
        }
        else if (choice == 2)
        {
            int index;
            printf("Enter user index (0 - %d): ", userCount - 1);
            scanf("%d", &index);

            if (index >= 0 && index < userCount) displayHoroscope(&users[index]);
            else printf("Invalid user index.\n");
        }
        else if (choice == 3)
        {
            updateForecast();
        }
        else if (choice == 4)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    getch();
    return 0;
}