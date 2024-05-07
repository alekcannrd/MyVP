#include "myiterator.h"


MyIterator::MyIterator(const MyIterator &it): m_User(it.m_User) {}

User &MyIterator::operator*() const
{
    return *m_User;
}

MyIterator &MyIterator::operator++()
{
    m_User++;
    return *this;
}

MyIterator &MyIterator::operator--()
{
    m_User--;
    return *this;
}

bool MyIterator::operator==(const MyIterator &it) const
{
    return m_User==it.m_User;
}

bool MyIterator::operator!=(const MyIterator &it) const {return m_User!=it.m_User;}

MyIterator::MyIterator(User *user): m_User(user)
{

}
