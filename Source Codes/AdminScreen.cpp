#include "AdminScreen.h"
#include<wx/wx.h>
#include"MovieAddFrame.h"
#include"admin.h"
#include"UserListing.h"
#include"CurrentMovieFrame.h"
#include"MainMenu.h"
#include "MovieDeleteFrame.h"


AdminScreen::AdminScreen(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

    wxPanel* panel = new wxPanel(this);

    wxStaticText* titleLabel2 = new wxStaticText(panel, wxID_ANY, wxT("THE ADMIN"), wxPoint(360,60), wxDefaultSize,
        wxALIGN_CENTER_HORIZONTAL);
    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    titleLabel2->SetFont(font);

    MovieAddButton = new wxButton(panel, wxID_ANY, wxT("Add Movies"), wxPoint(350, 150), wxSize(120, 30));
    UserListingButton = new wxButton(panel, wxID_ANY, wxT("User details"), wxPoint(350, 200), wxSize(120, 30));
    CurrentMoviesButton = new wxButton(panel, wxID_ANY, wxT("Current Movies"), wxPoint(350, 250), wxSize(120, 30));
    MovieDeleteButton = new wxButton(panel, wxID_ANY, wxT("Delete Movies"), wxPoint(350,300), wxSize(120, 30));

    // Bind button events
    MovieAddButton->Bind(wxEVT_BUTTON, &AdminScreen::OnMovieAddButtonClicked, this);
    UserListingButton->Bind(wxEVT_BUTTON, &AdminScreen::OnUserListingButtonClicked, this);
    CurrentMoviesButton->Bind(wxEVT_BUTTON, &AdminScreen::OnCurrentMoviesButtonClicked, this);
    MovieDeleteButton->Bind(wxEVT_BUTTON, &AdminScreen::OnMovieDeleteButtonClicked, this);


    wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

    wxFont buttonFont = BackButton->GetFont();
    buttonFont.SetPointSize(15); // Set the desired font size
    BackButton->SetFont(buttonFont);	BackButton->Bind(wxEVT_BUTTON, &AdminScreen::OnBackButtonClicked, this);
    CreateStatusBar();
}

void AdminScreen::OnMovieAddButtonClicked(wxCommandEvent& event) {  //Closes current window and opens login frame
    Close();
    MovieAddFrame* movieAddFrame = new MovieAddFrame("Add Movies");
    movieAddFrame->SetClientSize(800, 800);
    movieAddFrame->Center();
    movieAddFrame->Show();
}

void AdminScreen::OnCurrentMoviesButtonClicked(wxCommandEvent& event) {  //Closes current window and opens movies frame
    wxLogStatus("buttonclicked");
    Close();
    CurrentMovieFrame* currentMovieFrame = new CurrentMovieFrame("Currently playing Movies");
    currentMovieFrame->SetClientSize(800, 800);
    currentMovieFrame->Center();
    currentMovieFrame->Show();
     
}

void AdminScreen::OnUserListingButtonClicked(wxCommandEvent& event) {  //Closes current window and opens userlisting frame
    wxLogStatus("buttonclicked");
    Close();
    UserListing* userListing = new UserListing("User Lists");
    userListing->SetClientSize(800, 800);
    userListing->Center();
    userListing->Show();
}

void AdminScreen::OnMovieDeleteButtonClicked(wxCommandEvent& event) {  //Closes current window and opens login frame
    Close();
    MovieDeleteFrame* movieDeleteFrame = new MovieDeleteFrame("Add Movies");
    movieDeleteFrame->SetClientSize(800, 800);
    movieDeleteFrame->Center();
    movieDeleteFrame->Show();
}

void AdminScreen::OnBackButtonClicked(wxCommandEvent& evt) {
    Close();
    MainMenu* mainMenu = new MainMenu("Movie Ticket Booking System");
    mainMenu->SetClientSize(800, 800);
    mainMenu->Center();
    mainMenu->Show();
}