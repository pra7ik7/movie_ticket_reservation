#include "admin.h"
using namespace std;

bool admin::alogin(char username[], char pw[])
{
    if (!strcmp(username,"MTBS") && !strcmp(pw,"1234"))
        return true;

    return false;
}
vector<users> admin::users_list()
{
    vector<users>list;
    users u;
    int ch;
    ifstream in;
    in.open("users.dat", ios::in | ios::binary);
    if (in)
    {
        while (!in.eof())
        {
            if (in.read(reinterpret_cast<char*>(&u), sizeof(u)).good())
            {
                list.push_back(u);
            }
            else
                break;
        }
    }
    in.close();
    return list;
}