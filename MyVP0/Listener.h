#pragma once
#include <iostream>
#include <vector>
#include "BasicUser.h"
#include "artist.h"

using namespace std;
class Artist;
class Listener : public BasicUser
{
public:
    Listener() {}
    Listener(const UserSettings& crUserSettings);
    void setFavSong(Song* a)
    {
        m_pFavSong = a;
    }
    Song* const & getFavSong() const
    {
        return m_pFavSong;
    }
    friend ostream& operator<<(ostream& out, Listener listener) ;
    friend istream &operator>>(istream &in, Listener &listener);
    bool operator>(Listener &b) const;

    bool operator<(Listener &b) const;
private:
   Song* m_pFavSong;

};
