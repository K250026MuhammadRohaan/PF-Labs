#include <stdio.h>
#include <conio.h>

#define MAX_EMPLOYEES 100

struct Employee
{
    char name[50];
    int id;
    int daysPresent;
};

int totalAttendance(struct Employee emp[], int index, int n)
{
    if (index == n) return 0;

    return emp[index].daysPresent + totalAttendance(emp, index + 1, n);
}

int main()
{
    struct Employee emp[MAX_EMPLOYEES];
    int n, minRequired;

    printf("\nEnter number of employees: ");
    scanf("%d", &n);

    for (int i=0 ; i<n ; i++)
    {
        printf("\n\n---------  Employee %d  ---------\n", i+1);

        printf("Enter name: ");
        scanf("%s", emp[i].name);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter days present: ");
        scanf("%d", &emp[i].daysPresent);
    }

    int total = totalAttendance(emp, 0, n);
    printf("\n> Total attendance for all employees = %d\n", total);

    printf("\n\n--> Enter minimum required days of attendance: ");
    scanf("%d", &minRequired);

    printf("\n> Employees with attendance less than %d days:\n", minRequired);
    int found = 0;

    for (int i=0 ; i<n ; i++)
    {
        if (emp[i].daysPresent < minRequired)
        {
            printf("\nName: %s", emp[i].name);
            printf("\nID: %d", emp[i].id);
            printf("\nDays Present: %d\n", emp[i].daysPresent);
            found = 1;
        }
    }

    if (!found) printf("None.\n");

    getch();
    return 0;
}
