#pragma once
#include<wx/wx.h>
#include"movies.h"

class CurrentMovieFrame:public wxFrame
{
private:
    std::vector<movies>list;
    std::vector<wxButton*> movieButtons;
    void OnMovieButtonClick(wxCommandEvent& event);
    void OnBackButtonClicked(wxCommandEvent& evt);
public:
	CurrentMovieFrame(const wxString& title);
};

