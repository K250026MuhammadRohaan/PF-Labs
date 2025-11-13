#include <stdio.h>
#include <conio.h>

float findBonus(int salary)
{
    int bonus;

    if (salary < 30000)
    {
        return bonus = salary * 0.20;
    }
    else
    {
        return bonus = salary * 0.10;
    }
}

int main()
{
    int salary[5], totalPayout = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("\nEmployee %d Salary:  ", i + 1);
        scanf("%d", &salary[i]);

        totalPayout += salary[i];
        float bonus = findBonus(salary[i]);
        totalPayout += bonus;

        printf("Employee %d Bonus:  %.2f", i + 1, bonus);
    }

    printf("\n\nTotal Payout:  %d\n", totalPayout);
}