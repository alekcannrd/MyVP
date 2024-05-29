#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "myvector.h"
using namespace std;

template <typename T>
class MenuItem
{
public:

    typedef void(*Func)(MyVector<T>* const list);
    MenuItem(string strName, Func func,  MyVector<T>* const list)
        : m_strName{strName},
          m_Function{func},
          m_pvList{list}
    {
//        m_strName = strName;
//        m_Function = func;
//        m_vList =list;
    }

    ~MenuItem()
    {

    }
//    void setFunction(Func func)
//    {
//        m_Function = func;
//    }
    void setName(string name)
    {
        name = m_strName;
    }
    Func getFunc();
    string getName()
    {
        return m_strName;
    }
    void run()
    {
//        *m_Function(m_vList);
        m_Function(m_pvList);
    }
//    friend ostream &operator<<(ostream& out, MenuItem& item);
    friend ostream &operator<<(ostream &out, MenuItem<T> &item)
    {
        out << item.m_strName;
        return out;
    }


private:
    MyVector<T>* const m_pvList;
    Func m_Function;
    string m_strName;
};





