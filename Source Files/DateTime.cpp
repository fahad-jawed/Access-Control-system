#include "../Header Files/DateTime.h"

void DateTime::ToDateTimeFormat()
{
    time_t current_datetime;
    std::time(&current_datetime);

    tm *struct_datetime = localtime(&current_datetime);

    year = (struct_datetime->tm_year + 1900);
    month = (struct_datetime->tm_mon + 1);
    day = (struct_datetime->tm_mday);
    hour = struct_datetime->tm_hour;
    minute = struct_datetime->tm_min;
    second = struct_datetime->tm_sec;
}

time_t DateTime::toTimeT() const
{
    tm tm_struct{};
    tm_struct.tm_year = year - 1900;
    tm_struct.tm_mon = month - 1;
    tm_struct.tm_mday = day;
    tm_struct.tm_hour = hour;
    tm_struct.tm_min = minute;
    tm_struct.tm_sec = second;
    return mktime(&tm_struct);
}

DateTime::DateTime()
{
    ToDateTimeFormat();
}
bool DateTime::isBefore(const DateTime& other) const
{
    return this->toTimeT() < other.toTimeT();
}
bool DateTime::isAfter(const DateTime& other) const
{
    return this->toTimeT() > other.toTimeT();
}
bool DateTime::isEqual(const DateTime& other) const {
    return (this->toTimeT() == other.toTimeT());
}
std::string DateTime::toString() const
{
    std::string str = (std::to_string(day) + " / " + std::to_string(month) + " / " + std::to_string(year) + " - " + std::to_string(hour) + " : " + std::to_string(minute) + " : " + std::to_string(second));

    return str;
}
DateTime DateTime::getCurrentDateTime()
{
    DateTime current_date_time;
    return current_date_time;
}
Time DateTime::DateTimetoTime() const {
        Time obj (this->hour, this->minute, this->second);
        return obj;
    }