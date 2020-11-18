// Khiem Pham 
// CECS 282-01
// Program 4 - Operator Overloading
// Due date: 11/2/2020
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "upDate.h"
#include <iostream>

using namespace std;

int upDate::counter = 0;

void upDate::increaseDate(int n)
{
	Julian2Greg(julian() + n, datePtr[0], datePtr[1], datePtr[2]);
}

void upDate::decreaseDate(int n)
{
	Julian2Greg(julian() - n, datePtr[0], datePtr[1], datePtr[2]);
}

bool upDate::isLeapYear(int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
			{
				return true;
			}
		} else {
			return true;
		}
	}
	return false;
}

bool upDate::isDateValid(int month, int day, int year)
{
	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > 31)
		return false;

	if (month == 2)
	{
		if (isLeapYear(year))
		{
			return (day <= 29);
		}
		return (day <= 28);
	}

	// April, June, Sept and Nov should have 30 or less.
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);

	return true;
}

string upDate::getMonthName() const
{
	string monthName;

	switch (datePtr[0]) {
		case 1:
			monthName = "January";
			break;
		case 2:
			monthName = "February";
			break;
		case 3:
			monthName = "March";
			break;
		case 4:
			monthName = "April";
			break;
		case 5:
			monthName = "May";
			break;
		case 6:
			monthName = "June";
			break;
		case 7:
			monthName = "July";
			break;
		case 8:
			monthName = "August";
			break;
		case 9:
			monthName = "September";
			break;
		case 10:
			monthName = "October";
			break;
		case 11:
			monthName = "November";
			break;
		case 12:
			monthName = "December";
			break;
		default:
			monthName = "Unknown";
			break;
	}

	return monthName;
}

void upDate::Julian2Greg(int JD, int& month, int& day, int& year)
{
	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}

int upDate::julian() const
{
	const int month = datePtr[0];
	const int day = datePtr[1];
	const int year = datePtr[2];
	return day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
}

upDate::upDate() : upDate(DEFAULT_MONTH, DEFAULT_DAY, DEFAULT_YEAR) { }

upDate::upDate(int M, int D, int Y)
{
	datePtr = new int[3];
	setDate(M, D, Y);
	counter++;
}

upDate::upDate(int J)
{
	Julian2Greg(J, datePtr[0], datePtr[1], datePtr[2]);
	counter++;
}

upDate::upDate(const upDate& date) : upDate(date.datePtr[0], date.datePtr[1], date.datePtr[2]) { }

upDate::~upDate()
{
	delete[] datePtr;
	counter--;
}

void upDate::setDate(int M, int D, int Y)
{
	if (isDateValid(M, D, Y))
	{
		datePtr[0] = M;
		datePtr[1] = D;
		datePtr[2] = Y;
	}
	else {
		datePtr[0] = DEFAULT_MONTH;
		datePtr[1] = DEFAULT_DAY;
		datePtr[2] = DEFAULT_YEAR;
	}
}

int upDate::getMonth() const
{
	return datePtr[0];
}

int upDate::getDay() const
{
	return datePtr[1];
}

int upDate::getYear() const
{
	return datePtr[2];
}

upDate upDate::operator=(const upDate& date)
{
	setDate(date.getMonth(), date.getDay(), date.getYear());
	return *this;
}

upDate upDate::operator+(const int n) const
{
	upDate temp(*this);
	temp.increaseDate(n);
	return temp;
}

upDate upDate::operator-(const int n) const
{
	upDate temp(*this);
	temp.decreaseDate(n);
	return temp;
}

upDate operator+(int x, upDate& date)
{
	return date + x;
}

int operator-(upDate& date1, upDate& date2)
{
	return date1.julian() - date2.julian();
}

ostream& operator<<(ostream& os, const upDate& dt)
{
	os << dt.getMonth() << "/" << dt.getDay() << "/" << dt.getYear();
	return os;
}

bool upDate::operator==(const upDate& date) const
{
	return julian() == date.julian();
}

bool upDate::operator!=(const upDate& date) const
{
	return !(*this == date);
}

bool upDate::operator>(const upDate& date) const
{
	return julian() > date.julian();
}

bool upDate::operator<(const upDate& date) const
{
	return julian() < date.julian();
}

upDate upDate::operator++()
{
	increaseDate(1);
	return *this;
}

upDate upDate::operator++(int)
{
	increaseDate(1);
	return *this;
}

upDate upDate::operator--()
{
	decreaseDate(1);
	return *this;
}

upDate upDate::operator--(int)
{
	decreaseDate(1);
	return *this;
}


int upDate::GetDateCount()
{
	return counter;
}
