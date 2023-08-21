#include "movies.h"
#include<vector>
using namespace std;


void movies::savedata()
{
    ofstream save;
    save.open("movies.dat", ios::app | ios::binary);
    save.write((char*)this, sizeof(*this));
    save.close();
}


bool movies::deletemovie(char Moviename[20])
{
    movies m2;
    ifstream movsee;
    movsee.open("movies.dat", ios::in | ios::binary);
    ofstream newmov;
    newmov.open("tem.dat", ios::out | ios::binary);
    while (!movsee.eof())
    {
        if (movsee.read(reinterpret_cast<char*>(&m2), sizeof(m2)).good())
        {
            if (strcmp(m2.m_name, Moviename) != 0)
            {
                newmov.write((char*)&m2, sizeof(m2));
            }
        }
    }
    movsee.close();
    newmov.close();
    remove("movies.dat");
    rename("tem.dat", "movies.dat");
    return true;
}
vector<movies> movies::movies_details()
{
    movies m;
    vector<movies>list;

    ifstream movsee;
    movsee.open("movies.dat", ios::in | ios::binary);
    int c = 0;
    if (movsee)
    {
        while (!movsee.eof())
        {

            if (movsee.read(reinterpret_cast<char*>(this), sizeof(*this)).good())
            {
                list.push_back(*this);
            }
        }
    }
    else {
        list.push_back(m);
    }
    movsee.close();
    return list;
}

int* movies::seatshow(char mstr[]) {
    cout << mstr;
    ifstream movsee;
    movsee.open("movies.dat", ios::in | ios::binary);
    if (movsee)
    {
        int c = 2, count = 2;
        while (!movsee.eof())
        {
            movsee.read((char*)this, sizeof(*this));
            if (strcmp(mstr, m_name) == 0)
            {
                movsee.close();
                return seats;

            }
        }
    }
}