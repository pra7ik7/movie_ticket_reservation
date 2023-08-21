#pragma once
#include<wx/wx.h>
class SignupFrame :public wxFrame
{
private:
	wxTextCtrl* nameTextCtrl;
	wxTextCtrl* usernameTextCtrl;
	wxTextCtrl* emailTextCtrl;
	wxTextCtrl* mobilenoTextCtrl;
	wxTextCtrl* passwordTextCtrl;
	void OnSubmitButtonClicked(wxCommandEvent& evt);
	void OnLoginButtonClicked(wxCommandEvent& evt);
	void OnBackButtonClicked(wxCommandEvent& evt);
public:
	SignupFrame(const wxString& title);
};