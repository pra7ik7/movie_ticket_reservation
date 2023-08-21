#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include<cstdio>
#include "movies.h"

using namespace std;

class users : public movies
{
public:
    users(){}
    //{
    //    strncpy(full_name, "", sizeof(full_name));
    //    strncpy(user_name, "", sizeof(user_name));
    //    strncpy(email, "", sizeof(email));
    //    strncpy(mbl_number, "", sizeof(mbl_number));
    //    strncpy(pw, "", sizeof(pw));
    //}
    char full_name[30], user_name[20], email[30], mbl_number[20], pw[20];
    friend class admin;
    bool newusers(char full_names[], char user_names[], char emails[], char mbl_numbers[], char pws[]);
    bool authenticate(char tempname[], char user_name[]);
    void selection(char mstr[], std::vector<int>seats);
};