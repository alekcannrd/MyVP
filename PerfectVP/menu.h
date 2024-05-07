#pragma once
#include <string>
#include "menuitem.h"
using namespace std;

template<typename T>
class Menu
{
public:
    Menu(string name, MenuItem<T>* items, int count)
        : m_pItemArray{items},
          m_strName{name},
          m_iItemCount{count}
    {
//        m_pItemArray = items;
//        m_strName = name;
//        m_iItemCount = count;
    }

    void printToConsole()
    {
        std::cout << m_strName << std::endl;
        for (int i{};i<m_iItemCount;++i)
        {
            std::cout << i << ". " << m_pItemArray[i].getName() << std::endl;
        };
    }

    void run()
    {
        int choice{-1};
        while(choice)
        {
            std::cin >> choice;
            if (choice&&choice<=m_iItemCount)
            {
                m_pItemArray[choice].run();
            }
        }
    }

private:
    string m_strName;
    int m_iItemCount;
    MenuItem<T>* m_pItemArray;
};


