#include "LoginFrame.h"
#include<wx/wx.h>
#include"SignupFrame.h"
#include"users.h"
#include"MovieListingapp.h"
#include"MainMenu.h"



LoginFrame::LoginFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	//wxPanel* panel = new wxPanel(this);
    panel = new wxPanel(this);


	wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, wxT("User Login"), wxPoint(370,60), wxDefaultSize,
		wxALIGN_CENTER_HORIZONTAL);
	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	titleLabel->SetFont(font);

	wxStaticText* usernameLabel = new wxStaticText(panel, wxID_ANY, "Username", wxPoint(250, 150));
	usernameTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 150), wxSize(200, -1));
	wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password", wxPoint(250, 220));
	passwordTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 220), wxSize(200, -1), wxTE_PASSWORD);

	//wxButton* loginButton = new wxButton(panel, wxID_ANY, "Login", wxPoint(280, 300), wxSize(100, 35));
    loginButton = new wxButton(panel, wxID_ANY, "Login", wxPoint(280, 300), wxSize(100, 35)); // Store loginButton as a member variable
	wxButton* signupButton = new wxButton(panel, wxID_ANY, "Signup", wxPoint(420, 300), wxSize(100, 35));

	wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

	wxFont buttonFont = BackButton->GetFont();
	buttonFont.SetPointSize(15); // Set the desired font size
	BackButton->SetFont(buttonFont);	BackButton->Bind(wxEVT_BUTTON, &LoginFrame::OnBackButtonClicked, this);

	loginButton->Bind(wxEVT_BUTTON, &LoginFrame::OnLoginButtonClicked, this);
	signupButton->Bind(wxEVT_BUTTON, &LoginFrame::OnSignupButtonClicked, this);
	CreateStatusBar();
}

void LoginFrame::OnLoginButtonClicked(wxCommandEvent& evt) {
	wxString username = usernameTextCtrl->GetValue();
	wxString password = passwordTextCtrl->GetValue();
	char Username[20], Password[20];
	strcpy(Username, username.c_str());
	strcpy(Password, password.c_str());
	users u1;
	if (strcmp(Username, "") != 0 || strcmp(Password, "") != 0)
	{
	bool userlogin = u1.authenticate(Username, Password);
		if (userlogin) {
			//wxMessageBox("login successfully", "Login Info", wxOK | wxICON_INFORMATION);
			Close();
			MovieListingapp* movieListingapp = new MovieListingapp("The movie lists");
			movieListingapp->SetClientSize(800, 800);
			movieListingapp->Center();
			movieListingapp->Show();
		}
		else {
			wxMessageBox("Login failed", "Login Info", wxOK | wxICON_INFORMATION);
		}
	}
	else
	{
		wxMessageBox("Login failed.\n You can not have a blank username or password", "Login Info", wxOK | wxICON_INFORMATION);
	}
}


void LoginFrame::OnSignupButtonClicked(wxCommandEvent& evt) {
	Close();
	SignupFrame* signupFrame = new SignupFrame("Place for signing up");
	signupFrame->SetClientSize(800, 800);
	signupFrame->Center();
	signupFrame->Show();
}

void LoginFrame::OnBackButtonClicked(wxCommandEvent& evt) {
	Close();
	MainMenu* mainMenu = new MainMenu("Movie ticket booking system");
	mainMenu->SetClientSize(800, 800);
	mainMenu->Center();
	mainMenu->Show();
}