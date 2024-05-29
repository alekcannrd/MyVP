#pragma once
#include "myiterator.h"
#include <iostream>

using namespace std;
template <typename T>
class MyVector
{
public:
    MyVector():
        m_pList{new T[100]},
        m_uSize{100},
        m_uCurrentSize{0}
    {

    }
    void push_back(T el)
    {
        if (m_uCurrentSize>=m_uSize)
        {
            increaseVector();
        }
        m_pList[m_uCurrentSize++] = el;
    }

    // возврат итератора на первый элемент
    Iterator<T> begin() {
    return Iterator(m_pList);
    }
    // возврат итератора на следующий за последним элемент
    Iterator<T> end() {
    return Iterator(m_pList+m_uCurrentSize);
    }
//    // возврат константного итератора на первый элемент
//    Iterator begin() const {
//    return Iterator(m_chars);
//    }
//    // возврат константного итератора на следующий за последним элемент
//    Iterator end() const {
//    return Iterator(m_end);
//    }
    void print()
    {
        for (unsigned i{};i<m_uCurrentSize;++i)
        {
            std::cout << m_pList[i];
        }
    }
    T& operator[](int index)
    {
        return m_pList[index];
    }
    unsigned size() const
    {
        return m_uCurrentSize;
    }
    void erase(Iterator<T> it)
    {
//        for (auto iter = it;iter!=end()-1;++iter)
//        {
//            if (iter!=end())
//            *iter = *(iter+1);
//        }
        bool fl{false};
        for (int i{};i<m_uCurrentSize-1;++i)
        {
            if ((*it).getId()==m_pList[i].getId())
            {
                fl = true;

            }
            if (fl)
            {
                m_pList[i] = m_pList[i+1];
            }
        }
        if (!fl)
        {
            std::cout << "Error: doesn't exist";
        }
        else
        {
            m_uCurrentSize--;

        }
    }


private:
    T* m_pList;
    T* m_pEnd;
    unsigned m_uSize;
    unsigned m_uCurrentSize;
    void increaseVector()
    {
        T* newList = new T[m_uSize*2];
        for (int i{};i<m_uCurrentSize;++i)
        {
            newList[i] = m_pList[i];
        }
        delete m_pList;
        m_pList = newList;
    }
};


