#include "../../headers/DateTime.h"


DateTime::DateTime(const long long int year, const unsigned long long int month, const unsigned long long int day, const unsigned short hours, const unsigned short minutes , const unsigned short seconds)
{
    this->_day = day;
    this->_month = month;
    this->_year = year;
    this->_time = {hours, minutes, seconds};

    this->_check_date_part();
    this->_check_time_part();
}


DateTime::DateTime(const long long int year, const unsigned long long int month, const unsigned long long int day, TimeObject time)
{
    this->_day = day;
    this->_month = month;
    this->_year = year;
    this->_time = time;

    this->_check_date_part();
    this->_check_time_part();
}



DateTime::DateTime(const String& date_str)
{
    const auto date_and_time = date_str.Split();
    const auto date_parts = date_and_time[0].Split(".");

    for (long long str_i = 0; str_i<date_parts.Size(); ++str_i)
    {
        const auto& part = date_parts[str_i];
        for (long long i =0;i<part.Size();++i) {
            if (!part[i].IsNumber() && !(i==0 && part[i] == "-" && part.Size()>1)) {
                throw std::invalid_argument("Invalid date");
            }
        }
    }

    this->_day = date_parts[0].ToInt();
    this->_month = date_parts[1].ToInt();
    this->_year = date_parts[2].ToInt();

    this->_check_date_part();

    if (date_and_time.Size() == 2)
    {
        const auto time_parts = date_and_time[1].Split(":");

        for (long long str_i = 0; str_i<time_parts.Size(); ++str_i)
        {
            const auto& part = time_parts[str_i];
            for (long long i =0;i<part.Size();++i) {
                if (!part[i].IsNumber()) {
                    throw std::invalid_argument("Неверное время");
                }
            }
        }

        this->_time.hours = time_parts[0].ToInt();
        this->_time.minutes = time_parts[1].ToInt();
        this->_time.seconds = time_parts[2].ToInt();

        this->_check_time_part();
    }
    else if (date_and_time.Size() !=1 && date_and_time.Size() != 2) throw std::invalid_argument("Invalid date format");
}


DateTime DateTime::Now()
{
    const auto t = std::time(nullptr);
    const std::tm* tm = std::localtime(&t);

    return {
        tm->tm_year+1900,
        static_cast<unsigned long long int>(tm->tm_mon+1),
        static_cast<unsigned long long int>(tm->tm_mday),
        static_cast<unsigned short>(tm->tm_hour),
        static_cast<unsigned short>(tm->tm_min),
        static_cast<unsigned short>(tm->tm_sec)
    };
}

DateTime DateTime::NextDay() const{
    if (IsEndOfYear()) {
        long long int new_year = _year + 1;
        if (_year == -1) new_year = 1;
        return {new_year, 1, 1, this->_time};
    }
    if (IsEndOfMonth()) return {_year, _month + 1, 1, this->_time};

    return {_year, _month, _day + 1, this->_time};
}

DateTime DateTime::PreviousDay() const
{
    if (_day == 1 && _month ==1) {
        long long int new_year = _year - 1;
        if (_year ==1) new_year = -1;
        return {new_year, 1, _daysInMonth(1), this->_time};
    }
    if (_day ==1) return {_year, _month - 1, _daysInMonth(_month-1), this->_time};
    return {_year, _month, _day - 1, this->_time};
}

DateTime DateTime::NextYear() const{
    long long int new_year = _year + 1;
    unsigned long long int new_day = this->_day;

    if (this->_year == -1) new_year = 1;
    if (this->_day == 29 && this->_month == 2) new_day = 28;

    return {new_year, _month, new_day, this->_time};
}



