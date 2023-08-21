#pragma once
#include <wx/wx.h>
#include <vector>
#include"movies.h"

class MovieListingapp : public wxFrame {
public:
    MovieListingapp(const wxString& title);




private:
    std::vector<movies>list;
    std::vector<wxButton*> movieButtons;
    void OnMovieButtonClick(wxCommandEvent& event);
    void OnBackButtonClicked(wxCommandEvent& evt);
};

