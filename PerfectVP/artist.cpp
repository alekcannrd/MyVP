#include "artist.h"



Artist::Artist(){}

Artist::Artist(string name, string surname, int age, string login, string password): User(name, surname,age,login,password)
{

}

bool Artist::operator>(Artist &b)
{
    return (m_iNumOfAuditions>b.m_iNumOfAuditions);
}

bool Artist::operator<(Artist &b)
{
    return (m_iNumOfAuditions<b.m_iNumOfAuditions);
}

istream &operator>>(istream &in, Artist &artist)
{
    cout << "Input name: ";
    in >> artist.m_strName;
    cout << "Input surname: ";
    in >> artist.m_strSurname;
    cout << "Input age: ";
    in >> artist.m_iAge;
    cout << "Input login: ";
    in >> artist.m_strLogin;
    cout << "Input password: ";
    in >> artist.m_strPassword;
    return in;

}

//void Artist::setSongs(vector<Song*> songs)
//{

//    m_pOwnedSongs = songs;

//}

ostream& operator<<(ostream &out, Artist &artist)
{
    out << artist.m_strName << ' ' << artist.m_strSurname << ' ' << artist.m_iNumOfAuditions;
    out << "Owned songs: " << endl;
    for (int i{};i<artist.m_vOwnedSongs.size();++i)
    {
        out << *artist.m_vOwnedSongs[i];
    }
    return out;
}
