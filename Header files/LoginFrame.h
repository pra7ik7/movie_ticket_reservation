#pragma once
#include<wx/wx.h>
#include <wx/timer.h>
class LoginFrame :public wxFrame
{
private:
	wxTextCtrl* usernameTextCtrl;
	wxTextCtrl* passwordTextCtrl;
	void OnLoginButtonClicked(wxCommandEvent& evt);
	void OnSignupButtonClicked(wxCommandEvent& evt);
	void OnBackButtonClicked(wxCommandEvent& evt);

	wxButton* loginButton;
	wxPanel* panel;
public:
	LoginFrame(const wxString& title);

};


