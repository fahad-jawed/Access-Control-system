#include "../Header Files/User.h"

std::string User::generateID() {
        std::ostringstream oss;
        oss << "U" << std::setw(4) << std::setfill('0') << counter;
        return oss.str();
    }
    User::User(std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles) 
        : userID(generateID()), name(name), failed_login_attempts(0), is_locked(false), roles(roles)
    {
        counter++;
        hashed_password = picosha2::hash256_hex_string(password);

        for(auto role : roles) {
            addRole(role);
        }
    }
    void User::incrementFailedLoginAttempt() {
        failed_login_attempts++;
    }
    void User::resetFailedLoginAttempts() {
        failed_login_attempts = 0;
        is_locked = false;
    }
    bool User::authenticate(const std::string& tried_password) {
        std::string tried_hash = picosha2::hash256_hex_string(tried_password);
        if (tried_hash == hashed_password) {
            resetFailedLoginAttempts();
            return true;
        }
        //diff functionality for admin, because agar last admin bhi lock out hogya administration kon handle karega..  
        bool is_admin = false;
        for (const auto& role : this->roles) {
            if (role->getRoleID() == ROLEID::ADMIN) {
                is_admin = true;
                break;
            }
        }
        failed_login_attempts++;
        if((failed_login_attempts == 5) && !is_admin) {
            is_locked = true;
        }
        return false;
    }
    void User::changePassword(const std::string& new_password) {
        this->hashed_password = picosha2::hash256_hex_string(new_password);
    }
    std::string User::getUserID() const {
        return userID;
    }
    std::set<std::shared_ptr<Role>> User::getRoles() const {
        return roles;
    }
    bool User::checkLockStatus() const {
        return is_locked;
    }
    void User::addRole(std::shared_ptr<Role> role) {
        roles.insert(role);
    }
    bool User::removeRole(std::shared_ptr<Role> role) {
        if (roles.erase(role) == 1) {
            return true;
        }
        return false;
    }
    SecurityLevel User::getEffectiveClearanceLevel() const {
    SecurityLevel highestClearance = SecurityLevel::MAINTENANCE;
    for (const auto& role : roles) {
        if (role) {
            if (static_cast<int>(role->getClearanceLevel()) > static_cast<int>(highestClearance)) {
                highestClearance = role->getClearanceLevel();
            }
        }
    }
    return highestClearance;
}
void User::lockAccount() {
        this->is_locked = true;
    }
void User::unlockAccount() {
        this->is_locked = false;
    }