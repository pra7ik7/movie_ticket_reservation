#pragma once
#include<wx/wx.h>

class MovieDeleteFrame :public wxFrame
{
private:
	wxTextCtrl* movienameTextCtrl;
	void OnBackButtonClicked(wxCommandEvent& evt);
	void OnDeleteButtonClicked(wxCommandEvent& evt);
public:
	MovieDeleteFrame(const wxString& title);
};

