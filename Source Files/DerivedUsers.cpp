#include "../Header Files/DerivedUsers.h"

GuestUser::GuestUser(std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles, const DateTime &expiry_datetime)
    : User(name, password, roles), expiry_datetime(expiry_datetime)
{
}
bool GuestUser::isExpiryDateTimeValid(const DateTime &current_datetime) const
{
    return ((expiry_datetime.isAfter(current_datetime)) && (expiry_datetime.isEqual(current_datetime)));
}
bool GuestUser::isAccountCurrentlyActive(const DateTime &current_datetime) const
{
    if ((!this->checkLockStatus()) || isExpiryDateTimeValid(current_datetime))
    {
        return true;
    }
    return false;
}

RegularUser::RegularUser(std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles)
    : User(name, password, roles)
{
}
bool RegularUser::isAccountCurrentlyActive(const DateTime &current_time) const
{
    return !(this->checkLockStatus());
}

MaintenanceUser::MaintenanceUser(std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles)
    : User(name, password, roles)
{
}
bool MaintenanceUser::isAccountCurrentlyActive(const DateTime &current_time) const
{
    return !(this->checkLockStatus());
}

AdminUser::AdminUser(std::string name, std::string password, std::set<std::shared_ptr<Role>>& roles)
    : User(name, password, roles)
{
}
bool AdminUser::isAccountCurrentlyActive(const DateTime &current_time) const
{
    return !(this->checkLockStatus());
}