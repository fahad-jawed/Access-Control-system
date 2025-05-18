//getAccessStrategy and getRole returns nullptr for one case // handle error 

#include "../Header Files/RoleFactory.h"

std::shared_ptr<Role> RoleFactory::getAdminInstance() {
    static std::shared_ptr<Role>admin_role = std::make_shared<Role>(ROLEID::ADMIN, "Admin User", &(AdminAccessStrategySingleton::getInstance()));
    return admin_role;
}
std::shared_ptr<Role> RoleFactory::getGuestInstance() {
   static std::shared_ptr<Role>guest_role = std::make_shared<Role>(ROLEID::GUEST, "Guest User", &(GuestAccessStrategySingleton::getInstance()));
    return guest_role;
}
std::shared_ptr<Role> RoleFactory::getRegularInstance() {
    static std::shared_ptr<Role>regular_role = std::make_shared<Role>(ROLEID::REGULAR, "Regular User", &(RegularAccessStrategySingleton::getInstance()));
    return regular_role;
}
std::shared_ptr<Role> RoleFactory::getMaintenanceInstance() {
    static std::shared_ptr<Role>maintenance_role = std::make_shared<Role>(ROLEID::MAINTENANCE, "Maintenace User", &(MaintenanceAccessStrategySingleton::getInstance()));
    return maintenance_role;
}

std::shared_ptr<Role> RoleFactory::getRole(ROLEID role_id) {
        if (role_id == ROLEID::ADMIN) {
            return getAdminInstance();
        }
        else if (role_id == ROLEID::GUEST) {
            return getGuestInstance();
        }
        else if (role_id == ROLEID::REGULAR) {
            return getRegularInstance();
        }
        else if (role_id == ROLEID::MAINTENANCE) {
            return getMaintenanceInstance();
        }
        else {
            return nullptr;
        }
    }

AccessStrategy* RoleFactory::getAccessStrategy(const std::string& strategy_type) {
    if (strategy_type == "ADMIN" || strategy_type == "admin") {
        return &(AdminAccessStrategySingleton::getInstance());
    }
    else if (strategy_type == "GUEST" || strategy_type == "guest") {
        return &(GuestAccessStrategySingleton::getInstance());
    }
    else if (strategy_type == "REGULAR" || strategy_type == "regular") {
        return &(RegularAccessStrategySingleton::getInstance());
    }
    else if (strategy_type == "MAINTENANCE" || strategy_type == "maintenance") {
        return &(MaintenanceAccessStrategySingleton::getInstance());
    }
    else {
        return nullptr;
    }
}
