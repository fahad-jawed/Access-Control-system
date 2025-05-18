//INCOMPLETE checkAccess().. return after User..


#ifndef ACCESSSTRATEGIES_H
#define ACCESSSTRATEGIES_H

#include "../Header Files/Door.h"
#include "../Header Files/DateTime.h"

class User;


class AccessStrategy
{
public:
    AccessStrategy() = default;
    virtual ~AccessStrategy() = default;
    virtual bool checkAccess(const User* user, const Door* door, const DateTime& access_time) const = 0;
};

class RegularAccessStrategySingleton : public AccessStrategy {
private:
    RegularAccessStrategySingleton();
    RegularAccessStrategySingleton(const RegularAccessStrategySingleton&) = delete;
    RegularAccessStrategySingleton& operator=(const RegularAccessStrategySingleton&) = delete;

public:
    static RegularAccessStrategySingleton& getInstance();
    bool checkAccess(const User* user, const Door* door, const DateTime& access_time) const override;
};

class GuestAccessStrategySingleton : public AccessStrategy {
private:
    GuestAccessStrategySingleton();
    GuestAccessStrategySingleton(const GuestAccessStrategySingleton&) = delete;
    GuestAccessStrategySingleton& operator=(const GuestAccessStrategySingleton&) = delete;

public:
    static GuestAccessStrategySingleton& getInstance();
    bool checkAccess(const User* user, const Door* door, const DateTime& access_time) const override;
};

class AdminAccessStrategySingleton : public AccessStrategy {
private:
    AdminAccessStrategySingleton();
    AdminAccessStrategySingleton(const AdminAccessStrategySingleton&) = delete;
    AdminAccessStrategySingleton& operator=(const AdminAccessStrategySingleton&) = delete;

public:
    static AdminAccessStrategySingleton& getInstance();
    bool checkAccess(const User* user, const Door* door, const DateTime& access_time) const override;
};

class MaintenanceAccessStrategySingleton : public AccessStrategy {
private:
    MaintenanceAccessStrategySingleton();
    MaintenanceAccessStrategySingleton(const MaintenanceAccessStrategySingleton&) = delete;
    MaintenanceAccessStrategySingleton& operator=(const MaintenanceAccessStrategySingleton&) = delete;

public:
    static MaintenanceAccessStrategySingleton& getInstance();
    bool checkAccess(const User* user, const Door* door, const DateTime& access_time) const override;
};

#endif 