#include "CurrentMovieFrame.h"
#include<wx/wx.h>
#include"BookSeats.h"
#include<vector>
#include"AdminScreen.h"

CurrentMovieFrame::CurrentMovieFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

        wxPanel* panel = new wxPanel(this, wxID_ANY);

        wxStaticText* titleLabel2 = new wxStaticText(panel, wxID_ANY, wxT("Movies"), wxPoint(360, 60), wxDefaultSize,
            wxALIGN_CENTER_HORIZONTAL);
        wxFont font(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        titleLabel2->SetFont(font);

        wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

        boxSizer->Add(titleLabel2, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 20);

        movies m;
        list = m.movies_details();
        size_t size = list.size();
        for (size_t i = 0; i < size; ++i) {
            wxButton* movieButton = new wxButton(panel, wxID_ANY, list[i].m_name);

            // Increase the font size for the button label
            wxFont buttonFont = movieButton->GetFont();
            buttonFont.SetPointSize(12); // You can adjust the font size as needed
            movieButton->SetFont(buttonFont);

            // Set the size of the movie button
            movieButton->SetMinSize(wxSize(200, 100)); // Adjust the dimensions as needed

            movieButton->Bind(wxEVT_BUTTON, &CurrentMovieFrame::OnMovieButtonClick, this);
            boxSizer->Add(movieButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 30);
            movieButtons.push_back(movieButton);
        }
        wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

        wxFont buttonFont1 = BackButton->GetFont();
        buttonFont1.SetPointSize(15); // Set the desired font size
        BackButton->SetFont(buttonFont1);

        BackButton->Bind(wxEVT_BUTTON, &CurrentMovieFrame::OnBackButtonClicked, this);
        panel->SetSizerAndFit(boxSizer);
        CreateStatusBar(); 
}

void CurrentMovieFrame::OnMovieButtonClick(wxCommandEvent& event) {
    wxButton* movieButton = dynamic_cast<wxButton*>(event.GetEventObject());
    if (movieButton) {
        int movieIndex = -1;
        for (size_t i = 0; i < movieButtons.size(); ++i) {
            if (movieButton == movieButtons[i]) {
                movieIndex = i;
                break;
            }
        }

        if (movieIndex != -1) {
            movies selectedmovie = list[movieIndex];
            Close();
            BookSeats* bookSeats = new BookSeats("Seat Reserver", selectedmovie,"admin");
            bookSeats->SetClientSize(800, 800);
            bookSeats->Center();
            bookSeats->Show();

        }
    }
}
void CurrentMovieFrame::OnBackButtonClicked(wxCommandEvent& evt) {
    Close();
    AdminScreen* adminScreen = new AdminScreen("Admin Screen");
    adminScreen->SetClientSize(800, 800);
    adminScreen->Center();
    adminScreen->Show();
}