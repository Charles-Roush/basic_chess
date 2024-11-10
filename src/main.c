#include <stdbool.h>
#include <stdio.h>
#include  "game.h"
#include "turn.h"
#include "board.h"
#include "pieces.h"

int main(void)
{
    chess_piece board[BOARD_SIZE][BOARD_SIZE];
    game_stats game; game.turn = WHITE; game.black_score = 0; game.white_score = 0; game.black_turns = 0; game.white_turns = 0;

    init_board(board); bool exit = false; vector2 before_pos; vector2 after_pos; game.turn = BLACK;
    
    while (exit == false){
        print_board(board);
        printf("turn = %d\n", game.turn);

        while (true){
            before_pos = get_pos("piece pos:  ");
            after_pos =  get_pos("  new pos:  ");
            printf("checking valididity...\n\n");
            if (check_valid_move(before_pos, after_pos, game.turn, board)){
                break;
            }
            else printf("invalid\n");
        }

        update_board(before_pos, after_pos, board);

        if (game.turn == WHITE) game.turn = BLACK;
        else game.turn = WHITE;
    }
}