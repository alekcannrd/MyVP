#pragma once

#include "user.h"
#include "artist.h"
using namespace std;
class RegularUser: public User
{
public:
    RegularUser();
private:
    Artist** m_pFavoriteArtists;


};


