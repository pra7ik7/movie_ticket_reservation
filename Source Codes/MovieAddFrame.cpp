#include "MovieAddFrame.h"
#include <wx/wx.h>
#include"AdminScreen.h"
#include"movies.h"

MovieAddFrame::MovieAddFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, wxT("Add Movies"), wxPoint(370, 60), wxDefaultSize,
		wxALIGN_CENTER_HORIZONTAL);
	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	titleLabel->SetFont(font);

    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText* NameLabel = new wxStaticText(panel, wxID_ANY, "Name", wxPoint(250, 220));
	movienameTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 220), wxSize(200, -1));

	wxStaticText* usernameLabel = new wxStaticText(panel, wxID_ANY, "Duration", wxPoint(250, 255));
	durationTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 255), wxSize(200, -1));

	wxStaticText* emailLabel = new wxStaticText(panel, wxID_ANY, "Release Date", wxPoint(250, 285));
	releasedateTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 285), wxSize(200, -1));

	wxStaticText* mobilenoLabel = new wxStaticText(panel, wxID_ANY, "Price", wxPoint(250, 320));
	priceTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(320, 320), wxSize(200, -1));

	wxButton* submitButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(360, 420), wxSize(100, 35));
	submitButton->Bind(wxEVT_BUTTON, &MovieAddFrame::OnSubmitButtonClicked, this);

	wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

	wxFont buttonFont = BackButton->GetFont();
	buttonFont.SetPointSize(15); // Set the desired font size
	BackButton->SetFont(buttonFont);    BackButton->Bind(wxEVT_BUTTON, &MovieAddFrame::OnBackButtonClicked, this);
    panel->SetSizerAndFit(boxSizer);
    CreateStatusBar();
}
void MovieAddFrame::OnSubmitButtonClicked(wxCommandEvent& evt) {
	wxString moviename = movienameTextCtrl->GetValue();
	wxString duration = durationTextCtrl->GetValue();
	wxString releasedate = releasedateTextCtrl->GetValue();
	wxString price = priceTextCtrl->GetValue();

	char Moviename[20], Duration[20], Releasedate[20], Price[20];
	strcpy(Moviename, moviename.c_str());
	strcpy(Duration, duration.c_str());
	strcpy(Releasedate, releasedate.c_str());
	strcpy(Price, price.c_str());
    
	movies m(Moviename, Duration, Releasedate, Price);
	m.savedata();
	wxMessageBox("Movie Saved successfully", "Movie info", wxOK | wxICON_INFORMATION);
	Close();
	AdminScreen* adminScreen = new AdminScreen("Admin Screen");
	adminScreen->SetClientSize(800, 800);
	adminScreen->Center();
	adminScreen->Show();
}

void MovieAddFrame::OnBackButtonClicked(wxCommandEvent& evt) {
	Close();
	AdminScreen* adminScreen = new AdminScreen("Admin Screen");
	adminScreen->SetClientSize(800, 800);
	adminScreen->Center();
	adminScreen->Show();
}