#include "MovieDeleteFrame.h"
#include <wx/wx.h>
#include "AdminScreen.h"
#include "movies.h"


MovieDeleteFrame::MovieDeleteFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, wxT("Movie Delete"), wxPoint(370, 60), wxDefaultSize,
		wxALIGN_CENTER_HORIZONTAL);
	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	titleLabel->SetFont(font);

	wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText* NameLabel = new wxStaticText(panel, wxID_ANY, "Movie Name", wxPoint(280, 220));
	movienameTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(370, 220), wxSize(200, -1));

	wxButton* deleteButton = new wxButton(panel, wxID_ANY, "Delete", wxPoint(370, 320), wxSize(100, 35));
	deleteButton->Bind(wxEVT_BUTTON, &MovieDeleteFrame::OnDeleteButtonClicked, this);

	wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

	wxFont buttonFont = BackButton->GetFont();
	buttonFont.SetPointSize(15); // Set the desired font size
	BackButton->SetFont(buttonFont);	
	BackButton->Bind(wxEVT_BUTTON, &MovieDeleteFrame::OnBackButtonClicked, this);
	panel->SetSizerAndFit(boxSizer);
	CreateStatusBar();
}

void MovieDeleteFrame::OnDeleteButtonClicked(wxCommandEvent& evt) {
	wxString moviename = movienameTextCtrl->GetValue();;

	char Moviename[20];
	strcpy(Moviename, moviename.c_str());

	movies m;
	if (m.deletemovie(Moviename))
	{
		wxMessageBox("Movie deleted", "Movie info", wxOK | wxICON_INFORMATION);
		Close();
		AdminScreen* adminScreen = new AdminScreen("Admin Screen");
		adminScreen->SetClientSize(800, 800);
		adminScreen->Center();
		adminScreen->Show();
	}
	else
	{
		wxMessageBox("Error: Movie not deleted", "Movie info", wxOK | wxICON_INFORMATION);
	}
}

void MovieDeleteFrame::OnBackButtonClicked(wxCommandEvent& evt) {
	Close();
	AdminScreen* adminScreen = new AdminScreen("Admin Screen");
	adminScreen->SetClientSize(800, 800);
	adminScreen->Center();
	adminScreen->Show();
}