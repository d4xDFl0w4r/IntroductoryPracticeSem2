#include "date.h"

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

unsigned int Date::getDay() {
    return day;
}

void Date::setDay(unsigned int newDay) {
    if (month == 2) {
        if (newDay <= 28) {
            day = newDay;
        } else if (newDay == 29 && year % 4 == 0) {
            day = newDay;
        }
    } else if ((month % 2 == 1 && month <= 7) || (month % 2 == 0 && month >= 8)) {
        if (newDay <= 31) {
            day = newDay;
        }
    } else {
        if (newDay <= 30) {
            day = newDay;
        }
    }
}

unsigned int Date::getMonth() {
    return month;
}

void Date::setMonth(unsigned int newMonth) {
    if (newMonth >= 1 && newMonth <= 12) {
        month = newMonth;
    }
}

unsigned int Date::getYear() {
    return year;
}

void Date::setYear(unsigned int newYear) {
    if (newYear >= 2000 && newYear <= 2024) {
        year = newYear;
    }
}

std::string Date::GetDateAsString() {
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}

int Date::CompareDates(Date* firstDate, Date* secondDate) {
    if (firstDate->year > secondDate->year) {
        return -1;
    } else if (firstDate->year < secondDate->year) {
        return 1;
    } else {
        if (firstDate->month > secondDate->month) {
            return -1;
        } else if (firstDate->month < secondDate->month) {
            return 1;
        } else {
            if (firstDate->day > secondDate->day) {
                return -1;
            } else if (firstDate->day < secondDate->day) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}
