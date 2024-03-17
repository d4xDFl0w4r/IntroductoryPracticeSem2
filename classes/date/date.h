#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    Date();

    unsigned int getDay();
    void setDay(unsigned int newDay);
    unsigned int getMonth();
    void setMonth(unsigned int newMonth);
    unsigned int getYear();
    void setYear(unsigned int newYear);

    std::string GetDateAsString();

    static int CompareDates(Date* firstDate, Date* secondDate);

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

#endif // DATE_H
