#pragma once
#include<wx/wx.h>
#include<iostream>
#include<vector>
#include<string>
#include"movies.h"
#include"users.h"

class BookSeats :public wxFrame
{
public:
	BookSeats(const wxString& title, movies list,std::string);

private:
	movies m;
	int count = 0;
	int* seats;
	int list[48];
	string userrole;
	std::vector<int>seatsbooked;
	std::vector<wxButton*> seatButtons;
	void OnBookSeatsButtonClick(wxCommandEvent& event);
	void OnBookButtonClick(wxCommandEvent& event);
	void OnBackButtonClicked(wxCommandEvent& event);
};
