#pragma once
#include <string>
#include "menuitem.h"
using namespace std;
template<typename T>
class Menu
{
public:
    Menu(string name,MenuItem<T>* items, int count);
    void printToConsole();
    void run();
private:
    string m_strName;
    int m_iItemCount;
    MenuItem<T>* m_pItemArray;
};


