#include "../Header Files/Door.h"

std::string Door::generateID()
{
    std::ostringstream oss;
    oss << "D" << std::setw(4) << std::setfill('0') << counter;
    return oss.str();
}

Door::Door(std::string loc, SecurityLevel security_lvl, TimeRange allowed_times)
    : door_id(generateID()), location(loc), security_level(security_lvl), is_locked(false), allowed_access_times(allowed_times)
{
    counter++;
}

bool Door::checkBasicConditions(Time access_time) const
{
    if (allowed_access_times.isWithinRange(access_time) && (!is_locked))
    {
        return true;
    }
    return false;
}

std::string Door::getDoorID() const
{
    return door_id;
}
std::string Door::getLocation() const
{
    return location;
}
SecurityLevel Door::getSecurityLevel() const
{
    return security_level;
}
bool Door::getLockedStatus() const
{
    return is_locked;
}
void Door::setLockedStatus(bool lock_status)
{
    is_locked = lock_status;
}
void Door::setSecurityLevel(SecurityLevel lvl)
{
    security_level = lvl;
}
void Door::setAllowedTimes(TimeRange time)
{
    allowed_access_times = time;
}
TimeRange Door::getAllowedAccessTimes() const
{
    return allowed_access_times;
}

int Door::counter = 1;
