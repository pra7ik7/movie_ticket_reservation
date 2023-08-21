#include<iostream>
#include "SignupFrame.h"
#include<wx/wx.h>
#include"LoginFrame.h"
#include"users.h"
#include"MainMenu.h"
SignupFrame::SignupFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, wxT("User Signup"), wxPoint(370, 60), wxDefaultSize,
		wxALIGN_CENTER_HORIZONTAL);
	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	titleLabel->SetFont(font);

	wxStaticText* NameLabel = new wxStaticText(panel, wxID_ANY, "Name", wxPoint(250, 160));
	nameTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 160), wxSize(200, -1));

	wxStaticText* usernameLabel = new wxStaticText(panel, wxID_ANY, "Username", wxPoint(250, 210));
	usernameTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 210), wxSize(200, -1));

	wxStaticText* emailLabel = new wxStaticText(panel, wxID_ANY, "Email Id", wxPoint(250, 260));
	emailTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 260), wxSize(200, -1));

	wxStaticText* mobilenoLabel = new wxStaticText(panel, wxID_ANY, "Mobile no", wxPoint(250, 310));
	mobilenoTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 310), wxSize(200, -1));

	wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password", wxPoint(250, 360));
	passwordTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 360), wxSize(200, -1), wxTE_PASSWORD);


	wxButton* submitButton = new wxButton(panel, wxID_ANY, "Signup", wxPoint(350, 420), wxSize(100, 35));

	wxStaticText* titleLabel1 = new wxStaticText(panel, wxID_ANY, wxT("or login in if you already have an account"), wxPoint(300, 495), wxDefaultSize);
	wxFont labelfont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	titleLabel1->SetFont(labelfont);

	wxButton* loginButton = new wxButton(panel, wxID_ANY, "Login", wxPoint(350, 520), wxSize(100, 35));

	wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

	wxFont buttonFont1 = BackButton->GetFont();
	buttonFont1.SetPointSize(15); // Set the desired font size
	BackButton->SetFont(buttonFont1);

	BackButton->Bind(wxEVT_BUTTON, &SignupFrame::OnBackButtonClicked, this);

	submitButton->Bind(wxEVT_BUTTON, &SignupFrame::OnSubmitButtonClicked, this);
	loginButton->Bind(wxEVT_BUTTON, &SignupFrame::OnLoginButtonClicked, this);

	CreateStatusBar();
}

void SignupFrame::OnSubmitButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button clicked");
	wxString name = nameTextCtrl->GetValue();
	wxString username = usernameTextCtrl->GetValue();
	wxString emailid = emailTextCtrl->GetValue();
	wxString mobileno = mobilenoTextCtrl->GetValue();
	wxString password = passwordTextCtrl->GetValue();
	char Name[30], Username[20], Emailid[30], Mobileno[20], Password[20];
	strcpy(Name, name.c_str());
	strcpy(Username, username.c_str());
	strcpy(Emailid, emailid.c_str());
	strcpy(Mobileno, mobileno.c_str());
	strcpy(Password, password.c_str());
	if (strcmp(Name, "") == 0|| strcmp(username, "") == 0|| strcmp(emailid, "") == 0|| strcmp(mobileno, "") == 0|| strcmp(Password, "") == 0)
	{
		wxMessageBox("All data must be entered. Re-enter your details", "Error Info", wxOK | wxICON_INFORMATION);
	}
	else
	{
		users u1;
		bool userlogin = u1.newusers(Name, Username, Emailid, Mobileno, Password);
		if (userlogin) {
			wxMessageBox("Signed-up successfully. Press ok to goto main menu", "Login Info", wxOK | wxICON_INFORMATION);
			Close();
			MainMenu* mainMenu = new MainMenu("Movie Ticket Booking System");
			mainMenu->SetClientSize(800, 800);
			mainMenu->Center();
			mainMenu->Show();
		}
		else {
			wxMessageBox("signup failed", "Login Info", wxOK | wxICON_INFORMATION);
		}

		wxLogStatus(username);
	}
}
void SignupFrame::OnLoginButtonClicked(wxCommandEvent& evt) {
	Close();
	LoginFrame* loginFrame = new LoginFrame("Place for signing up");
	loginFrame->SetClientSize(800, 800);
	loginFrame->Center();
	loginFrame->Show();

}
void SignupFrame::OnBackButtonClicked(wxCommandEvent& evt) {
	Close();
	MainMenu* mainMenu = new MainMenu("Movie Ticket Booking System");
	mainMenu->SetClientSize(800, 800);
	mainMenu->Center();
	mainMenu->Show();
}