#pragma once
#include <string>
#include <vector>
#include "functions.cpp"
struct UserSettings
{
    std::string m_strUserName;
    std::string m_strUserLastName;
    unsigned m_uAge;
    std::string m_strLogin;
    std::string m_strPassword;
};

struct AbstractBasicUser
{
    virtual ~AbstractBasicUser() = default;


    virtual void setNextId(const int id) = 0;

    virtual unsigned int getId() const = 0;

    virtual void setUserName(const std::string& crStrUserName) = 0;
    virtual std::string getUserName() const = 0;

    virtual void setUserLastName(const std::string& crUserLastName) = 0;
    virtual std::string getUserLastName() const = 0;

    virtual void setUserAge(unsigned int uAge) = 0;
    virtual unsigned int getUserAge() const = 0;

    virtual void setUserLogin(const std::string& crStrUserLogin) = 0;
    virtual std::string getUserLogin() const = 0;

    virtual void setUserPassword(const std::string& crStrUserPassword) = 0;
    virtual std::string getUserPassword() const = 0;
};


class BasicUser : public AbstractBasicUser
{
public:
    explicit BasicUser(const UserSettings& crUserSettings);
    BasicUser();

    void setNextId(const int id) final;
    unsigned int getId() const final;

    void setUserName(const std::string& crStrUserName) final;
    std::string getUserName() const final;

    void setUserLastName(const std::string& crUserLastName) final;
    std::string getUserLastName() const final;

    void setUserAge(unsigned int uAge) final;
    unsigned int getUserAge() const final;

    void setUserLogin(const std::string& crStrUserLogin) final;
    std::string getUserLogin() const final;

    void setUserPassword(const std::string &crStrUserPassword) final;
    std::string getUserPassword() const final;

protected:
    std::string m_strUserName;
    std::string m_strUserLastName;

    int m_uAge;
    int m_uId;
    std::string m_strUserLogin;
    std::string m_strUserPassword;
    static inline unsigned nextId{1};
};

