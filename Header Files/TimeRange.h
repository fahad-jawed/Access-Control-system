#ifndef TIMERANGE_H
#define TIMERANGE_H

#include "../Header Files/Time.h"

class TimeRange
{
private:
    Time start_time, end_time;

public:
    TimeRange(const Time &st, const Time &et);

    bool isWithinRange(const Time &time) const;

    Time getStartTime() const;
    Time getEndTime() const;

    bool setTimeRange(const Time &st, const Time &et);
};
#endif