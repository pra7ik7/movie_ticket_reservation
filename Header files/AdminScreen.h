#pragma once
#include<wx/wx.h>
class AdminScreen :public wxFrame
{
	private:
		wxButton* MovieAddButton;
		wxButton* UserListingButton;
		wxButton* CurrentMoviesButton;
		wxButton* MovieDeleteButton;
		void OnMovieAddButtonClicked(wxCommandEvent& evt);
		void OnUserListingButtonClicked(wxCommandEvent& evt);
		void OnCurrentMoviesButtonClicked(wxCommandEvent& event);
		void OnMovieDeleteButtonClicked(wxCommandEvent& event);
		void OnBackButtonClicked(wxCommandEvent& evt);
public:
	AdminScreen(const wxString& title);
};

