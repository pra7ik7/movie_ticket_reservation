#pragma once
#include<wx/wx.h>

class MovieAddFrame:public wxFrame
{
private:
	wxTextCtrl* movienameTextCtrl;
	wxTextCtrl* durationTextCtrl;
	wxTextCtrl* releasedateTextCtrl;
	wxTextCtrl* priceTextCtrl;
	void OnBackButtonClicked(wxCommandEvent& evt);
	void OnSubmitButtonClicked(wxCommandEvent& evt);
public:
	MovieAddFrame(const wxString& title);

};