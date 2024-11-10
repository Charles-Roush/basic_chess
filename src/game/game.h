#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "turn.h"
#include "pieces.h"

typedef struct

{
    unsigned int black_turns;
    unsigned int white_turns;

    white_or_black turn;

    unsigned int white_score;
    unsigned int black_score;

} game_stats;

typedef struct
{
    int x;
    int y;
} vector2;

vector2 get_pos(char *input);

bool check_valid_move(vector2 before_pos, vector2 after_pos, white_or_black turn, chess_piece board[BOARD_SIZE][BOARD_SIZE]);

bool check_valid_straight(vector2 before_pos, vector2 after_pos, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change, vector2 difference);

bool check_valid_diagonal(vector2 before_pos, vector2 after_pos, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change, vector2 difference);
#endif

