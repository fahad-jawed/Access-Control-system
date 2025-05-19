//INCOMPLETE

#ifndef ROLE_H
#define ROLE_H

#include <memory>
#include "../Header Files/AccessStrategies.h"
#include "../Header Files/Enums.h"

class Role {
    private:
    ROLEID role_id;
    std::string role_name;
    SecurityLevel clearence_level;
    AccessStrategy* access_strategy;
    
    Role(const Role&) = delete;
    Role& operator = (const Role&) = delete;
    
    public:
    Role(ROLEID role_id, std::string role_name, AccessStrategy* access_strategy, SecurityLevel clearance_level);
    AccessStrategy* getAccessStrategy() const;
    ROLEID getRoleID() const;
    SecurityLevel getClearanceLevel() const;

};

#endif