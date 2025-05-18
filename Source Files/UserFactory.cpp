#include "../Header Files/UserFactory.h"

std::unique_ptr<User> UserFactory::createGuestUser(const std::string &name, const std::string &password, const DateTime &expiry_datetime)
{
    std::shared_ptr<Role> role = RoleFactory::getRole(ROLEID::GUEST);
    return std::make_unique<GuestUser>(name, password, role, expiry_datetime);
}
std::unique_ptr<User> UserFactory::createRegularUser(const std::string &name, const std::string &password)
{

    std::shared_ptr<Role> role = RoleFactory::getRole(ROLEID::REGULAR);
    std::unique_ptr reg_user = std::make_unique<RegularUser>(name, password, role);
    return reg_user;
}
std::unique_ptr<User> UserFactory::createAdminUser(const std::string &name, const std::string &password)
{

    std::shared_ptr<Role> role = RoleFactory::getRole(ROLEID::ADMIN);
    return std::make_unique<AdminUser>(name, password, role);
}
std::unique_ptr<User> UserFactory::createMaintenanceUser(const std::string &name, const std::string &password)
{
    std::shared_ptr<Role> role = RoleFactory::getRole(ROLEID::MAINTENANCE);
    return std::make_unique<MaintenanceUser>(name, password, role);
}