#include "BookSeats.h"
#include<wx/wx.h>
#include<vector>
#include"MovieListingapp.h"
#include"CurrentMovieFrame.h"
#include"movies.h"


BookSeats::BookSeats(const wxString& title, movies movie,std::string role="user") :wxFrame(nullptr, wxID_ANY, title) {
    m = movie;
    userrole = role;
    wxPanel* panel = new wxPanel(this);

    wxButton* BackButton = new wxButton(panel, wxID_ANY, L"\u2190", wxPoint(50, 60), wxSize(55, 35));

    wxFont buttonFont = BackButton->GetFont();
    buttonFont.SetPointSize(15); // Set the desired font size
    BackButton->SetFont(buttonFont);    BackButton->Bind(wxEVT_BUTTON, &BookSeats::OnBackButtonClicked, this);

    wxStaticText* nameLabel = new wxStaticText(panel, wxID_ANY, "Movie Name:", wxPoint(280, 30));
    wxStaticText* nameLabel1 = new wxStaticText(panel, wxID_ANY, movie.m_name);

    wxStaticText* releaseLabel1 = new wxStaticText(panel, wxID_ANY, "Release Date:", wxPoint(280, 47));
    wxStaticText* releaseLabel = new wxStaticText(panel, wxID_ANY, movie.release_date);

    wxStaticText* priceLabel1 = new wxStaticText(panel, wxID_ANY, "Ticket Price:", wxPoint(280,64));
    wxStaticText* priceLabel = new wxStaticText(panel, wxID_ANY, movie.price);

    wxStaticText* durationLabel1 = new wxStaticText(panel, wxID_ANY, "Duration(in min):", wxPoint(280, 79));
    wxStaticText* durationLabel = new wxStaticText(panel, wxID_ANY, movie.duration);

    wxStaticText* durationLabel2 = new wxStaticText(panel, wxID_ANY, "---------------------------------------------------------------------------------------------", wxPoint(166, 74));

    wxStaticText* durationLabel3 = new wxStaticText(panel, wxID_ANY, "SCREEN", wxPoint(480, 50));
    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    durationLabel3->SetFont(font);


    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    int boxSize = 450;

    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    boxSizer->SetMinSize(wxSize(boxSize, boxSize));

    int numRows = 8;
    int numCols = 6;
    int i = 1;

    std::string moviename = movie.m_name;
    char* movieName = const_cast<char*>(moviename.data());
    movies m;
    seats = m.seatshow(movieName);
    for (int j = 0; j < 48; j++) {
        list[j] = seats[j];
    }

    wxGridSizer* gridSizer = new wxGridSizer(numRows, numCols, 5, 5);
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {

            //change color of booked seats

            wxButton* seatButton = new wxButton(panel, wxID_ANY, wxString::Format("%d", i));

            if (!seats[i - 1]) {
                seatButton->SetBackgroundColour(wxColour(255, 0, 0));
            }
            else {
                seatButton->SetBackgroundColour(wxColour(0, 255, 0));
            }
            seatButton->Bind(wxEVT_BUTTON, &BookSeats::OnBookSeatsButtonClick, this);
            gridSizer->Add(seatButton, 0, wxEXPAND);
            seatButtons.push_back(seatButton);
            i++;
        }
    }
 
    mainSizer->Add(30, 30);
    mainSizer->Add(nameLabel1, 0, wxALIGN_CENTER_HORIZONTAL);
    mainSizer->Add(releaseLabel, 0, wxALIGN_CENTER_HORIZONTAL);
    mainSizer->Add(priceLabel, 0, wxALIGN_CENTER_HORIZONTAL);
    mainSizer->Add(durationLabel, 0, wxALIGN_CENTER_HORIZONTAL);
    mainSizer->Add(durationLabel2, 0, wxALIGN_CENTER_HORIZONTAL);
    mainSizer->Add(durationLabel3, 0, wxALIGN_CENTER_HORIZONTAL);


    boxSizer->Add(gridSizer, 1, wxEXPAND);
    mainSizer->Add(boxSizer, 1, wxALIGN_CENTER | wxALL, 20);
    
    if (userrole != "admin") {
        wxButton* bookButton = new wxButton(panel, wxID_ANY, wxT("Book Seats"), wxDefaultPosition, wxDefaultSize, wxBU_LEFT);
        bookButton->Bind(wxEVT_BUTTON, &BookSeats::OnBookButtonClick, this);
        mainSizer->Add(bookButton, 0, wxALIGN_CENTER | wxBottom, 20);

    }

    panel->SetSizer(mainSizer);
}

void BookSeats::OnBookSeatsButtonClick(wxCommandEvent& event) {
    if (userrole != "admin") {
        wxButton* seatButton = dynamic_cast<wxButton*>(event.GetEventObject());
        wxString seatBooked = seatButton->GetLabel();
        long seatvalue;
        seatBooked.ToLong(&seatvalue);
        int j = seatvalue;

        if (seatButton) {
            if (!list[j - 1]) {
                wxMessageBox("Already booked. Please select the available ones.", wxT("Booking Confirmation"), wxOK | wxICON_INFORMATION);
                return;
            }
            if (seatButton->GetBackgroundColour() == wxColour(255, 0, 0)) {
                seatButton->SetBackgroundColour(wxColour(0, 255, 0));
                seatsbooked.erase(std::remove(seatsbooked.begin(), seatsbooked.end(), seatvalue), seatsbooked.end());
            }
            else {
                seatsbooked.push_back(seatvalue);
                seatButton->SetBackgroundColour(wxColour(255, 0, 0));
            }
            seatButton->Refresh();
        }
    }
   
}
void BookSeats::OnBookButtonClick(wxCommandEvent& event) {

    users u1;
    u1.selection(m.m_name, seatsbooked);
    wxString totalseats;
    for (int i = 0; i < seatsbooked.size(); ++i) {
        totalseats += wxString::Format("%d ", seatsbooked[i]);
    }
    int intValue = wxAtoi(m.price); // Convert char array to int using wxAtoi

    // Calculate the total price
    int totalPrice = seatsbooked.size() * intValue;

    // Convert totalPrice to wxString
    wxString wxStringTotalPrice = wxString::Format(wxT("%d"), totalPrice);

    // Create and display the message box
    wxString message = wxT("Seats booked: ") + totalseats + wxT("\nTotal Price: ") + wxStringTotalPrice;
    wxMessageBox(message, wxT("Booking Confirmation"), wxOK | wxICON_INFORMATION);
 /*   int intValue = std::atoi(m.price);
    wxString wxStringInteger = wxString::Format(wxT("%d"), (seatsbooked.size() * intValue));
    wxMessageBox("Seats booked:  " + totalseats + "\nTotal Price:" + wxStringInteger, wxT("Booking Confirmation"), wxOK | wxICON_INFORMATION);*/
    Close();
    MovieListingapp* movieListingapp = new MovieListingapp("The movie lists");
    movieListingapp->SetClientSize(800, 800);
    movieListingapp->Center();
    movieListingapp->Show();
}

void BookSeats::OnBackButtonClicked(wxCommandEvent& evt) {
    if (userrole == "user")
    {
        Close();
        MovieListingapp* mainMenu = new MovieListingapp("The movie lists");
        mainMenu->SetClientSize(800, 800);
        mainMenu->Center();
        mainMenu->Show();
    }
    if (userrole == "admin")
    {
        Close();
        CurrentMovieFrame* currentMovieFrame = new CurrentMovieFrame("The movie lists");
        currentMovieFrame->SetClientSize(800, 800);
        currentMovieFrame->Center();
        currentMovieFrame->Show();
    }
}