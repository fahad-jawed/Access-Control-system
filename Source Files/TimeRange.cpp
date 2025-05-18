#include "../Header Files/TimeRange.h"

#include <iostream>

TimeRange::TimeRange(const Time &st, const Time &et)
    : start_time(st), end_time(et)
{
    if (end_time.isBefore(start_time))
    {
        throw std::invalid_argument("End time can not be before start time");
    }
}

bool TimeRange::isWithinRange(const Time &time) const
{
    if (time.isAfter(start_time) && time.isBefore(end_time))
    {
        return true;
    }
    return false;
}

Time TimeRange::getStartTime() const
{
    return start_time;
}
Time TimeRange::getEndTime() const
{
    return end_time;
}
bool TimeRange::setTimeRange(const Time &st, const Time &et)
{
    if (st.isAfter(et))
    {
        return false;
    }
    start_time = st;
    end_time = et;
    return true;
}