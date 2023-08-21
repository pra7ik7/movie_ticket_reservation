#include "adminLogin.h"
#include<wx/wx.h>
#include"AdminScreen.h"
#include"admin.h"
#include"MovieListingapp.h"
#include"MainMenu.h"

adminLogin::adminLogin(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, wxT("Admin Login"), wxPoint(370, 60), wxDefaultSize,
		wxALIGN_CENTER_HORIZONTAL);
	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	titleLabel->SetFont(font);

	wxStaticText* usernameLabel = new wxStaticText(panel, wxID_ANY, "Username", wxPoint(250, 150));
	usernameTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 150), wxSize(200, -1));
	wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password", wxPoint(250, 220));
	passwordTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 220), wxSize(200, -1), wxTE_PASSWORD);


	wxButton* submitButton = new wxButton(panel, wxID_ANY, "Login", wxPoint(365, 305), wxSize(100, 35));

	wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

	wxFont buttonFont = BackButton->GetFont();
	buttonFont.SetPointSize(15); // Set the desired font size
	BackButton->SetFont(buttonFont);

	submitButton->Bind(wxEVT_BUTTON, &adminLogin::OnLoginButtonClicked, this);
	BackButton->Bind(wxEVT_BUTTON, &adminLogin::OnBackButtonClicked, this);
	CreateStatusBar();
}

void adminLogin::OnLoginButtonClicked(wxCommandEvent& evt) {
	
	wxString username = usernameTextCtrl->GetValue();
	wxString password = passwordTextCtrl->GetValue();
	char Username[20], Password[20];
	strcpy(Username, username.c_str());
	strcpy(Password, password.c_str());
	//calls alogin function of admin for authentication
	admin a1;
	bool Adminlogin = a1.alogin(Username, Password);
	if (Adminlogin) {
		//wxMessageBox("Logged-in successfully", "Login Info", wxOK | wxICON_INFORMATION);
		Close();
		AdminScreen* adminScreen = new AdminScreen("THE ADMINISTRATOR");
		adminScreen->SetClientSize(800, 800);
		adminScreen->Center();
		adminScreen->Show();
	}
	else {
		wxMessageBox("login failed", "Login Info", wxOK | wxICON_INFORMATION);
	}
}
void adminLogin::OnBackButtonClicked(wxCommandEvent& evt) {
	Close();
	MainMenu* mainMenu = new MainMenu("Movie Ticket Booking System");
	mainMenu->SetClientSize(800, 800);
	mainMenu->Center();
	mainMenu->Show();
}