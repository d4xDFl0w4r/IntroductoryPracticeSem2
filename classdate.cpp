#include "classdate.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::GetDay() {
    return day;
}

void Date::SetDay(int day) {
    this->day = day;
}

int Date::GetMonth() {
    return month;
}

void Date::SetMonth(int month) {
    this->month = month;
}

int Date::GetYear() {
    return year;
}

void Date::SetYear(int year) {
    this->year = year;
}


Date::CompareDates(Date* firstDate, Date* secondDate) {
    if (firstDate->year > secondDate->year) {
        return 1;
    } else if (firstDate->year < secondDate->year) {
        return -1;
    } else {
        if (firstDate->month > secondDate->month) {
            return 1;
        } else if (firstDate->month < secondDate->month) {
            return -1;
        } else {
            if (firstDate->day > secondDate->day) {
                return 1;
            } else if (firstDate->day < secondDate->day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}