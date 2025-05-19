//throws std::invalid_arguement in generateID method..

#ifndef USER_H
#define USER_H

#include <string>
#include <iomanip>
#include <set>
#include <memory>
#include <stdexcept>
#include "../Header Files/Door.h"
#include "../Header Files/DateTime.h"
#include "../Header Files/RoleFactory.h"
#include "../Header Files/picosha2.h"


class User {
    private:
    const std::string userID;
    std::string name;
    std::string hashed_password;
    int failed_login_attempts;
    std::set<std::shared_ptr<Role>> roles;

    bool is_locked;
    static int counter;

    static std::string generateID();
    public:
    User(std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles);
    void incrementFailedLoginAttempt();
    void resetFailedLoginAttempts();
    bool authenticate(const std::string& tried_password);
    std::set<std::shared_ptr<Role>> getRoles() const;
    bool checkLockStatus() const;
    void changePassword(const std::string& new_password);
    void lockAccount();
    void unlockAccount();
    std::string getUserID() const;
    void addRole(std::shared_ptr<Role> role);
    bool removeRole(std::shared_ptr<Role> role);
    SecurityLevel getEffectiveClearanceLevel() const;
    virtual bool isAccountCurrentlyActive(const DateTime& current_time) const = 0;
};

#endif