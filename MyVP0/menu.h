#pragma once
#include <string>
#include "menuitem.h"
#include "functions.h"
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
            std::cout << i+1 << ". " << m_pItemArray[i].getName() << std::endl;
        };
        cout << "0. Exit" << endl;
    }

    void run()
    {
        int choice{-1};

        while(choice)
        {
            printToConsole();
            input(std::cin,choice,0,m_iItemCount,"");
            if (choice>=1&&choice<=m_iItemCount)
            {
                m_pItemArray[choice-1].run();
            }
        }
    }

private:
    string m_strName;
    int m_iItemCount;
    MenuItem<T>* m_pItemArray;
};


