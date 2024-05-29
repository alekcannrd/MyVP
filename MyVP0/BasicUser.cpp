#include "BasicUser.h"

BasicUser::BasicUser(const UserSettings& crUserSettings)
    : m_strUserName{crUserSettings.m_strUserName},
      m_strUserLastName{crUserSettings.m_strUserLastName},
      m_uAge{crUserSettings.m_uAge},
      m_strUserLogin{crUserSettings.m_strLogin},
      m_strUserPassword{crUserSettings.m_strPassword},
      m_uId{nextId++}
{

}

BasicUser::BasicUser():
    m_uId{nextId++}
{

}

void BasicUser::setNextId(const int id)
{
    nextId = id;
}

unsigned int BasicUser::getId() const
{
    return m_uId;
}

void BasicUser::setUserName(const std::string& crStrUserName)
{
    m_strUserName = crStrUserName;
}

std::string BasicUser::getUserName() const
{
    return m_strUserName;
}

void BasicUser::setUserLastName(const std::string& crUserLastName)
{
    m_strUserLastName = crUserLastName;
}

std::string BasicUser::getUserLastName() const
{
    return m_strUserLastName;
}

void BasicUser::setUserLogin(const std::string& crStrUserLogin)
{
    m_strUserLogin = crStrUserLogin;
}

std::string BasicUser::getUserLogin() const
{
    return m_strUserLogin;
}

void BasicUser::setUserPassword(const std::string& crStrUserPassword)
{
    m_strUserPassword = crStrUserPassword;
}

std::string BasicUser::getUserPassword() const
{
    return m_strUserPassword;
}

void BasicUser::setUserAge(unsigned int uAge)
{
    m_uAge = uAge;
}

unsigned int BasicUser::getUserAge() const
{
    return m_uAge;
}
