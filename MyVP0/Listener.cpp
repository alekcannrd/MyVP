#include "Listener.h"

Listener::Listener(const UserSettings& crUserSettings)
    : BasicUser{crUserSettings}
{

}

//Artist* Listener::getFavoriteArtist() const
//{
//    return m_vpFavoriteArtists;
//}

//void Listener::setFavoriteArtist(Artist* crArtists)
//{
//    m_vpFavoriteArtists = crArtists;
//}

bool Listener::operator>(Listener &b) const
{
    return (getUserName()<b.getUserName());
}

bool Listener::operator<(Listener &b) const
{
    return (getUserName()>b.getUserName());
}

istream &operator>>(istream &in, Listener &listener)
{
    cout << "Input name: ";
    in >> listener.m_strUserName;
    cout << "Input surname: ";
    in >> listener.m_strUserLastName;
    input(cin,listener.m_uAge,0,255,"Input age");
    cout << "Input login: ";
    in >> listener.m_strUserLogin;
    cout << "Input password: ";
    in >> listener.m_strUserPassword;
    return in;

}

ostream &operator<<(ostream &out, Listener listener)
{
    out << listener.getId() << ' ' << listener.getUserName() << ' ' << listener.getUserLastName() << endl;
    out << *listener.getFavSong();

    return out;
}
