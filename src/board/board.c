#include <stdbool.h>
#include "board.h"
#include "pieces.h"
#include <stdio.h>
#include "game.h"

//       A   B   C   D   E   F   G   H
//     |---|---|---|---|---|---|---|---|
//   1 | r | n | b | q | k | b | n | r |
//     |---|---|---|---|---|---|---|---|
//   2 | p | p | p | p | p | p | p | p |
//     |---|---|---|---|---|---|---|---|
//   3 |   |   |   |   |   |   |   |   |
//     |---|---|---|---|---|---|---|---|
//   4 |   |   |   |   |   |   |   |   |
//     |---|---|---|---|---|---|---|---|
//   5 |   |   |   |   |   |   |   |   |
//     |---|---|---|---|---|---|---|---|
//   6 |   |   |   |   |   |   |   |   |
//     |---|---|---|---|---|---|---|---|
//   7 | P | P | P | P | P | P | P | P |
//     |---|---|---|---|---|---|---|---|
//   8 | R | N | B | Q | K | B | N | R |
//     |---|---|---|---|---|---|---|---|
void update_board(vector2 before_pos, vector2 after_pos, chess_piece board[BOARD_SIZE][BOARD_SIZE]) {
    chess_piece piece = board[before_pos.y][before_pos.x];

    board[before_pos.y][before_pos.x].type = EMPTY;
    board[after_pos.y][after_pos.x].type = piece.type; 
    board[after_pos.y][after_pos.x].color = piece.color;
    board[after_pos.y][after_pos.x].first_turn = false;
    
}

chess_piece init_board(chess_piece board[BOARD_SIZE][BOARD_SIZE]) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x].type = EMPTY;
        }
    }

    int board_y = 0;
    bool is_black = false;

    for (int board_x = 0; board_x < BOARD_SIZE; board_x++) {
        switch (board_x) {
            case 0:
            case 7:
                board[board_y][board_x].type = ROOK;
                break;
            case 1:
            case 6:
                board[board_y][board_x].type = KNIGHT;
                break;
            case 2:
            case 5:
                board[board_y][board_x].type = BISHOP;
                break;
            case 3:
                board[board_y][board_x].type = QUEEN;
                break;
            case 4:
                board[board_y][board_x].type = KING;
                break;
        }
        board[board_y][board_x].color = WHITE;
    }

    board_y = 1;
    for (int board_x = 0; board_x < BOARD_SIZE; board_x++) {
        board[board_y][board_x].type = PAWN;
        board[board_y][board_x].first_turn = true;
        board[board_y][board_x].color = WHITE;
        printf("Board y = %i\n Board x = %i\n Board color = %d\n", board_y, board_x, board[board_y][board_x].color);
    }

    board_y = 7;
    is_black = true;
    for (int board_x = 0; board_x < BOARD_SIZE; board_x++) {
        switch (board_x) {
            case 0:
            case 7:
                board[board_y][board_x].type = ROOK;
                break;
            case 1:
            case 6:
                board[board_y][board_x].type = KNIGHT;
                break;
            case 2:
            case 5:
                board[board_y][board_x].type = BISHOP;
                break;
            case 3:
                board[board_y][board_x].type = QUEEN;
                break;
            case 4:
                board[board_y][board_x].type = KING;
                break;
        }
        board[board_y][board_x].color = BLACK;
    }

    board_y = 6;
    for (int board_x = 0; board_x < BOARD_SIZE; board_x++) {
        board[board_y][board_x].type = PAWN;
        board[board_y][board_x].first_turn = true;
        board[board_y][board_x].color = BLACK;
        printf("Board y = %i\n Board x = %i\n Board color = %d\n", board_y, board_x, board[board_y][board_x].color);
    }
}

void print_row(chess_piece board_row[BOARD_SIZE], int key_y) {
    printf("%i", key_y + 1);
    printf(BOARD_FILLER);
    for (int board_x = 0; board_x < BOARD_SIZE; board_x++) {
        char piece = get_piece(board_row[board_x]);
        printf(" %c%s", piece, BOARD_FILLER);
    }
    printf("\n");
}

void print_board(chess_piece board[BOARD_SIZE][BOARD_SIZE]) {
    printf(BOARD_KEY_X);
    printf(BOARD_BLANK);
    for (int board_y = 0; board_y < BOARD_SIZE; board_y++) {     
        print_row(board[board_y], board_y);
        printf(BOARD_BLANK);       
    }
}