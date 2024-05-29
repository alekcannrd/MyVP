#include "song.h"

Song::Song(string name,int num):
    m_uId{m_uNextId++},
    m_iAuditionNum{num}
{
    m_strName = name;
}

Song::Song():
    m_uId{m_uNextId++}
{

}

string Song::getName() const
{
    return m_strName;
}

Artist *Song::getArtist() const
{
    return m_pAuthor;
}

int Song::getAuditions() const
{
    return m_iAuditionNum;
}

void Song::setName(string name)
{
    m_strName = name;
}

void Song::setAuthor(Artist *author)
{
    if (m_pAuthor!=nullptr)
        m_pAuthor->delSong(this);
    author->addSong(this);
    m_pAuthor = author;
}

void Song::setAuditions(int auditions) {m_iAuditionNum = auditions;}

unsigned int Song::getId() const
{
    return m_uId;
}

bool Song::operator<(Song &b)
{
    return m_iAuditionNum<b.m_iAuditionNum;
}

bool Song::operator>(Song &b)
{
    return m_iAuditionNum>b.m_iAuditionNum;
}

istream &operator>>(istream &in, Song &song)
{
    input(in,song.m_iAuditionNum,0,INT_MAX,"Input num of auditions: ");
    cout << "Input name: ";
    getline(in,song.m_strName);
    return in;

}

ostream &operator<<(ostream &out, Song &song)
{
    out << song.getId() << ' ' << song.m_strName << endl;
    return out;
}


