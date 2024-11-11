#ifndef CHECKS_H
#define CHECKS_H

#include "pieces.h"
#include "turn.h"
#include "board.h"
#include "game.h"

bool check_pawn(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change);
bool check_rook(vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change);
bool check_knight(vector2 difference);
bool check_bishop(vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change);
bool check_queen(vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change);
bool check_king(vector2 difference);

#endif