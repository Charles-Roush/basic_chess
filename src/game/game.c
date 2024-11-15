#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "game.h"
#include "board.h"
#include "pieces.h"
#include "util.h"
#include "turn.h"
#include "checks.h"

bool check_valid_move(vector2 before_pos, vector2 after_pos, white_or_black turn, chess_piece board[BOARD_SIZE][BOARD_SIZE])
{

    printf("before pos\n x = %i\n y = %i\n\n", before_pos.x, before_pos.y);
    printf("after\n x = %i\n y = %i\n\n", after_pos.x, after_pos.y);
    chess_piece before_piece = board[before_pos.y][before_pos.x];
    chess_piece after_piece = board[after_pos.y][after_pos.x]; after_piece.first_turn = true;


    if (before_piece.color != turn){
        printf("not turn\n"); 
        return false;
    }

    if (before_piece.type == EMPTY){
        printf("empty square\n");
    }

    if (before_pos.x == after_pos.x && before_pos.y == after_pos.y){
        printf("not piece\n"); 
        return false;
    }

    vector2 difference; difference.x = after_pos.x - before_pos.x; difference.y = after_pos.y - before_pos.y;

    printf("Difference x: %i, y: %i\n", difference.x, difference.y);

    vector2 change;

    if (difference.x > 0){
        change.x = 1; 
    }
    else if (difference.x < 0){
        change.x = -1;
    }
    else change.x = 0;
    
    printf("change.x = %i\n", change.x);

    if (difference.y > 0){
        change.y = 1; 
    }
    else if (difference.y < 0){
        change.y = -1; 
    } 
    else change.y = 0;

    printf("change.y = %i\n", change.y);

    printf("checking pieces\n");
    switch (before_piece.type)
    {
        // The Pawn moves directly forward, never backward or to the side. 
        // Pawns move exactly one square forward but are allowed to move 2 on first turn; 
        // Pawns capture a piece that is one square diagonally forward.
        case PAWN:
            printf("checking pawn\n");
            if (check_pawn(before_piece, after_piece, before_pos, after_pos, difference, board, change)){
                printf("pawn");
                return true;
            }
            else return false;
        case ROOK:
            printf("rook\n");
            if (check_rook(before_pos, after_pos, difference, board, change)){
                return true;
            }
            else return false;
        case KNIGHT:
            printf("knight\n");
            if (check_knight(difference)){
                return true;
            }
            else return false;
        case BISHOP:
            printf("bishop\n");
            if (check_bishop(before_pos, after_pos, difference, board, change)){
                return true;
            }
            else return false;
        case QUEEN:
            printf("queen\n");
            if (check_queen(before_pos, after_pos, difference, board, change)){
                return true;
            }
            else return false;
        case KING:
            printf("king\n");
            if (check_king(difference)){
                return true;
            }
            else return false;
    
    default:
        break;
    }
    return true;
    
}


vector2 tokenize_board_pos(char *move_string)
{
    vector2 pos;
    pos.x = -1;
    pos.y = -1;

    for (int i = 0; i < strlen(move_string); i++) {
        if (isdigit(move_string[i])) {
            int y = move_string[i] - '1';
            if (y > -1 && y < 8)
            {
                pos.y = y;
            }
        } else if (isalpha(move_string[i])) {
            int x = move_string[i] - 'a';
            if (x > -1 && x < 8)
            {
                pos.x = x;
            }
        }
    }
    return pos;
}

vector2 get_pos(char *input)
{
    bool move_is_good = false;
    vector2 pos;
    while (move_is_good == false) {
        char *move_string = get_string(input);
        pos = tokenize_board_pos(move_string);
        if (pos.x == -1 || pos.y == -1) {
            printf("Invalid Pos\n");
        } else{
            move_is_good = true;
        }
    }
    return pos;
}