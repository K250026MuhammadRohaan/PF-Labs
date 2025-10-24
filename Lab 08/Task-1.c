#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 8
#define COLUMN 8

int main()
{
    int min = 0, max = 255;

    srand(time(NULL));
    int matrix[ROW][COLUMN];

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix[i][j] = (rand() % max) + min;
        }
    }

    printf("\n\n\n-> Original %dx%d Image Matrix:\n\n", ROW, COLUMN);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix[i][j] += 20;

            if (matrix[i][j] > 255)
            {
                matrix[i][j] = 255;
            }
        }
    }

    printf("\n\n\n-> Brightened %dx%d Image Matrix:\n\n", ROW, COLUMN);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    getch();
    return 0;
}