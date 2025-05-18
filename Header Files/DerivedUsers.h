#ifndef DERIVEDUSERS_H
#define DERIVEDUSERS_H

#include "../Header Files/User.h"
#include "../Header Files/DateTime.h"
#include "../Header Files/enums.h"

class GuestUser : public User {
    DateTime expiry_datetime;

    public:
    GuestUser (std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles, const DateTime& expiry_datetime);
    bool isExpiryDateTimeValid(const DateTime& current_datetime) const;
    bool isAccountCurrentlyActive(const DateTime& current_datetime) const override;
};

class RegularUser : public User {
    public:
    RegularUser (std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles);
    bool isAccountCurrentlyActive(const DateTime& current_time) const override;
};

class MaintenanceUser : public User {
    public:
    MaintenanceUser (std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles);
    bool isAccountCurrentlyActive(const DateTime& current_time) const override;
};

class AdminUser : public User {
    public:
    AdminUser (std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles);
    bool isAccountCurrentlyActive(const DateTime& current_time) const override;
};

#endif