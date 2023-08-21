#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include <cstring>
#include<cstdio>

class movies
{
public:
    movies()
    {
        strncpy(m_name, "", sizeof(m_name));
        strncpy(duration, "", sizeof(duration));
        strncpy(release_date, "", sizeof(release_date));
        strncpy(price, "", sizeof(price));
        for (int i = 0; i < 50; i++)
            seats[i] = 1;
    }
    movies(char Moviename[20], char Duration[20], char Releasedate[20], char Price[20])
    {
        strcpy(m_name, Moviename);
        strcpy(duration, Duration);
        strcpy(release_date, Releasedate);
        strcpy(price, Price);
        for (int i = 0; i < 50; i++)
        seats[i] = 1;
    }

    int seats[50];
    char m_name[20], release_date[20];
    char price[20], duration[20];

public:
    void savedata();
    bool deletemovie(char Moviename[20]);
    std::vector<movies> movies_details();
    int* seatshow(char a[]);
};

