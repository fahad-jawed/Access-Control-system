#include "../Header Files/Time.h"

Time::Time(int h = 0, int m = 0, int s = 0)
    : hour(h), minute(m), second(s)
{
    if (hour > 23 || hour < 0 || minute < 0 || minute > 59 || second > 59 || second < 0)
    {
        throw std::invalid_argument("Invalid Time");
    }
}

bool Time::isBefore(const Time &other) const
{
    if (hour < other.hour)
        return true;
    if (hour > other.hour)
        return false;
    if (minute < other.minute)
        return true;
    if (minute > other.minute)
        return false;
    return second < other.second;
}

bool Time::isAfter(const Time &other) const
{
    if (hour > other.hour)
        return true;
    if (hour < other.hour)
        return false;
    if (minute > other.minute)
        return true;
    if (minute < other.minute)
        return false;
    return second > other.second;
}

bool Time::isEqual(const Time &other) const
{
    return hour == other.hour && minute == other.minute && second == other.second;
}

std::string Time::toString() const
{
    std::string str = (std::to_string(hour) + " : " + std::to_string(minute) + " : " + std::to_string(second));

    return str;
}