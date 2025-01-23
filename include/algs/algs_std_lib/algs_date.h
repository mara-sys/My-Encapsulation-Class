#ifndef MY_ENCAP_ALGS_DATE_H
#define MY_ENCAP_ALGS_DATE_H

#include <string>
#include <sstream>
#include <vector>

class EncapDate {
private:
    static constexpr int DAYS[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month_;
    int day_;
    int year_;


    bool IsValid(int m, int d, int y);
    bool IsLeapYear(int y);
public:
    /**
     * Default constructor
     */
    EncapDate() {}

    /**
     * Initializes a new date from the month, day, and year.
     * @param month the month (between 1 and 12)
     * @param day the day (between 1 and 28-31, depending on the month)
     * @param year the year
     * @throws IllegalArgumentException if this date is invalid
     */
    EncapDate(int month, int day, int year);

    /**
     * Initializes new date specified as a string in form MM/DD/YYYY.
     * @param date the string representation of this date
     * @throws IllegalArgumentException if this date is invalid
     */
    EncapDate(std::string date);

    /**
     * Return the month.
     * @return the month (an integer between 1 and 12)
     */
    inline int month() { return month_; }

    /**
     * Returns the day.
     * @return the day (an integer between 1 and 31)
     */
    inline int day() { return day_; }

    /**
     * Returns the year.
     * @return the year
     */
    inline int year() { return year_; }

    /**
     * Returns the next date in the calendar.
     *
     * @return a date that represents the next day after this day
     */
    EncapDate Next();

    /**
     * Compares two dates chronologically.
     *
     * @param  that the other date
     * @return {@code true} if this date is after that date; {@code false} otherwise
     */
    bool IsAfter(EncapDate that);

    /**
     * Compares two dates chronologically.
     *
     * @param  that the other date
     * @return {@code true} if this date is before that date; {@code false} otherwise
     */
    bool IsBefore(EncapDate that);

    /**
     * Returns a string representation of this date.
     *
     * @return the string representation in the format MM/DD/YYYY
     */
    std::string ToString();

    /**
     * Returns an integer hash code for this date.
     *
     * @return an integer hash code for this date
     */
    int HashCode();

    /**
     * Compares two dates chronologically.
     * 
     * @param that the other date
     * @return {@code true} if this date less than that date; {@code false} otherwise
     */
    bool operator<(const EncapDate &that) const;

    /**
     * Compares two dates chronologically.
     * 
     * @param that the other date
     * @return {@code true} if this date equals that date; {@code false} otherwise
     */
    bool operator==(const EncapDate &that) const;

    /**
     * Compares two dates chronologically.
     * 
     * @param that the other date
     * @return {@code true} if this date laters than that date; {@code false} otherwise
     */
    bool operator>(const EncapDate &that) const;
};

#endif