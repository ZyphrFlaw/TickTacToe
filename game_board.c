#include "game_board.h"
#include "debug.h"

char **initialise()
{
    char **board = (char **)malloc(ROWS * sizeof(char *));
    int row;

    // for each row allocate Cols chars
    for (row = 0; row < ROWS; row++)
    {
        board[row] = (char *)malloc(COLUMNS * sizeof(char));
    }

    printf("Board created successfully!!! \n");
    for (row = 0; row < ROWS; row++)
    {
        memset(board[row], ' ', COLUMNS * sizeof(int));
    }
    return board;
    // dbg(arr); // TO-DO check why dbg((char**)arr) not working earlier
}
char create_line()
{
    char ch = '|';
    return ch;
}
void display_board(char **board)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c%c", create_line(), board[i][j]);
        }
        printf("|\n");
    }
}

bool check_win(int **R, int **C)
{
    for (int i = 0; i < ROWS; i++)
    {
        // printf("FIRST COUNT ROW[%d] : %d\n", i + 1, R[0][i]);
        if (R[0][i] == COLUMNS)
            return true;
    }
    for (int i = 0; i < COLUMNS; i++)
    {
        // printf(" FIRST COUNT COL[%d] : %d\n", i + 1, C[0][i]);
        if (C[0][i] == ROWS)
            return true;
    }
    for (int i = 0; i < ROWS; i++)
    {
        // printf("SECOND COUNT ROW[%d] : %d\n", i + 1, R[1][i]);
        if (R[1][i] == COLUMNS)
            return true;
    }
    for (int i = 0; i < COLUMNS; i++)
    {
        // printf("SECOND COUNT COL[%d] : %d\n", i + 1, C[1][i]);
        if (C[1][i] == ROWS)
            return true;
    }
    // printf("********************************\n");
    return false;
}
bool diagonal_check(char **R)
{
    int flag_right = 1, flag_left = 1;
    for (int i = 1; i < ROWS; i++)
    {
        if (R[i - 1][i - 1] != R[i][i])
        {
            flag_right = 0;
            break;
        }
    }
    for (int i = 1; i < ROWS; i++)
    {
     //   printf("%c %c\n",R[i - 1][COLUMNS - i] , R[i][COLUMNS - 1 - i]);
        if ((R[i - 1][COLUMNS - i] != R[i][COLUMNS - 1 - i]) || (R[i - 1][COLUMNS - i] == ' '))
        {
            printf("TRUE\n");
            flag_left = 0;
            break;
        }
    }
   // printf("%d %d\n",flag_right , flag_left);
    return (bool)(flag_right | flag_left);
}