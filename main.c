#include <stdio.h>
#include "game_board.h"
#include "player_turns.h"
#include "debug.h"
#include <string.h>
int main()
{
    char **p = initialise();
    player(p);
    return 0;
}
