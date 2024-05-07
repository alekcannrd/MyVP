#pragma once
#include "user.h"

using namespace std;

class MyIterator
{
    friend class MyVector;
public:
    MyIterator(const MyIterator& it);
    User& operator*() const;
    MyIterator& operator++();
    MyIterator& operator--();
    bool operator==(const MyIterator &it) const;
    bool operator!=(const MyIterator& it) const;
private:
    User *m_User;
    MyIterator(User* user);

};


