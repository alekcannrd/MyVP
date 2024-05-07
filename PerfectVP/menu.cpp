#include "menu.h"


template<typename T>
Menu<T>::Menu(string name, MenuItem<T> *items, int count)
{
    m_pItemArray = items;
    m_strName = name;
    m_iItemCount = count;
}
template <typename T>
void Menu<T>::printToConsole()
{
    std::cout << m_strName << std::endl;
    for (int i{};i<m_iItemCount;++i)
    {
        std::cout << i << ". " << m_pItemArray[i].getName() << std::endl;
    };
}
template <typename T>
void Menu<T>::run()
{
    int choice{-1};
    while (choice)
    {
        std::cin >> choice;
        if (choice&&choice<=m_iItemCount)
        {
            m_pItemArray[choice].run();
        }
    }
}
