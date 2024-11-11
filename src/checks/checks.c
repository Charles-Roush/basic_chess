#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "game.h"
#include "checks.h"

bool check_valid_straight(vector2 before_pos, vector2 after_pos, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change, vector2 difference)
{
    white_or_black before_color = board[before_pos.y][before_pos.x].color;  // y, x order

    if (change.y != 0)  // Vertical movement (along the y-axis)
    {
        for (int y = before_pos.y + change.y; y != after_pos.y; y += change.y)  // Iterate vertically
        {
            if (board[y][before_pos.x].color == before_color && board[y][before_pos.x].type != EMPTY)  // [y][x] access
            {
                return false;  // Piece blocking the path
            }
        }
        return true;
    }
    else if (change.x != 0)  
    {
        for (int x = before_pos.x + change.x; x != after_pos.x; x += change.x)  // Iterate horizontally
        {
            if (board[before_pos.y][x].color == before_color && board[before_pos.y][x].type != EMPTY)  // [y][x] access
            {
                return false;  
            }
        }
        return true;
    }
    else return false; 
}


bool check_valid_diagonal(vector2 before_pos, vector2 after_pos, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change, vector2 difference) 
{ 
    if (abs(difference.x) != abs(difference.y))  // Ensure diagonal
    {
        printf("Not diagonal\n"); 
        return false;
    }

    white_or_black before_color = board[before_pos.y][before_pos.x].color;  // y, x order
    
    for (int x = before_pos.x + change.x, y = before_pos.y + change.y; 
         x != after_pos.x && y != after_pos.y; 
         x += change.x, y += change.y)  // Iterate diagonally
    {
        if (board[y][x].color == before_color && board[y][x].type != EMPTY)  // [y][x] access
        {
            printf("pieces in between\n"); 
            return false;  // Piece blocking the path
        }
    }
    return true; 
}


bool check_pawn(chess_piece before_piece, chess_piece after_piece, vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{   
    if (abs(difference.y) > 2){
    return false;
    }
    
    if (before_piece.first_turn == false && abs(difference.y > 1)){
    return false;
    }
    
    if (difference.x == 0){
        if (after_piece.type != EMPTY)
        {
            printf("pawns can only move diagonally to take an enemy piece.\n");
            return false;
        }
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
bool check_rook(vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
    return check_valid_straight(before_pos, after_pos, board, change, difference);
}
bool check_knight(vector2 difference) 
{
    if ((abs(difference.x) == 2 && abs(difference.y) == 1) || 
        (abs(difference.x) == 1 && abs(difference.y) == 2))
    {
        return true;
    }
    else
    {
        printf("Knights can only move in an L shape.\n");
        return false;
    }
}
bool check_bishop(vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
    return check_valid_diagonal(before_pos, after_pos, board, change, difference);
}
bool check_queen(vector2 before_pos, vector2 after_pos, vector2 difference, chess_piece board[BOARD_SIZE][BOARD_SIZE], vector2 change)
{
    if (check_valid_diagonal(before_pos, after_pos, board, change, difference) || check_valid_straight(before_pos, after_pos, board, change, difference))
    {
        return true;
    }
    else return false;
}
bool check_king(vector2 difference)
{
    if (abs(difference.x) < 2 && abs(difference.y) < 2)
    {
        return true;
    }
    else return false;
}