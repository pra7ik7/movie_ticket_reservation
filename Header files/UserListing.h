#pragma once
#include <wx/wx.h>
#include <vector>
#include"users.h"

class UserListing : public wxFrame
{
    public:
        UserListing(const wxString& title);

    private:
        std::vector<users>list;
        void OnBackButtonClicked(wxCommandEvent& evt);
};