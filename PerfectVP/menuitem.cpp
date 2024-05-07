#include "menuitem.h"


template<typename T>
MenuItem<T>::MenuItem(string name, Func func,vector<T> list)
{
    m_strName = name;
    m_pFunction = func;
    m_vList = list;
}
template <typename T>
MenuItem<T>::~MenuItem()
{

}

//template <typename T>
//MenuItem<T>::Func MenuItem<T>::getFunc()
//{
//    return m_pFunction;
//}
template <typename T>
string MenuItem<T>::getName()
{
    return m_strName;
}
template <typename T>
void MenuItem<T>::run()
{
    *m_pFunction(m_vList);
}
template <typename T>
ostream &operator<<(ostream &out, MenuItem<T> &item)
{
    out << item.m_strName;
    return out;
}
template <typename T>
void MenuItem<T>::setName(string name)
{
    name = m_strName;
}
template <typename T>
void MenuItem<T>::setFunction(Func func)
{
    m_pFunction = func;
}



