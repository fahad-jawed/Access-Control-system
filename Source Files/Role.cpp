#include "../Header Files/Role.h"

Role::Role(ROLEID role_id, std::string role_name, AccessStrategy* access_strategy) : role_id(role_id), role_name(role_name), access_strategy(access_strategy)
    {}

ROLEID Role::getRoleID() const {
    return this->role_id;
}

