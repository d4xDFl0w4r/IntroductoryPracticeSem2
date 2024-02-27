#include "classdate.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

unsigned int Date::GetDay() {
    return day;
}

void Date::SetDay(unsigned int day) {
    if (month == 2) {
        if (day <= 28) {
            this.day = day;
        } else if (day == 29 && this.year % 4 == 0) {
            this.day = day;
        }

    } else if ((month % 2 == 1 && month <= 7) || (month % 2 == 0 && month >= 8)) {
        if (day <= 31) {
            this.day = day;
        }
    } else {
        if (day <= 30) {

        }
    }
}

unsigned int Date::GetMonth() {
    return month;
}

void Date::SetMonth(unsigned int month) {
    if (month >= 1 && month <= 12) {
        this->month = month;
    }
}

unsigned int Date::GetYear() {
    return year;
}

void Date::SetYear(unsigned int year) {
    if (year >= 2000 && year <= 2024) {
        this->year = year;
    }
}


Date::CompareDates(Date* firstDate, Date* secondDate) {
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