//find methods return nullptr....
//createGuestUser throws an error at a case ///

#ifndef ACCESSCONTROLLSYSTEM_H
#define ACCESSCONTROLLSYSTEM_H

#include "../Header Files/Time.h"
#include "../Header Files/DateTime.h"
#include "../Header Files/TimeRange.h"
#include "../Header Files/User.h"
#include "../Header Files/DerivedUsers.h"
#include "../Header Files/UserFactory.h"
#include "../Header Files/Role.h"
#include "../Header Files/RoleFactory.h"
#include "../Header Files/Door.h"
#include "../Header Files/AccessStrategies.h"
#include "../Header Files/Enums.h"

#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <string>

class AccessControlSystem
{
private:
    std::vector<std::unique_ptr<User>> users;
    std::vector<std::unique_ptr<Door>> doors;
    AccessControlSystem(std::vector<std::unique_ptr<User>> users_vector, std::vector<std::unique_ptr<Door>> doors_vector)
        : users(std::move(users_vector)), doors(std::move(doors_vector)) {}
    AccessControlSystem() {}
    AccessControlSystem(const AccessControlSystem &acs) = delete;
    AccessControlSystem &operator=(const AccessControlSystem &acs) = delete;

public:
    static AccessControlSystem &getInstance();
    Door* findDoor(const std::string& door_id) const;
    User* findUser(const std::string& user_id) const;
    bool addUser(ROLEID userType,const std::string& name,const std::string& password, const DateTime* expiry_date = nullptr);


    bool processAccessRequest(const User &authenticatedUser, const std::string &door_id);
    bool addDoor (const std::string& location, SecurityLevel security_level, const TimeRange& allowed_times);

    const std::vector<std::unique_ptr<User>>& getAllUsers() const;
    const std::vector<std::unique_ptr<Door>>& getAllDoors() const;
    User* authenticateUser(const std::string& user_id, const std::string& password);
    bool lockAccount(const std::string& userID);
    bool unlockAccount(const std::string& user_id);
    bool resetFailedLoginAttempts(const std::string& user_id);
};
#endif