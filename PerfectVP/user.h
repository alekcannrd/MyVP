#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
public:
    User(string name, string surname, int age, string login,string password);
    User();

protected:
    string m_strName;
    string m_strSurname;
    int m_iAge;
    string m_strLogin;
    string m_strPassword;

};


