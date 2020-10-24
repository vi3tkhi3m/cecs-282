// Khiem Pham 
// CECS 282-01
// Program 2 - myDate
// Due date: 9/28/2020
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "myDate.h"
#include <iostream>

using namespace std;

/**
 * Converts a gregorian date to a julian date
 *
 * @param month Gregorian month.
 * @param day Gregorian day.
 * @param year Gregorian year.
 * @return the julian date.
 */
int Greg2Julian(int month, int day, int year)
{
	return day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
}

/**
 * Converts a julian date to a gregorian date with pass by reference.
 *
 * @param JD The julian date.
 * @param month The pass by reference month.
 * @param day The pass by reference day.
 * @param year The pass by reference year.
 */
void Julian2Greg(int JD, int& month, int& day, int& year)
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

/**
 * Converts a the month number to a month name.
 *
 * @param month The month number.
 * @return the month name.
 */
string myDate::getMonthName(int month)
{
    string monthName;

    switch (month) {
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

/**
 * Checks if the given year is a leap year.
 *
 * @param year The year.
 * @return returns true if the given year is a leap year, else returns false.
 */
bool myDate::isLeapYear(int year)
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

/**
 * Checks if the given date is a valid date.
 *
 * @param month The month number.
 * @param day The day number.
 * @param year The year number.
 * @return returns true if the date is valid, else returns false.
 */
bool myDate::isDateValid(int month, int day, int year)
{
	const int MAX_VALID_YR = 9999;
	const int MIN_VALID_YR = 0;

	// Checks if year, month and day are between values.
	if (year > MAX_VALID_YR || year < MIN_VALID_YR)
		return false;

	if (month < 1 || month > 12)
		return false;
	
	if (day < 1 || day > 31)
		return false;

	// Handle leap year.
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

/**
 * Default constructor
 *
 * Sets the date to 5/11/1959
 */
myDate::myDate()
{
	month = DEFAULT_MONTH;
	day = DEFAULT_DAY;
	year = DEFAULT_YEAR;
}

/**
 * Overloaded constructor
 *
 * If the given date is valid, it will set the date, else it will set the date to default 5/11/1959.
 *
 * @param month The month number.
 * @param day The day number.
 * @param year The year number.
 */
myDate::myDate(int month, int day, int year)
{
	if(isDateValid(month,day,year))
	{
		this->month = month;
		this->day = day;
		this->year = year;
	} else {
		this->month = DEFAULT_MONTH;
		this->day = DEFAULT_DAY;
		this->year = DEFAULT_YEAR;
	}
}

/**
 * Prints the date.
 */
void myDate::display()
{
    cout << getMonthName(month) << ' ' << day << ", " << year;
}

/**
 * Increases the date by the amount of days.
 *
 * @param n The amount of days to increase.
 */
void myDate::increaseDate(int n)
{
	int jd = Greg2Julian(month, day, year) + n;
	Julian2Greg(jd, month, day, year);
}	

/**
 * Decreases the date by the amount of days.
 *
 * @param n The amount of days to decrease.
 */
void myDate::decreaseDate(int n)
{
	int jd = Greg2Julian(month, day, year) - n;
	Julian2Greg(jd, month, day, year);
}

/**
 * Calculates the days between this date and the given date. It will return an absolute value. So for example -31 will be 31.
 *
 * @param date myDate object.
 * @return The amount of days difference between this date and the given date.
 */
int myDate::daysBetween(myDate date)
{
	int jd1 = Greg2Julian(month, day, year);
	int jd2 = Greg2Julian(date.getMonth(), date.getDay(), date.getYear());
	return abs(jd1-jd2);
}

/**
 * Gets the month.
 *
 * @return The month.
 */
int myDate::getMonth()
{
	return month;
}

/**
 * Gets the day.
 *
 * @return The day.
 */
int myDate::getDay()
{
	return day;
}

/**
 * Gets the year.
 *
 * @return The year.
 */
int myDate::getYear()
{
	return year;
}

/**
 * This will get the day number of this date.
 *
 * @return The day number.
 */
int myDate::dayOfYear()
{
	// [0] is the day count for a non-leap year
	// [1] is the day count for a leap year
	const int DAYS_TO_MONTH[2][12] =
	{
		{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 },
		{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 },
	};
	return DAYS_TO_MONTH[isLeapYear(year)][month-1] + day;
}

/**
 * This will get the day of the week.
 *
 * @return The day of the week.
 */
string myDate::dayName()
{
	string dayName;
	const int AMOUNT_OF_DAYS_IN_A_WEEK = 7;
	int dayModuloNumber = Greg2Julian(month, day, year) % AMOUNT_OF_DAYS_IN_A_WEEK;

	switch (dayModuloNumber) {
		case 0:
			dayName = "Monday";
			break;
		case 1:
			dayName = "Tuesday";
			break;
		case 2:
			dayName = "Wednesday";
			break;
		case 3:
			dayName = "Thursday";
			break;
		case 4:
			dayName = "Friday";
			break;
		case 5:
			dayName = "Saturday";
			break;
		case 6:
			dayName = "Sunday";
			break;
		default:
			dayName = "Unknown";
			break;
	}

	return dayName;
}
