#pragma once
#include<wx/wx.h>

class MainMenu :public wxFrame
{

private:
	wxButton* loginButton;
	wxButton* signupButton;
	wxButton* adminLoginButton;
	void OnLoginButtonClicked(wxCommandEvent& evt);
	void OnSignupButtonClicked(wxCommandEvent& evt);
	void adminLoginButtonClick(wxCommandEvent& event);
	void OnMouseEnterButton(wxMouseEvent& event);
	void OnMouseLeaveButton(wxMouseEvent& event);

public:
	MainMenu(const wxString& title);

};


