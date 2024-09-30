#include "player_turns.h"

void player(char **board)
{
    int **R = (int **)malloc(ROWS * sizeof(int *));
    int **C = (int **)malloc(COLUMNS * sizeof(int *));
    for (int row = 0; row < ROWS; row++)
    {
        R[row] = (int *)malloc(COLUMNS * sizeof(int));
        C[row] = (int *)malloc(ROWS * sizeof(int));
    }
    int counter = 0, tot_move = 0;
    int row = 0, col = 0;
    bool check = false;
    for (int i = 0; i < PLAYERS; i++)
    {
        memset(R[i], 0, ROWS * sizeof(int));
        memset(C[i], 0, COLUMNS * sizeof(int));
    }
    while (!check)
    {
        if (tot_move == MAX_TURN)
        {
            printf("EXITING AS NOBODY WON\n");
            break;
        }
        printf("PLAYER %s", counter > 0 ? "TWO\n" : "ONE\n");
        display_board(board);
        printf("Make You Move\n Choose Row(1-3) : ");
        scanf("%d", &row);
        printf("\nChoose Column(1-3) : ");
        scanf("%d", &col);
        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            printf("Box doesn't exist!!!\n Choose again\n");
            continue;
        }
        if (board[row - 1][col - 1] == ' ')
        {
            board[row - 1][col - 1] = (counter == 0 ? 'X' : 'O');
        }
        else
        {
            printf("Can't make a move on a area which is already played.\n Enter AGAIN!!!!\n");
            continue;
        }
        if (!counter)
        {
            R[0][row - 1]++;
            C[0][col - 1]++;
        }
        else
        {
            R[1][row - 1]++;
            C[1][col - 1]++;
        }

        tot_move++;
        check = (check_win(R, C) || diagonal_check(board));
        if (check)
        {
            printf("PLAYER %s WINS\n", counter > 0 ? "TWO" : "ONE");
            display_board(board);
        }
        counter ^= 1;
    }
}