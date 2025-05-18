#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

class Time
{
private:
    int hour, second, minute;

public:
    Time(int h = 0, int m = 0, int s = 0);
    bool isBefore(const Time &other) const;
    bool isAfter(const Time &other) const;
    bool isEqual(const Time &other) const;
    std::string toString() const;
};

#endif