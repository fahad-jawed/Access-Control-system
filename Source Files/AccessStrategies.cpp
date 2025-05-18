#include "../Header Files/AccessStrategies.h"

RegularAccessStrategySingleton::RegularAccessStrategySingleton() {}
RegularAccessStrategySingleton& RegularAccessStrategySingleton::getInstance() {
    static RegularAccessStrategySingleton instance;
    return instance;
}
bool RegularAccessStrategySingleton::checkAccess(const User* user, const Door* door, const DateTime& access_time) const {

}


GuestAccessStrategySingleton::GuestAccessStrategySingleton() {}
GuestAccessStrategySingleton& GuestAccessStrategySingleton::getInstance() {
    static GuestAccessStrategySingleton instance;
    return instance;
}
bool GuestAccessStrategySingleton::checkAccess(const User* user, const Door* door, const DateTime& access_time) const {

}


AdminAccessStrategySingleton::AdminAccessStrategySingleton() {}
AdminAccessStrategySingleton& AdminAccessStrategySingleton::getInstance() {
    static AdminAccessStrategySingleton instance;
    return instance;
}
bool AdminAccessStrategySingleton::checkAccess(const User* user, const Door* door, const DateTime& access_time) const {
    
}

MaintenanceAccessStrategySingleton::MaintenanceAccessStrategySingleton() {}
MaintenanceAccessStrategySingleton& MaintenanceAccessStrategySingleton::getInstance() {
    static MaintenanceAccessStrategySingleton instance;
    return instance;
}
bool MaintenanceAccessStrategySingleton::checkAccess(const User* user, const Door* door, const DateTime& access_time) const {
}


