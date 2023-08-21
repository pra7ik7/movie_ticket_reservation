#include "users.h"
bool users::newusers(char full_names[], char user_names[], char emails[], char mbl_numbers[], char pws[])
{
    strcpy(full_name, full_names);
    strcpy(user_name, user_names);
    strcpy(email, emails);
    strcpy(mbl_number, mbl_numbers);
    strcpy(pw, pws);
    ofstream cppfile;
    cppfile.open("users.dat", ios::app | ios::binary);
    fflush(stdin);
    if (cppfile.write(reinterpret_cast<char*>(this), sizeof(*this)))
        return true;
    else
        return false;
    cppfile.close();
}

bool users::authenticate(char tempname[], char temppw[])
{
    movies m1;
    ifstream in;
    in.open("users.dat", ios::in | ios::binary);
    while (!in.eof())
    {
        if (in.read(reinterpret_cast<char*>(this), sizeof(*this)).good())
        {
            if (strcmp(tempname, user_name) == 0 && strcmp(temppw, pw) == 0)
            {
                in.close();
                return true;
            }
        }
    }
    return false;
}
void users::selection(char mstr[], std::vector<int>seats)
{
    movies m1;
    int temp, count = 0, c = 0, tktnum = 0;
    fstream save;
    save.open("movies.dat", ios::in | ios::out | ios::binary);
    ofstream temp_fp;
    temp_fp.open("temp.dat", ios::out | ios::binary);
    while (!save.eof())
    {
        if (save.read(reinterpret_cast<char*>(&m1), sizeof(m1)).good())
        {
            if (strcmp(mstr, m1.m_name) == 0)
            {
                for (int i = 0; i < seats.size(); i++)
                {
                    temp = seats[i];
                    if (m1.seats[temp - 1])
                    {
                        m1.seats[temp - 1] = 0;
                    }
                }
            }
            temp_fp.write((char*)&m1, sizeof(m1));
        }
    }
    save.close();
    temp_fp.close();
    remove("movies.dat");
    if (rename("temp.dat", "movies.dat"));
}