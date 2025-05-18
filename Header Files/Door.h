#ifndef DOOR_H
#define DOOR_H

#include "../Header Files/TimeRange.h"
#include "../Header Files/Enums.h"

#include <iostream>
#include <sstream>
#include <iomanip>

class Door
{
private:
    const std::string door_id, location;
    SecurityLevel security_level;
    bool is_locked;
    TimeRange allowed_access_times;
    static int counter;

    static std::string generateID();

public:
    Door(std::string loc, SecurityLevel security_lvl, TimeRange allowed_times);
    bool checkBasicConditions(Time access_time) const;

    std::string getDoorID() const;
    std::string getLocation() const;
    SecurityLevel getSecurityLevel() const;
    bool getLockedStatus() const;
    void setLockedStatus(bool lock_status);
    void setSecurityLevel(SecurityLevel lvl);
    void setAllowedTimes(TimeRange time);
    TimeRange getAllowedAccessTimes() const;
};

#endif