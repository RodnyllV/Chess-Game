#pragma once

#ifndef FRAME_H
#define FRAME_H

#include <wx/wx.h>
#include "Grid.h"

class Frame : public wxFrame {
	private:
		void OnSize(wxSizeEvent& event);
		int TotalGrids;
		Grid* Grids;
	public:
		Frame(const wxString& title);
		void AddGrid(Grid* grid);
};

Frame::Frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 800)) {
	Bind(wxEVT_SIZE, &Frame::OnSize, this);
}

void Frame::AddGrid(Grid* grid) {
	Grid* NewGrids = new Grid[++TotalGrids];

	for (int i = 0; i < TotalGrids - 1; i++) {
		NewGrids[i] = Grids[i];
	}

	NewGrids[TotalGrids - 1] = *grid;
	delete[] Grids;

	Grids = NewGrids;
}

void Frame::OnSize(wxSizeEvent &event) {
	wxSize NewSize = event.GetSize();
	wxSize Size = GetSize();

	int WidthDiff = abs(NewSize.GetWidth() - Size.GetWidth());
	int HeightDiff = abs(NewSize.GetHeight() - Size.GetHeight());

	if (WidthDiff > HeightDiff) {
		this->SetSize(NewSize.GetWidth(), NewSize.GetWidth());
	} else {
		this->SetSize(NewSize.GetHeight(), NewSize.GetHeight());
	}

	event.Skip();
}

#endif
