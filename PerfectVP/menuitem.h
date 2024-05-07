#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MenuItem
{
public:

    typedef void(*Func)(vector<T> list);
    MenuItem(string strName, Func func, vector<T> list)
        : m_strName{strName},
          m_Function{func},
          m_vList{list}
    {
//        m_strName = strName;
//        m_Function = func;
//        m_vList =list;
    }

    ~MenuItem()
    {

    }
    void setFunction(Func func)
    {
        m_Function = func;
    }
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
        m_Function(m_vList);
    }
//    friend ostream &operator<<(ostream& out, MenuItem& item);
    friend ostream &operator<<(ostream &out, MenuItem<T> &item)
    {
        out << item.m_strName;
        return out;
    }


private:
    vector<T> m_vList;
    Func m_Function;
    string m_strName;
};





