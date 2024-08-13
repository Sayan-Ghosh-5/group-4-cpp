#include <iostream>
#include <stdexcept>
#include <ctime>    

class Date {
private:
    int day, month, year;
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) const {
        static const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && isLeapYear(year)) return 29;
        return days[month - 1];
    }

    void normalizeDate() {
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        while (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += daysInMonth(month, year);
        }
    }

public:
    
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        normalizeDate();
    }

    
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

   
    Date& operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    
    Date operator+(int daysToAdd) const {
        Date newDate = *this;
        newDate.day += daysToAdd;
        while (newDate.day > newDate.daysInMonth(newDate.month, newDate.year)) {
            newDate.day -= newDate.daysInMonth(newDate.month, newDate.year);
            newDate.month++;
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }
        return newDate;
    }

    
    operator int() const {
        int totalDays = 0;
        for (int m = 1; m < month; ++m) {
            totalDays += daysInMonth(m, year);
        }
        totalDays += day;
        return totalDays;
    }

    void print() const {
        std::cout << day << '/' << month << '/' << year << std::endl;
    }
};


int main() {
    Date dt1(28, 2, 2024); 
    Date dt2(1, 3, 2024);  
    
    dt1.print(); 
    dt2.print(); 
    
    std::cout << "dt1 < dt2: " << (dt1 < dt2) << std::endl; 
    std::cout << "dt1 <= dt2: " << (dt1 <= dt2) << std::endl; 
    std::cout << "dt1 > dt2: " << (dt1 > dt2) << std::endl; 
    std::cout << "dt1 >= dt2: " << (dt1 >= dt2) << std::endl;
    std::cout << "dt1 == dt2: " << (dt1 == dt2) << std::endl;
    std::cout << "dt1 != dt2: " << (dt1 != dt2) << std::endl;
    
    ++dt1;
    dt1.print(); 
    Date dt3 = dt1 + 5;
    dt3.print(); 
    int daysElapsed = static_cast<int>(dt3);
    std::cout << "Days elapsed in the year: " << daysElapsed << std::endl; 

    return 0;
}
