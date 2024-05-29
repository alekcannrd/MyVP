#include "artist.h"



Artist::Artist(){}

Artist::Artist(const UserSettings &crUserSettings): BasicUser(crUserSettings)
{

}

unsigned int Artist::getAuditions()
{
    int numOfAuditions = 0;
    for (int i{}, total = m_vOwnedSongs.size();i<total;++i)
    {
        numOfAuditions+= m_vOwnedSongs[i]->getAuditions();
    };
    m_iNumOfAuditions = numOfAuditions;
    return m_iNumOfAuditions;
}

//Artist::Artist(string name, string surname, int age, string login, string password): User(name, surname,age,login,password)
//{

//}

bool Artist::operator>(Artist &b) const
{
    return (m_iNumOfAuditions>b.m_iNumOfAuditions);
}

bool Artist::operator<(Artist &b) const
{
    return (m_iNumOfAuditions<b.m_iNumOfAuditions);
}


istream &operator>>(istream &in, Artist &artist)
{
    cout << "Input name: ";
    in >> artist.m_strUserName;
    cout << "Input surname: ";
    in >> artist.m_strUserLastName;
    input(cin,artist.m_uAge,0,255,"Input age");
    cout << "Input login: ";
    in >> artist.m_strUserLogin;
    cout << "Input password: ";
    in >> artist.m_strUserPassword;
    return in;

}

//void Artist::setSongs(vector<Song*> songs)
//{

//    m_pOwnedSongs = songs;

//}

ostream& operator<<(ostream &out, Artist &artist)
{
    out << artist.getId() << ' ' << artist.m_strUserName << ' ' << artist.m_strUserLastName << ' ' << artist.getAuditions() << ' ';
    out << "Owned songs: " << endl;
    for (int i{};i<artist.m_vOwnedSongs.size();++i)
    {
        out << *artist.m_vOwnedSongs[i] << endl;
    }
    return out;
}
