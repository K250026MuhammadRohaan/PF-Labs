#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    printf("\n\t\t\t====================   CINEMA HALL - EMPTY SEATS CALCULATOR   ====================\n\n");
    srand(time(NULL));

    int ROW, COLUMN;
    int numAvailableSeats=0, row_EmptySeat=0, num_EmptySeat=0, count=0;

    printf("\n->  SIZE OF CINEMA HALL:-\n");
    printf("Enter no. of ROWS of Cinema Hall:  ");
    scanf("%d", &ROW);
    printf("Enter no. of COLUMNS of Cinema Hall:  ");
    scanf("%d", &COLUMN);
    printf("\n\n");


    int cinemaHall[ROW][COLUMN];

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            cinemaHall[i][j] = (rand() % (1 - 0 + 1)) + 0;
        }
    }


    printf("\n->  %dx%d CINEMA HALL SEATING ARRANGEMENT (0 -> Empty, 1 -> OCCUPIED):\n\n", ROW, COLUMN);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%2d", cinemaHall[i][j]);
        }
        printf("\n");
    };


    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (cinemaHall[i][j] == 0) numAvailableSeats++;
        }
    }

    printf("\n\n\n->  Total Number of Available Seats:-  %d\n\n", numAvailableSeats);


    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (cinemaHall[i][j] == 0) count++;
        }

        if (count == 0)
        {
            printf("->  There are NO Empty Seats Available in ANY ROW.\n\n");
            return 0;
        }
        else if (count>num_EmptySeat)
        {
            num_EmptySeat = count;
            row_EmptySeat = i;
        }

        count = 0;
    }

    printf("->  Row with Most Empty Seats: Row %d (%d empty seats)\n", row_EmptySeat, num_EmptySeat);

    getch();
    return 0;
}