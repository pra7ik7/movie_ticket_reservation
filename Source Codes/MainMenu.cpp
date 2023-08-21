#include "MainMenu.h"
#include<wx/wx.h>
#include"SignupFrame.h"
#include "LoginFrame.h"
#include"MovieListingapp.h"
#include"adminLogin.h"

MainMenu::MainMenu(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, wxT("THE moviehall"), wxDefaultPosition, wxDefaultSize,
        wxALIGN_CENTER_HORIZONTAL);
    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    titleLabel->SetFont(font);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    loginButton = new wxButton(panel, wxID_ANY, wxT("Login"), wxDefaultPosition, wxSize(120, 30));
    signupButton = new wxButton(panel, wxID_ANY, wxT("Signup"), wxDefaultPosition, wxSize(120, 30));
    adminLoginButton = new wxButton(panel, wxID_ANY, wxT("Admin Login"), wxDefaultPosition, wxSize(120, 30));

    // Bind button events
    loginButton->Bind(wxEVT_BUTTON, &MainMenu::OnLoginButtonClicked, this);
    signupButton->Bind(wxEVT_BUTTON, &MainMenu::OnSignupButtonClicked, this);
    adminLoginButton->Bind(wxEVT_BUTTON, &MainMenu::adminLoginButtonClick, this);

    // Bind mouse events for hover effect
    loginButton->Bind(wxEVT_ENTER_WINDOW, &MainMenu::OnMouseEnterButton, this);
    loginButton->Bind(wxEVT_LEAVE_WINDOW, &MainMenu::OnMouseLeaveButton, this);

    signupButton->Bind(wxEVT_ENTER_WINDOW, &MainMenu::OnMouseEnterButton, this);
    signupButton->Bind(wxEVT_LEAVE_WINDOW, &MainMenu::OnMouseLeaveButton, this);

    adminLoginButton->Bind(wxEVT_ENTER_WINDOW, &MainMenu::OnMouseEnterButton, this);
    adminLoginButton->Bind(wxEVT_LEAVE_WINDOW, &MainMenu::OnMouseLeaveButton, this);

    buttonSizer->Add(loginButton, 0, wxALL, 30);
    buttonSizer->Add(signupButton, 0, wxALL, 30);
    buttonSizer->Add(adminLoginButton, 0, wxALL, 30);

    mainSizer->Add(titleLabel, 0, wxALIGN_CENTER | wxALL, 30);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxALL, 20);

    panel->SetSizerAndFit(mainSizer);
}


void MainMenu::OnLoginButtonClicked(wxCommandEvent& event) {  //Closes current window and opens login frame
    Close();
    LoginFrame* loginFrame = new LoginFrame("Login to reserve seats");
    loginFrame->SetClientSize(800, 800);
    loginFrame->Center();
    loginFrame->Show();
}

void MainMenu::OnSignupButtonClicked(wxCommandEvent& event) {   //Closes current window and opens signup frame
    Close();
    SignupFrame* signupFrame = new SignupFrame("Place for signing up");
    signupFrame->SetClientSize(800, 800);
    signupFrame->Center();
    signupFrame->Show();
}

void MainMenu::adminLoginButtonClick(wxCommandEvent& event) {     //Closes current window and opens admin login frame
   // wxMessageBox(wxT("Book Seat button clicked!"), wxT("Info"), wxOK | wxICON_INFORMATION, this);

    Close();
    adminLogin* AdminLogin = new adminLogin("The wall to control the system");
    AdminLogin->SetClientSize(800, 800);
    AdminLogin->Center();
    AdminLogin->Show();
}

void MainMenu::OnMouseEnterButton(wxMouseEvent& event) {
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    if (button) {
        button->SetBackgroundColour(wxColour(200, 200, 200)); // Change background color on hover
        button->Refresh();
    }
}

void MainMenu::OnMouseLeaveButton(wxMouseEvent& event) {
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    if (button) {
        button->SetBackgroundColour(wxNullColour); // Restore original background color
        button->Refresh();
    }
}