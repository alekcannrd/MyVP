#pragma once
#include "artist.h"
using namespace std;
class Artist;
class Song
{
public:
    Song(string name);
    Song();
    void setName(string name);
    void setAuthor(Artist* author);
    void setAuditions(int auditions);
    bool operator<(Song &b);
    bool operator>(Song &b);
    friend ostream& operator<<(ostream& out, Song &song);
private:
    int m_iAuditionNum;
    Artist* m_pAuthor;
    string m_strName;

};

