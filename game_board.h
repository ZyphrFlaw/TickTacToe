#pragma once
#include "player_turns.h"
#include "common.h"

void dbg(char **board);
void display_board(char **board);
char **initialise();
bool check_win(int **R, int **C);
bool diagonal_check(char** board);