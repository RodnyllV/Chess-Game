#pragma once

#ifndef PAWN_H
#define PAWN_H

#include <wx/wx.h>
#include "ChessPiece.h"

class Pawn : public ChessPiece {
	public:
		Pawn(wxWindow* parent, wxColour& color, char player, char* position);
		
		void SetPositionParams() override;
		//void SetPositionParams() override;
		//void Move() override;
};

Pawn::Pawn(wxWindow* parent, wxColour& color, char player, char* position) : ChessPiece(parent, color, player, position) {
	SetAppearance("../Resource Files/Images/Pawn.png");
}

void Pawn::SetPositionParams() {

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
