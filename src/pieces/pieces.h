#ifndef PIECES_H
#define PIECES_H

#include "turn.h"
#include "stdbool.h"
#include "turn.h"

typedef enum {
    EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} piece_type;

typedef struct {
    piece_type type;
    white_or_black color;
    bool first_turn;
    bool threatened;
} chess_piece;

char get_piece(chess_piece piece);

#endif