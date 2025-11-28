#include <stdio.h>
#include <conio.h>

#define MAX_TEAMS 100
#define MAX_ROUNDS 100

struct Team
{
    char name[50];
    int scores[MAX_ROUNDS];
    int rounds;
};

int sumScores(int scores[], int index, int rounds)
{
    if (index == rounds) return 0;

    return scores[index] + sumScores(scores, index + 1, rounds);
}

int main()
{
    int n;
    struct Team teams[MAX_TEAMS];

    printf("\nEnter number of teams: ");
    scanf("%d", &n);

    for (int i=0 ; i<n ; i++)
    {
        printf("\n\n------  Team %d  ------\n", i+1);

        printf("Enter team name: ");
        scanf("%s", teams[i].name);

        printf("Enter number of rounds: ");
        scanf("%d", &teams[i].rounds);

        printf("\nEnter scores for each round:\n");

        for (int j=0 ; j<teams[i].rounds ; j++)
        {
            printf("Round %d score: ", j + 1);
            scanf("%d", &teams[i].scores[j]);
        }
    }


    int threshold;
    printf("\nEnter score threshold: ");
    scanf("%d", &threshold);

    printf("\n\n==========  TEAM SCORES AND RESULTS  ==========\n");

    for (int i=0 ; i<n ; i++)
    {
        printf("\nTeam: %s\n", teams[i].name);

        int total = sumScores(teams[i].scores, 0, teams[i].rounds);
        printf("Total Score: %d\n", total);

        if (total > threshold) printf("Result: ABOVE threshold\n");
        else printf("Result: NOT above threshold\n");
    }

    getch();
    return 0;
}