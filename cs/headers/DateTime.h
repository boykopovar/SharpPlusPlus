#ifndef DATETIME_H
#define DATETIME_H

#include "string.h"
#include <ctime>


struct TimeObject
{
    unsigned short hours, minutes, seconds;
    bool operator<(const TimeObject &other) const{return hours < other.hours || (hours == other.hours && minutes < other.minutes) || (hours == other.hours && minutes == other.minutes && seconds < other.seconds);}

    bool operator==(const TimeObject &other) const{return hours == other.hours && minutes == other.minutes && seconds == other.seconds;}
    bool operator!=(const TimeObject &other) const {return !((*this)==other);}

    bool operator<=(const TimeObject &other) const {return (*this) == other || (*this) < other;}
    bool operator>=(const TimeObject &other) const {return !((*this) < other);}
    bool operator >(const TimeObject &other) const {return !((*this) <= other);}
};


class DateTime {
public:
    DateTime(long long int year, unsigned long long int month, unsigned long long int day, unsigned short hours = 0, unsigned short minutes = 0, unsigned short seconds = 0);
    DateTime(long long int year, unsigned long long int month, unsigned long long int day, TimeObject time);

    explicit DateTime(const String& date_str);

    DateTime() : DateTime(Now()) {}
    bool operator==(const DateTime& other) const {return this->_day == other._day && this->_month == other._month && this->_year == other._year;}

    [[nodiscard]] unsigned long long Day() const{return this->_day;}
    [[nodiscard]] unsigned long long Month() const{return this->_month;}
    [[nodiscard]] unsigned long long Year() const{return this->_year;}

    [[nodiscard]] unsigned short Hours() const{return this->_time.hours;}
    [[nodiscard]] unsigned short Minutes() const{return this->_time.minutes;}
    [[nodiscard]] unsigned short Seconds() const{return this->_time.seconds;}

    [[nodiscard]] DateTime NextDay() const;
    [[nodiscard]] DateTime PreviousDay() const;
    [[nodiscard]] DateTime NextYear() const;
    static DateTime Now();

    [[nodiscard]] String ToString(bool need_time = true, const String& delim = ".") const;

    [[nodiscard]] unsigned long long int DaysTillBirthday(const DateTime& birthday) const;
    [[nodiscard]] unsigned long long int Duration(const DateTime& second_date) const;
    [[nodiscard]] long long int AbsoluteDays() const;

    [[nodiscard]] unsigned long long int DaysInYear() const {return 365 + static_cast<int>(this->IsLeap());}
    [[nodiscard]] unsigned long long int DaysInMonth() const {return _daysInMonth(this->_month);}

    [[nodiscard]] bool IsEndOfMonth() const {return this->_day == DaysInMonth();}
    [[nodiscard]] bool IsLastMonth() const {return (_month == 12);}
    [[nodiscard]] bool IsEndOfYear() const {return IsEndOfMonth() && IsLastMonth();}
    [[nodiscard]] bool IsLeap() const {return (this->_year%4 == 0 && this->_year%100 != 0) || this->_year%400 == 0;}

    friend std::ostream& operator<<(std::ostream &out, const DateTime& list) {return out << list.ToString();}


private:
    unsigned long long int _day, _month;
    long long int _year;

    TimeObject _time;

    [[nodiscard]] unsigned long long int _daysInMonth(unsigned long long int month_number) const;
    static long long int _leapCount(long long int year);
    [[nodiscard]] unsigned long long int _daysOfCurrentYear() const;

    void _check_date_part() const;
    void _check_time_part() const;
};


namespace std {
    template<>
    struct hash<DateTime> {unsigned long long operator()(const DateTime& date) const noexcept {return date.ToString().GetHash();}};
}


#endif //DATETIME_H
