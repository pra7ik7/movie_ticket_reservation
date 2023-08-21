#pragma once
#include "UserListing.h"
#include"AdminScreen.h"
#include"admin.h"

UserListing::UserListing(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
  
    admin a;
    list = a.users_list();


    wxButton* BackButton = new wxButton(this, wxID_ANY, L"\u2190", wxPoint(10, 10), wxSize(40,20));

    wxFont buttonFont1 = BackButton->GetFont();
    buttonFont1.SetPointSize(15); // Set the desired font size
    BackButton->SetFont(buttonFont1);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* titleLabel = new wxStaticText(this, wxID_ANY, wxT("User Details"),wxDefaultPosition, wxSize(30,30),
    wxALIGN_CENTER_HORIZONTAL);
    wxFont font(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    titleLabel->SetFont(font);
    SetBackgroundColour(wxColour(255, 255, 255));
 
    wxBoxSizer* positionSizer = new wxBoxSizer(wxHORIZONTAL);
    positionSizer->AddSpacer(50); // Vertical space

    wxSize backButtonSize(50, 50); // Set the desired size
    BackButton->SetSize(backButtonSize);


    wxBoxSizer* tableSizer = new wxBoxSizer(wxVERTICAL);

    std::vector<wxString> columnTitles = {"Full Name", "User Name", "Mobile Number", "Email" };

    // Create a horizontal row for the titles
    wxBoxSizer* titleRowSizer = new wxBoxSizer(wxHORIZONTAL);
    for (const wxString& columnTitle : columnTitles) {
        wxStaticText* titleCtrl = new wxStaticText(this, wxID_ANY, columnTitle, wxDefaultPosition, wxDefaultSize);

        // Get the default font
        wxFont font = titleCtrl->GetFont();

        // Set the font weight to bold
        font.SetWeight(wxFONTWEIGHT_BOLD);

        // Apply the modified font to the title control
        titleCtrl->SetFont(font);

        titleRowSizer->Add(titleCtrl, 1, wxALL | wxALIGN_CENTER, 5);
    }
    tableSizer->Add(titleRowSizer, 0, wxALL | wxEXPAND, 0);


    for (const users& user :list) {
        wxBoxSizer* rowSizer = new wxBoxSizer(wxHORIZONTAL);
        wxStaticText* fnameCtrl = new wxStaticText(this, wxID_ANY, user.full_name, wxDefaultPosition, wxDefaultSize);
        wxStaticText* nameCtrl = new wxStaticText(this, wxID_ANY, user.user_name, wxDefaultPosition, wxDefaultSize);
        wxStaticText* mobileCtrl = new wxStaticText(this, wxID_ANY, user.mbl_number, wxDefaultPosition, wxDefaultSize);
        wxStaticText* emailCtrl = new wxStaticText(this, wxID_ANY, user.email, wxDefaultPosition, wxDefaultSize);

        rowSizer->Add(fnameCtrl, 1, wxALL | wxALIGN_CENTER, 8);
        rowSizer->Add(nameCtrl, 1, wxALL | wxALIGN_CENTER, 8);
        rowSizer->Add(mobileCtrl, 1, wxALL | wxALIGN_CENTER, 8);
        rowSizer->Add(emailCtrl, 1, wxALL | wxALIGN_CENTER, 8);

        tableSizer->Add(rowSizer, 0, wxALL | wxEXPAND, 0);
    }
    mainSizer->Add(titleLabel, 0, wxALL | wxEXPAND, 60);
    mainSizer->Add(tableSizer, 1, wxALL | wxEXPAND, 10);
    //mainSizer->Add(BackButton, 0, wxALL | wxEXPAND, 10);
    
    BackButton->Bind(wxEVT_BUTTON, &UserListing::OnBackButtonClicked, this);
    //mainSizer->Add(BackButton, 0, wxALL, 10);


    SetSizerAndFit(mainSizer);

}


void UserListing::OnBackButtonClicked(wxCommandEvent& evt) {
    Close();
    AdminScreen* adminScreen = new AdminScreen("Admin Screen");
    adminScreen->SetClientSize(800, 800);
    adminScreen->Center();
    adminScreen->Show();
}