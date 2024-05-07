#include "song.h"

Song::Song(string name)
{
    m_strName = name;
}

Song::Song(){}

void Song::setName(string name)
{
    m_strName = name;
}

void Song::setAuthor(Artist *author) {m_pAuthor = author;}

void Song::setAuditions(int auditions) {m_iAuditionNum = auditions;}

bool Song::operator<(Song &b)
{
    return m_iAuditionNum<b.m_iAuditionNum;
}

bool Song::operator>(Song &b)
{
    return m_iAuditionNum>b.m_iAuditionNum;
}

ostream &operator<<(ostream &out, Song &song)
{
    out << song.m_strName;
    return out;
}


