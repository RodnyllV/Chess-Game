#pragma once
#include <wx/wx.h>
#include <unordered_map>
#include <iostream>
#include <string>
#include "ChessPiece.h"
#include "Frame.h"
#include "Grid.h"

using namespace std;

/* Player = {["Pawn"] = [pawnptr, pawnptr, pawnptr..], ["Rook"] = [rookptr...]} */

class App : public wxApp {
	private:
		std::unordered_map<std::string, ChessPiece> Player1Pieces;
		std::unordered_map<std::string, ChessPiece> Player2Pieces;
		Grid* Boards[GridRoot][GridRoot];
	public:
		bool OnInit() override;
};

bool App::OnInit() {
	// Initialize Window 
	Frame* MainFrame = new Frame("CHESS");

	wxBoxSizer* MainFrameSizer = new wxBoxSizer(wxVERTICAL);

	// Top Header Panel
	wxPanel* HeaderPanel = new wxPanel(MainFrame);
	wxBoxSizer* HeaderSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* TextHeader = new wxStaticText(HeaderPanel, wxID_ANY, "CHESS!");
	wxStaticText* PlayerTurn = new wxStaticText(HeaderPanel, wxID_ANY, "White's Turn");
	HeaderSizer->Add(TextHeader, 0, wxALIGN_CENTER | wxTOP, 10);
	HeaderSizer->Add(PlayerTurn, 0, wxALIGN_CENTER | wxTOP, 5);
	HeaderPanel->SetSizer(HeaderSizer);

	// Chess Board Panel
	wxPanel* GamePanel = new wxPanel(MainFrame);
	wxGridSizer* GameSizer = new wxGridSizer(GridRoot, GridRoot, 0, 0);
	//GameSizer->Add(new wxStaticText(GamePanel, wxID_ANY, "CHESS"), 0, wxALIGN_CENTER | wxTOP, 10);
	

	char TopLeftRank = '8', TopLeftFile = 'a';

	for (int Row = 0; Row < 8; Row++) { // Create the Grid
		for (int Col = 0; Col < 8; Col++) {
			wxColour BoardColor = ((Col + Row) % 2 == 0) ? wxColour(215, 215, 83) : wxColour(237, 236, 213);

			Grid* BoardGrid = new Grid(BoardColor, GamePanel, GameSizer, TopLeftRank - Row, TopLeftFile + Col, Col * 8, Row * 8);
			// MainFrame->AddGrid(BoardGrid);
		}
	}

	GamePanel->SetSizer(GameSizer);

	// Add the panels to the Main Frame Sizer
	MainFrameSizer->Add(HeaderPanel, 0, wxEXPAND | wxTOP, 0);
	MainFrameSizer->Add(GamePanel, 1, wxEXPAND | wxBOTTOM, 5);

	MainFrame->SetSizerAndFit(MainFrameSizer);
	MainFrame->SetSizeHints(wxSize(400, 400), wxSize(600, 600));
	MainFrame->Center();
	MainFrame->Show();
	
	return true;
}

