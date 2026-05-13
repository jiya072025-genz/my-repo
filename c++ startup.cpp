#include <iostream>
using namespace std;
class Date {
private:
    int day, month, year;
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    bool isValidDate(int d, int m, int y) {
        if (y < 1 || m < 1 || m > 12 || d < 1)
            return false;
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (isLeapYear(y))
            daysInMonth[1] = 29;
        if (d > daysInMonth[m - 1])
            return false;
        return true;
    }
public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(1), month(1), year(2000) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
        }
        else {
            cout << "Invalid date! Setting default date.\n";
        }
    }
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}
    Date& operator=(const Date& other) {
        if (this != &other) { 
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }
    ~Date() {
       
    }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d1;                      
    Date d2(29, 2, 2024);        
    Date d3(31, 2, 2023);        
    Date d4 = d2;                
    Date d5;
    d5 = d1;                    
    cout << "d1: "; d1.display();
    cout << "d2: "; d2.display();
    cout << "d3: "; d3.display();
    cout << "d4: "; d4.display();
    cout << "d5: "; d5.display();
    return 0;
}