String DateTime::ToString(const bool need_time, const String& delim) const
{
    const auto day_str = this->_day>9 ? String(this->_day) : String(0) + String(this->_day);
    const auto month_str = this->_month>9 ? String(this->_month) : String(0) + String(this->_month);

    const unsigned long long abs_year = this->_year <0 ? -this->_year : this->_year;
    auto year_str = String(abs_year);

    if (abs_year <10) {
        year_str = String("000") + year_str;
    }
    else if (abs_year < 100) {
        year_str = String("00") + year_str;
    }
    else if (abs_year < 1000) {
        year_str = String("0") + year_str;
    }
    year_str = this->_year <0 ? String("-") + year_str : year_str;

    auto date_str = day_str + delim + month_str + delim + year_str;
    if (need_time)
    {
        const String minutes = this->_time.minutes>9 ? String(this->_time.minutes) : String(0) + String(this->_time.minutes);
        const String hours = this->_time.hours>9 ? String(this->_time.hours) : String(0) + String(this->_time.hours);
        const String seconds = this->_time.seconds>9 ? String(this->_time.seconds) : String(0) + String(this->_time.seconds);

        date_str = date_str + " " + hours + ":" + minutes + ":" + seconds;
    }
    return date_str;
}



unsigned long long int DateTime::Duration(const DateTime& second_date) const
{
    const long long int duration = this->AbsoluteDays() - second_date.AbsoluteDays();
    return duration <0 ? -duration : duration;
}

long long int DateTime::AbsoluteDays() const {
    unsigned long long int leap_count = _leapCount(this->_year);
    leap_count = this->_year <0 ? -leap_count : leap_count;

    const long long int days_in_full_years = static_cast<long long>(365) * (this->_year -1) + static_cast<long long>(leap_count);
    const auto abs_days_of_current_year = _daysOfCurrentYear();

    long long days_of_current_year = 0;
    if (this->_year < 0) days_of_current_year = -static_cast<long long>(abs_days_of_current_year);
    else days_of_current_year = static_cast<long long>(abs_days_of_current_year);
    return days_of_current_year + days_in_full_years;
}

unsigned long long int DateTime::_daysInMonth(const unsigned long long int month_number) const
{
    if (month_number <1 || month_number > 12) return 0;
    if (month_number == 2) return this->IsLeap() ? 29 : 28;

    const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[month_number-1];
}

unsigned long long int DateTime::_daysOfCurrentYear() const {
    unsigned long long int abs_days_of_current_year = 0;

    // for (int i = 1; i<this->month; ++i) {
    //     if (this->month >i) abs_days_of_current_year += _daysInMonth(i);
    // }

    for (int i = 1; i<12; ++i) {
        if (this->_month >i) abs_days_of_current_year += _daysInMonth(i);
    }

    return abs_days_of_current_year + this->_day;
}

unsigned long long int DateTime::DaysTillBirthday(const DateTime& birthday) const
{
    long long int days_count = 0;
    if (!this->IsLeap() && birthday._day == 29 && birthday._month == 2) {
        auto buf_year = this->NextYear();
        days_count +=365;
        while (!buf_year.IsLeap()) {
            buf_year = this->NextYear();
        }
        days_count += static_cast<long long>(this->_daysOfCurrentYear()) - static_cast<long long>(birthday._daysOfCurrentYear());

    }
    else {
        days_count = static_cast<long long>(this->_daysOfCurrentYear()) - static_cast<long long>(birthday._daysOfCurrentYear());
    }
    return days_count < 0 ? -days_count : days_count;
}


long long int DateTime::_leapCount(const long long int year) {
    const long long int leap_count = year/4 - year/100 + year/400;
    return leap_count < 0 ? -leap_count : leap_count;
}

void DateTime::_check_date_part() const
{
    if (this->_year == 0 || this->_month < 1 || this->_month > 12) {
        throw std::invalid_argument("Invalid date");
    }

    if (this->_day > this->DaysInMonth()) {
        throw std::invalid_argument("Invalid days count");
    }
}

void DateTime::_check_time_part() const
{
    if (this->_time.hours >=24 || this->_time.minutes >= 60 || this->_time.seconds >= 60) {
        throw std::invalid_argument("Invalid time");
    }

    if (this->_time.hours <0 || this->_time.minutes < 0 || this->_time.seconds < 0) {
        throw std::invalid_argument("Invalid time");
    }
}

