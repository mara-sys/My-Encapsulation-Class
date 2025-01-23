#include "../../include/algs/algs_std_lib/algs_date.h"

using std::string;
using std::istringstream;
using std::vector;

bool EncapDate::IsValid(int m, int d, int y)
{
    if (m < 1 || m > 12)      return false;
    if (d < 1 || d > DAYS[m]) return false;
    if (m == 2 && d == 29 && !IsLeapYear(y)) return false;
    return true;
}

bool EncapDate::IsLeapYear(int y)
{
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

EncapDate::EncapDate(int month, int day, int year)
{
    if (!IsValid(month, day, year)) 
        throw "Invalid data";
    month_ = month;
    day_ = day;
    year_ = year;
}

EncapDate::EncapDate(std::string date)
{
    istringstream iss(date);
    vector<string> fields;
    string temp;
    while (getline(iss, temp, '/')) {
        fields.push_back(temp);
    }

    if (fields.size() != 3)
        throw "Invalid date";

    month_ = std::stoi(fields[0]);
    day_ = std::stoi(fields[1]);
    year_ = std::stoi(fields[2]);
    
    if (IsValid(month_, day_, year_))
        throw "Invalid date";
}

EncapDate EncapDate::Next() {
    if (IsValid(month_, day_ + 1, year_))
        return EncapDate(month_, day_ + 1, year_);
    else if (IsValid(month_ + 1, day_, year_))
        return EncapDate(month_ + 1, day_, year_);
    else
        return EncapDate(month_, day_, year_ + 1);
}

bool EncapDate::IsAfter(EncapDate that)
{
    return *this > that;
}

bool EncapDate::IsBefore(EncapDate that)
{
    return *this < that;
}

bool EncapDate::operator<(const EncapDate &that) const
{
    if (year_ < that.year_)
        return true;
    if (year_ > that.year_)
        return false;
    if (month_ < that.month_)
        return true;
    if (month_ > that.month_)
        return false;
    if (day_ < that.day_)
        return true;
    if (day_ > that.day_)
        return false;
    return false;
}

bool EncapDate::operator==(const EncapDate &that) const
{
    if (year_ == that.year_ &&
        month_ == that.month_ &&
        day_ == that.day_)
        return true;
    return false;
}

bool EncapDate::operator>(const EncapDate &that) const
{
    return that < *this;
}

string EncapDate::ToString()
{
    return std::to_string(month_) + "/" + 
            std::to_string(day_) + "/" +
            std::to_string(year_);
}