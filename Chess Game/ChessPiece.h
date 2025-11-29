#pragma once

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <wx/wx.h>
#include "Grid.h"

char ranks[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
char files[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };

class ChessPanel : public wxPanel {
public:
    ChessPanel(wxWindow* parent, wxSizer* sizer, const wxColour& pieceColor);
};

class ChessPiece {
private:
    wxColour color;
    char player;
    char* position;
    char* img;
    wxPanel* GUI;

    Grid* moveableGrids;
public:
    virtual void SetPositionParams() = 0;
    virtual void Move() = 0;

    ChessPiece(wxWindow* parent, wxColour& color, char player, char* position);



    void OnSelected();
    void Eliminate(ChessPiece* opponent);
    void SetAppearance(std::string path);

    int GetRank();
    int GetFile();

    ~ChessPiece();
};

ChessPiece::ChessPiece(wxWindow* parent, wxColour& color, char player, char* position) {
    this->color = color;
    this->player = player;
    this->position = position;
    this->moveableGrids = nullptr;
    this->GUI = new wxPanel(parent, wxID_ANY);
}

void ChessPiece::SetAppearance(std::string path) {
    wxBitmap PieceBitmap(wxString(path), wxBITMAP_TYPE_PNG);
    wxStaticBitmap* StaticBitmap = new wxStaticBitmap(this->GUI, wxID_ANY, PieceBitmap, wxPoint(0, 0), wxDefaultSize);
    wxBoxSizer* PieceSizer = new wxBoxSizer(wxVERTICAL);
    PieceSizer->Add(StaticBitmap, 1, wxALL, 3);
    this->GUI->SetSizer(PieceSizer);
    PieceSizer->Fit(this->GUI->GetParent());
}

void ChessPiece::OnSelected() {
    SetPositionParams();

    // TODO
}

int ChessPiece::GetRank() {
    for (int i = 0; i < 8; i++) {
        if (ranks[i] == position[0]) {
            return i;
        }
    }

    return -1;
}

int ChessPiece::GetFile() {
    for (int i = 0; i < 8; i++) {
        if (files[i] == position[1]) {
            return i;
        }
    }

    return -1;
}

void ChessPiece::Eliminate(ChessPiece* opponent) {
    if (position == opponent->position) {
        delete opponent;
        opponent = nullptr;
    }
}

ChessPiece::~ChessPiece() {
    delete[] img;
}

#endif#pragma once
