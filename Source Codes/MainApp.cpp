#pragma once
#include "MainApp.h"
#include"MainMenu.h"
#include<wx/wx.h>

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit() {
	MainMenu* mainMenu = new MainMenu("Movie Ticket Booking System");
	mainMenu->SetClientSize(800, 800);
	mainMenu->Center();
	mainMenu->Show();
	return true;
}