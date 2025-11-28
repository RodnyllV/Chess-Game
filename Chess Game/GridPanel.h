#pragma once

#ifndef GRIDPANEL_H
#define GRIDPANEL_H

#include <wx/wx.h>

class GridPanel : public wxPanel {
	public:
		GridPanel(wxWindow *parent, wxSizer* sizer, const wxColour& backgroundColor);
		void OnSize(wxSizeEvent& event);
		void OnPanelClick(wxMouseEvent& event);
};

GridPanel::GridPanel(wxWindow *parent, wxSizer* sizer, const wxColour& backgroundColor) : wxPanel(parent, wxID_ANY) { 
	Bind(wxEVT_PAINT, &GridPanel::OnPaint, this);
	Bind(wxEVT_SIZE, &GridPanel::OnSize, this);
	
	this->SetBackgroundColour(backgroundColor);
	sizer->Add(this, 1, wxEXPAND);
}

void GridPanel::OnPanelClick(wxMouseEvent& event) {
	// TODO
}

void GridPanel::OnSize(wxSizeEvent &event) {
	Refresh();

	event.Skip();
}

#endif