//getAccessStrategy and getRole returns nullptr for edge case // handle error 


#ifndef ROLEFACTORY_H
#define ROLEFACTORY_H

#include <stdexcept>
#include <memory>
#include "../Header Files/Role.h"
#include "../Header Files/AccessStrategies.h"

class RoleFactory {
    public:
    static std::shared_ptr<Role> getRole(ROLEID role_id);
    static AccessStrategy* getAccessStrategy(const std::string& strategy_type);
    
    static std::shared_ptr<Role> getAdminInstance();
    static std::shared_ptr<Role> getGuestInstance();
    static std::shared_ptr<Role> getRegularInstance();
    static std::shared_ptr<Role> getMaintenanceInstance();

    
};
#endif