#pragma once
#include <iostream>
#include <fstream>
#include "users.h"
#include<cstdio>

using namespace std;
class admin : public movies
{
public:
    admin(){}
    //void updatemov();
    std::vector<users>users_list();
    //void adminscreen();
    bool alogin(char u[], char p[]);
};