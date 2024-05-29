#pragma once
#include "artist.h"
#include "functions.h"
using namespace std;
class Artist;
class Song
{
public:
    Song(string name,int num);
    Song();
    string getName() const;
    Artist* getArtist() const;
    int getAuditions() const;
    void setName(string name);
    void setAuthor(Artist* author);
    void setAuditions(int auditions);
    unsigned getId() const;
    bool operator<(Song &b);
    bool operator>(Song &b);
    friend ostream& operator<<(ostream& out, Song &song);
    friend istream& operator>>(istream& in, Song &song);
private:
    int m_iAuditionNum;
    Artist* m_pAuthor{nullptr};
    string m_strName;
    static inline unsigned m_uNextId{1};
    unsigned m_uId;


};

