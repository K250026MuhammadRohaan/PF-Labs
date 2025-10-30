#include <stdio.h>
#include <conio.h>

#define STUDENT 5
#define SUBJECT 4

int main ()
{
    printf("\n\t\t\t====================   STUDENT MARKS IN 2D-ARRAY   ====================\n\n");

    int marks[STUDENT][SUBJECT], studentTotal, highestMarks[SUBJECT];
    float studentAverage;

    for (int i=0 ; i<STUDENT ; i++)
    {
        printf("\n->  Enter Marks of Student no. %d:\n", i+1);

        for (int j=0 ; j<SUBJECT ; j++)
        {
            printf("- Subject #%d:  ", j+1);
            scanf("%d", &marks[i][j]);
        }
    }

	printf("\n\n\n->  Average Marks of Each Student:-\n");
	for (int i = 0 ; i < STUDENT ; i++)
    {
        studentTotal = 0;

        for (int j = 0 ; j < SUBJECT ; j++)
        {
            studentTotal += marks[i][j];
        }

        studentAverage = (float)studentTotal / SUBJECT;
        printf("\n  Student no. %d:  %.1f", i+1, studentAverage);
    }


    printf("\n\n\n->  Highest Marks In Each Subject:-\n");
	for (int i = 0 ; i < SUBJECT ; i++)
    {
        highestMarks[i] = 0;

        for (int j = 0 ; j < STUDENT ; j++)
        {
            if (marks[j][i] > highestMarks[i])
            {
                highestMarks[i] = marks[j][i];
            }
        }

        printf("\n  Subject #%d:  %d", i+1, highestMarks[i]);
    }

    getch();
    return 0;
}