#pragma once

#ifndef PAWN_H
#define PAWN_H

#include <wx/wx.h>
#include "ChessPiece.h"

class Pawn : public ChessPiece {
	private:
		bool firstMove;
	public:
		Pawn(wxColour& color, char player, char* position);
		//void SetPositionParams() override;
		//void Move() override;
};

Pawn::Pawn(wxColour& color, char player, char* position) : ChessPiece(color, player, position) {
	this->firstMove = true;
}
/*
void Pawn::SetPositionParams() {
	// TODO
}

void Pawn::Move() {
	// TODO
}
*/
#endif
