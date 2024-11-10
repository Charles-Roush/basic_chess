#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "game.h"
#include "checks.h"

bool check_pawn(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{   
    if (abs(difference.y) > 2){
    return false;
    }
    
    if (before_piece.first_turn == false && abs(difference.y > 1)){
    return false;
    }

    
    if (difference.x == 0){
        printf("checking straight\n");
        return check_valid_straight(before_pos, after_pos, board, change, difference);
    }
    else{
        printf("checking diagonally\n");
        if (after_piece.type == EMPTY)
        {
            printf("pawns can only move diagonally to take an enemy piece.\n");
            return false;
        }
        return check_valid_diagonal(before_pos, after_pos, board, change, difference);
    }

}
bool check_rook(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
return true;
}
bool check_knight(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
return true;

}
bool check_bishop(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
return true;

}
bool check_queen(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
return true;

}
bool check_king(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
return true;

}