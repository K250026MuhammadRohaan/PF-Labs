#include <stdio.h>
#include <conio.h>

int main()
{
    int SIZE;
    printf("\n\t\t\t====================   GAME BOARD ROTATOR   ====================\n\n");

    printf("\n->  Enter the size of the board (NxN):  ");
    scanf("%d", &SIZE);
    printf("\n");

    int board[SIZE][SIZE], rotated[SIZE][SIZE], temp=0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Enter Game Board element of ROW: %d & COLUMN %d:  ", i, j);
            scanf("%d", &board[i][j]);
        }
    }

    printf("\n\n\n->  Original (%dx%d) Game Board:\n\n", SIZE, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n->  Rotated (90 degrees - Clockwise) (%dx%d) Game Board:\n\n", SIZE, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rotated[j][i] = board[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE/2; j++)
        {
            temp = rotated[i][j];
            rotated[i][j] = rotated[i][SIZE-1-j];
            rotated[i][SIZE-1-j] = temp;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%4d", rotated[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    getch();
    return 0;
}