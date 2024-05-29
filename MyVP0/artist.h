#pragma once
#include "BasicUser.h"
#include "song.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Song;
class Artist: public BasicUser
{
public:
    Artist();
    Artist(const UserSettings& crUserSettings);
    unsigned getAuditions();
//    Artist(string name, string surname, int age, string login, string password);
    bool operator>(Artist &b) const;
    bool operator<(Artist &b) const;
    friend ostream& operator<<(ostream& out, Artist &artist);
    friend istream& operator>>(istream& in, Artist &artist);
    void addSong(Song* song)
    {
        m_vOwnedSongs.push_back(song);
    }
    void delSong(Song* song)
    {
        auto it = find(m_vOwnedSongs.begin(),m_vOwnedSongs.end(),song);
        if (it!=m_vOwnedSongs.end())
        {
            m_vOwnedSongs.erase(it);
        }
        else
        {
            cout << "ERROR: deleted element not founded";
        }
    }
//    void setSongs(vector<Song*> songs);

private:
    vector<Song*> m_vOwnedSongs;
    int m_iNumOfAuditions;


};


