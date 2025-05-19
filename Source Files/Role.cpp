#include "../Header Files/Role.h"

Role::Role(ROLEID role_id, std::string role_name, AccessStrategy* access_strategy, SecurityLevel clearance_level) : role_id(role_id), role_name(role_name), access_strategy(access_strategy), clearence_level(clearance_level)
    {}

AccessStrategy* Role::getAccessStrategy() const {
    return access_strategy;
};

ROLEID Role::getRoleID() const {
    return this->role_id;
}
SecurityLevel Role::getClearanceLevel() const {
    return clearence_level;
}


