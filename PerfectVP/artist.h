#pragma once
#include "user.h"
#include "song.h"
#include <iostream>
#include <vector>
class Song;
using namespace std;
class Artist: public User
{
public:
    Artist();
    Artist(string name, string surname, int age, string login, string password);
    bool operator>(Artist &b);
    bool operator<(Artist &b);
    friend ostream& operator<<(ostream& out, Artist &artist);
    friend istream& operator>>(istream& in, Artist &artist);
    void setSongs(vector<Song*> songs);

private:
    vector<Song*> m_vOwnedSongs;
    int m_iNumOfAuditions;

};


