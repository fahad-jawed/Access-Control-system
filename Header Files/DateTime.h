#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <ctime>
#include "../Header Files/Time.h"

class DateTime
{
private:
    int year, month, day, hour, minute, second;

    void ToDateTimeFormat();
    time_t toTimeT() const;

public:
    DateTime();
    bool isBefore(const DateTime& other) const;
    bool isAfter(const DateTime& other) const;
    bool isEqual(const DateTime& other) const;
    std::string toString() const;
    static DateTime getCurrentDateTime();
    Time DateTimetoTime() const ;
};

#endif