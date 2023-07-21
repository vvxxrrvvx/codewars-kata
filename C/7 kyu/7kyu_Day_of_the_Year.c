#include stdbool.h

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0)  (year % 400 == 0);
}

int get_day_of_year(const int date[3]) {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = date[0];
    int month = date[1];
    int year = date[2];
    
    if (isLeapYear(year)) {
        monthDays[1] = 29;  February has 29 days in a leap year
    }
    
    int dayOfYear = 0;
    for (int i = 0; i  month - 1; i++) {
        dayOfYear += monthDays[i];
    }
    
    dayOfYear += day;
    
    return dayOfYear;
}