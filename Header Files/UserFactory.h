#ifndef USERFACTORY_H
#define USERFACTORY_H

#include <string>
#include <stdexcept>
#include <memory>
#include "../Header Files/User.h"
#include "../Header Files/DerivedUsers.h"
#include "../Header Files/RoleFactory.h"
#include "../Header Files/Enums.h"
#include "../Header Files/DateTime.h"

class UserFactory
{
    UserFactory();
    UserFactory(const UserFactory& user_factory) = delete;
    UserFactory& operator = (const UserFactory& user_factory) = delete;
public:
    static UserFactory& getInstance () {
        static UserFactory instance;
        return instance;
    }

    std::unique_ptr<User> createGuestUser(const std::string &name, const std::string &password, const DateTime &expiry_datetime);
    std::unique_ptr<User> createRegularUser(const std::string &name, const std::string &password);
    std::unique_ptr<User> createAdminUser(const std::string &name, const std::string &password);
    std::unique_ptr<User> createMaintenanceUser(const std::string &name, const std::string &password);
   
};

#endif