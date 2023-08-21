#pragma once
#include<wx/wx.h>

class adminLogin :public wxFrame
{
private:
	wxTextCtrl* usernameTextCtrl;
	wxTextCtrl* passwordTextCtrl;
	void OnLoginButtonClicked(wxCommandEvent& evt);
	void OnBackButtonClicked(wxCommandEvent& evt);

public:
	adminLogin(const wxString& title);
};
