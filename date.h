#ifndef CLASSDATE_H
#define CLASSDATE_H

class Date {
public:
    Date(unsigned int day, unsigned int month, unsigned int year);
    ~Date();

    unsigned int GetDay();
    void SetDay(unsigned int day);
    unsigned int GetMonth();
    void SetMonth(unsigned int month);
    unsigned int GetYear();
    void SetYear(unsigned int year);

    static int CompareDates(Date* firstDate, Date* secondDate);

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

#endif // CLASSDATE_H