#include "chess_piece.cpp"

class pawn : public chessPiece {
	pawn(int file, char rank, char color, string imgId);
};

pawn::pawn(int file, char rank, char color, string imgId) : chessPiece(int file, char rank, int color) {

}
