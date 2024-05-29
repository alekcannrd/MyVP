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
    Artist* getFavoriteArtist() const;
    void setFavoriteArtist(Artist* crArtists);
    friend ostream& operator<<(ostream& out, Listener listener) ;
    friend istream &operator>>(istream &in, Listener &listener);
    bool operator>(Listener &b) const;

    bool operator<(Listener &b) const;
private:
   Artist* m_vpFavoriteArtists;

};
