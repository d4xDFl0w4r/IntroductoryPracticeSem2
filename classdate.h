#ifndef CLASSDATE_H
#define CLASSDATE_H

class Date {
public:
    Date(int day, int month, int year);
    ~Date();

    int GetDay();
    void SetDay(int day);
    int GetMonth();
    void SetMonth(int month);
    int GetYear();
    void SetYear(int year);

    static int CompareDates(Date* firstDate, Date* secondDate);

private:
    int day;
    int month;
    int year;
};

#endif // CLASSDATE_H