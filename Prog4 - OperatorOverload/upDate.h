// Khiem Pham 
// CECS 282-01
// Program 4 - Operator Overloading
// Due date: 11/2/2020
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef UPDATE_H
#define UPDATE_H
#include <string>

using namespace std;

class upDate {
private:
	const int DEFAULT_MONTH = 5;
	const int DEFAULT_DAY = 11;
	const int DEFAULT_YEAR = 1959;
	int* datePtr;
	static int counter;
	void increaseDate(int n);
	void decreaseDate(int n);
	bool isLeapYear(int year);
	bool isDateValid(int month, int day, int year);
	void Julian2Greg(int JD, int& month, int& day, int& year);

public:
	upDate();
	upDate(int M, int D, int Y);
	upDate(int J);
	upDate(const upDate& date);
	~upDate();
	void setDate(int M, int D, int Y);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	string getMonthName() const;
	static int GetDateCount();
	int julian() const;
	upDate operator=(const upDate& date);
    upDate operator+(int n) const;
    upDate operator-(int n) const;
    friend upDate operator+(int x, upDate& date);
    friend int operator- (upDate& date1, upDate& date2);
    friend ostream& operator<<(ostream& os, const upDate& dt);
    upDate operator++();
    upDate operator++(int);
    upDate operator--();
    upDate operator--(int);
	bool operator== (const upDate& date) const;
	bool operator!= (const upDate& date) const;
	bool operator> (const upDate& date) const;
	bool operator< (const upDate& date) const;
};

#endif