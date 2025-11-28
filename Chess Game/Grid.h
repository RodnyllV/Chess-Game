#pragma once

#ifndef GRID_H
#define GRID_H

#include "ChessPiece.h"
#include "GridPanel.h"

const int GridRoot = 8;

class Grid {
    private: 
        wxColour color;
        ChessPiece* piece;
        char rank;
        char file;
        bool highlighted;
        GridPanel* square;
    public:
        Grid();
        Grid(const wxColour& color, wxPanel* parent, wxSizer* sizer, char rank, char file, int x, int y);

        char GetRank() const;
        char GetFile() const;
        void SetRank(const char &rank);
        void SetFile(const char &file);

        void Highlight(bool highlighted);
        void SetPiece(ChessPiece* piece);
};

Grid::Grid() {
    this->highlighted = false;
    this->piece = nullptr;
    this->square = nullptr;
}

Grid::Grid(const wxColour& color, wxPanel* parent, wxSizer* sizer, char rank, char file, int x, int y) {
    this->color = color;
    this->rank = rank;
    this->file = file;
    this->highlighted = false;
    this->piece = nullptr;

    // Grid Appearance
	wxSize PanelSize = parent->GetSize();

	this->square = new GridPanel(parent, sizer, color);
}

char Grid::GetRank() const {
    return this->rank;
}

char Grid::GetFile() const {
    return this->file;
}

void Grid::SetRank(const char &rank) {
	if (rank >= 'a' && rank < 'i') {
        this->rank = rank;
    }
}

void Grid::SetFile(const char& file) {
    if (file > '1' && file < '9') {
        this->file = file;
	}
}

void Grid::Highlight(bool highlighted) {
	this->highlighted = highlighted;

    if (highlighted) {
        if (this->piece != nullptr) {
            // TODO
        } else {
            // TODO
        }
    } else {
        // TODO
    }
}

void Grid::SetPiece(ChessPiece* piece) {
    this->piece = piece;
}

#endif