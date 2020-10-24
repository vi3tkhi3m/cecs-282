// Khiem Pham 
// CECS 282-01
// Program 2 - myDate
// Due date: 9/28/2020
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <string>
#ifndef MYDATE_H
#define MYDATE_H

using namespace std;

class myDate {
private:
	int month;
	int day;
	int year;
	const int DEFAULT_MONTH = 5;
	const int DEFAULT_DAY = 11;
	const int DEFAULT_YEAR = 1959;
	string getMonthName(int month);
	bool isLeapYear(int year);
	bool isDateValid(int m, int d, int y);

public:
	myDate();
	myDate(int month, int day, int year);
	void display();
	void increaseDate(int n);
	void decreaseDate(int n);
	int daysBetween(myDate date);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayName();
};

#endif


