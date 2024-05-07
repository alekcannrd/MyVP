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
    MenuItem(string name,Func func,vector<T> list);
    ~MenuItem();
    void setFunction(Func func);
    void setName(string name);
    Func getFunc();
    string getName();
    void run();
    friend ostream &operator<<(ostream& out,MenuItem& item);

private:
    vector<T> m_vList;
    Func m_pFunction;
    string m_strName;
};


\


