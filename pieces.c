#include "pieces.h"
#include <ctype.h>

char get_piece(chess_piece piece) {
    char piece_char;

    switch (piece.type) {
        case EMPTY:
            return ' ';
        case PAWN:
            piece_char = 'p';
            break;
        case ROOK:
            piece_char = 'r';
            break;
        case KNIGHT:
            piece_char = 'n';
            break;
        case BISHOP:
            piece_char = 'b';
            break;
        case QUEEN:
            piece_char = 'q';
            break;
        case KING:
            piece_char = 'k';
            break;
        default:
            piece_char = ' '; 
            break;
    }

    if (piece.color == BLACK) {
        piece_char = toupper(piece_char); 
    }

    return piece_char;
}