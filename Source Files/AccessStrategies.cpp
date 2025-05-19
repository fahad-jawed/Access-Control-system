#include "../Header Files/AccessStrategies.h"

RegularAccessStrategySingleton::RegularAccessStrategySingleton() {}
RegularAccessStrategySingleton& RegularAccessStrategySingleton::getInstance() {
    static RegularAccessStrategySingleton instance;
    return instance;
}
bool RegularAccessStrategySingleton::checkAccess(const User& user, const Door& door, const DateTime& access_time) const {
    SecurityLevel userClearance = user.getEffectiveClearanceLevel();
    SecurityLevel doorRequirement = door.getSecurityLevel();
    if((!user.isAccountCurrentlyActive(access_time)) || (!door.checkBasicConditions(access_time.DateTimetoTime())) || (doorRequirement == SecurityLevel::MAINTENANCE) || (static_cast<int>(userClearance) < static_cast<int>(doorRequirement))) {
        return false;
    }
    return true;
}


GuestAccessStrategySingleton::GuestAccessStrategySingleton() {}
GuestAccessStrategySingleton& GuestAccessStrategySingleton::getInstance() {
    static GuestAccessStrategySingleton instance;
    return instance;
}
bool GuestAccessStrategySingleton::checkAccess(const User& user, const Door& door, const DateTime& access_time) const {

    SecurityLevel doorRequirement = door.getSecurityLevel();
    if (!user.isAccountCurrentlyActive(access_time) ||
        !door.checkBasicConditions(access_time.DateTimetoTime())) { // Assuming DateTimetoTime() conversion method exists
        return false;
    }
    if (doorRequirement == SecurityLevel::LOW) {
        SecurityLevel userClearance = user.getEffectiveClearanceLevel();
        if (static_cast<int>(userClearance) >= static_cast<int>(SecurityLevel::LOW)) {
            return true;
        }
    }
    return false;
}


AdminAccessStrategySingleton::AdminAccessStrategySingleton() {}
AdminAccessStrategySingleton& AdminAccessStrategySingleton::getInstance() {
    static AdminAccessStrategySingleton instance;
    return instance;
}
bool AdminAccessStrategySingleton::checkAccess(const User& user, const Door& door, const DateTime& access_time) const {
    if (!user.isAccountCurrentlyActive(access_time)) {
        return false;
    }
    return true;
}

MaintenanceAccessStrategySingleton::MaintenanceAccessStrategySingleton() {}
MaintenanceAccessStrategySingleton& MaintenanceAccessStrategySingleton::getInstance() {
    static MaintenanceAccessStrategySingleton instance;
    return instance;
}
bool MaintenanceAccessStrategySingleton::checkAccess(const User& user, const Door& door, const DateTime& access_time) const {
    SecurityLevel userClearance = user.getEffectiveClearanceLevel();
    SecurityLevel doorRequirement = door.getSecurityLevel();

    if((!user.isAccountCurrentlyActive(access_time)) || (!door.checkBasicConditions(access_time.DateTimetoTime()))) {
        return false;
    }
    if (door.getSecurityLevel() == SecurityLevel::MAINTENANCE) {
        return true;
    }
    if (static_cast<int>(userClearance) >= static_cast<int>(doorRequirement)) {
        return true;
    }
    return false;
}


