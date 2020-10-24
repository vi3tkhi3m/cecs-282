// Khiem Pham 
// CECS 282-01
// Program 3 - Student Struct
// Due date: 10/12/2020
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <string>

using namespace std;

// -----------------------------------------
//    Start constants
// -----------------------------------------

const int AMOUNT_OF_STUDENTS = 10;
const int STUDENT_ID_MIN_VALUE = 1000;
const int STUDENT_ID_MAX_VALUE = 9999;
const int DATE_MIN_MONTH = 1;
const int DATE_MAX_MONTH = 12;
const int DATE_MIN_DAY = 1;
const int DATE_MAX_DAY = 31;
const int DATE_MIN_YEAR = 2000;
const int DATE_MAX_YEAR = 2005;

// -----------------------------------------
//    End constants
// -----------------------------------------

// -----------------------------------------
//    Start myDate Class
// -----------------------------------------

class myDate {
private:
	int month;
	int day;
	int year;
	const int DEFAULT_MONTH = 5;
	const int DEFAULT_DAY = 11;
	const int DEFAULT_YEAR = 1959;
	string getMonthName(int month);

public:
	myDate();
	myDate(int month, int day, int year);
	void setDate(int month, int day, int year);
	int getMonth();
	int getDay();
	int getYear();
	string toString();
	int toJd();
};

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
bool isLeapYear(int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
			{
				return true;
			}
		}
		else {
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
bool isDateValid(int month, int day, int year)
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
	if (isDateValid(month, day, year))
	{
		this->month = month;
		this->day = day;
		this->year = year;
	}
	else {
		this->month = DEFAULT_MONTH;
		this->day = DEFAULT_DAY;
		this->year = DEFAULT_YEAR;
	}
}

void myDate::setDate(int month, int day, int year)
{
	this->month = month;
	this->day = day;
	this->year = year;
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
 * Converts the date to a string.
 *
 * @return The date in string.
 */
string myDate::toString()
{
	return getMonthName(this->month).append(" ").append(std::to_string(this->day).append(", ").append(std::to_string(this->year)));
}

/**
 * Converts the date to a julian date.
 *
 * @return Julian date.
 */
int myDate::toJd()
{
	return day - 32075 + 1461 * (this->year + 4800 + (this->month - 14) / 12) / 4 + 367 * (this->month - 2 - (this->month - 14) / 12 * 12) / 12 - 3 * ((this->year + 4900 + (this->month - 14) / 12) / 100) / 4;
}

// -----------------------------------------
//    End myDate Class
// -----------------------------------------

// -----------------------------------------
//    Start Student Struct
// -----------------------------------------

struct Student
{
	char name[25];
	int studentId;
	char grade;
	myDate birthday;
	string hometown;
};

// -----------------------------------------
//    End Student Struct
// -----------------------------------------

// -----------------------------------------
//    Start Generators
// -----------------------------------------

/**
 * Generates a random number in a range.
 *
 * @param min The min number of the range.
 * @param max The max number of the range.
 * @return returns a random number.
 */
int generateRandNumRange(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);

	return dis(gen);
}

char generateRandomGrade()
{
	const char grades[] = "ABCDEF";
	return grades[generateRandNumRange(0, strlen(grades)-1)];
}

set<int> generateRandomStudentIds()
{
	set<int> idSet;

	while (idSet.size() != AMOUNT_OF_STUDENTS)
	{
		idSet.insert(generateRandNumRange(STUDENT_ID_MIN_VALUE, STUDENT_ID_MAX_VALUE));
	}

	return idSet;
}

myDate generateRandomDate()
{
	myDate date;
	
	int month = generateRandNumRange(DATE_MIN_MONTH, DATE_MAX_MONTH);
	int day = generateRandNumRange(DATE_MIN_DAY, DATE_MAX_DAY);
	int year = generateRandNumRange(DATE_MIN_YEAR, DATE_MAX_YEAR);

	while (!isDateValid(month, day, year))
	{
		month = generateRandNumRange(DATE_MIN_MONTH, DATE_MAX_MONTH);
		day = generateRandNumRange(DATE_MIN_DAY, DATE_MAX_DAY);
		year = generateRandNumRange(DATE_MIN_YEAR, DATE_MAX_YEAR);
	}

	date.setDate(month, day, year);
	
	return date;
}

void populateArray(Student(&studentArray)[AMOUNT_OF_STUDENTS])
{
	const string names[AMOUNT_OF_STUDENTS] = { "Tim", "Kevin", "Ryan","Bas","Kees","Wesley","Peter","Yarince","Bjorn","SpongeBob" };
	const string homeTowns[AMOUNT_OF_STUDENTS] = { "Amsterdam", "Rotterdam", "Den Haag","Nijmegen","Arnhem","Almere","Tiel","Zutphen","Sneek","Bikini Bottom" };
	const set<int> sutdentIdsSet = generateRandomStudentIds();

	auto it = sutdentIdsSet.begin();

	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		myDate date = generateRandomDate();
		strcpy_s(studentArray[i].name, sizeof studentArray[i].name, names[i].c_str());
		studentArray[i].studentId = *it;
		studentArray[i].grade = generateRandomGrade();
		studentArray[i].birthday.setDate(date.getMonth(), date.getDay(), date.getYear());
		studentArray[i].hometown = homeTowns[i];
		it++;
	}
}

void populatePointer(Student studentArray[AMOUNT_OF_STUDENTS], Student* p[AMOUNT_OF_STUDENTS])
{
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		p[i] = &studentArray[i];
	}
}

// -----------------------------------------
//    End Generators
// -----------------------------------------

// -----------------------------------------
//    Start Sort Functions
// -----------------------------------------

void swap(Student** x, Student** y)
{
	Student* temp = *x;
	*x = *y;
	*y = temp;
}

void sortByName(Student* p[AMOUNT_OF_STUDENTS])
{
	int i, j;
	for (i = 0; i < AMOUNT_OF_STUDENTS - 1; i++)
		for (j = 0; j < AMOUNT_OF_STUDENTS - i - 1; j++)
			if (strcmp(p[j]->name, p[j + 1]->name) > 0)
				swap(&p[j], &p[j + 1]);
}

void sortByStudentId(Student* p[AMOUNT_OF_STUDENTS])
{
	int i, j;
	for (i = 0; i < AMOUNT_OF_STUDENTS - 1; i++)
		for (j = 0; j < AMOUNT_OF_STUDENTS - i - 1; j++)
			if (p[j]->studentId > p[j + 1]->studentId)
				swap(&p[j], &p[j + 1]);
}

void sortByGrade(Student* p[AMOUNT_OF_STUDENTS])
{
	int i, j;
	for (i = 0; i < AMOUNT_OF_STUDENTS - 1; i++)
		for (j = 0; j < AMOUNT_OF_STUDENTS - i - 1; j++)
			if (p[j]->grade > p[j + 1]->grade)
				swap(&p[j], &p[j + 1]);
}

void sortByBirthday(Student* p[AMOUNT_OF_STUDENTS])
{
	int i, j;
	for (i = 0; i < AMOUNT_OF_STUDENTS - 1; i++)
		for (j = 0; j < AMOUNT_OF_STUDENTS - i - 1; j++)
			if (p[j]->birthday.toJd() > p[j + 1]->birthday.toJd())
				swap(&p[j], &p[j + 1]);
}

void sortByHomeTown(Student* p[AMOUNT_OF_STUDENTS])
{
	int i, j;
	for (i = 0; i < AMOUNT_OF_STUDENTS - 1; i++)
		for (j = 0; j < AMOUNT_OF_STUDENTS - i - 1; j++)
			if (p[j]->hometown > p[j + 1]->hometown)
				swap(&p[j], &p[j + 1]);
}

// -----------------------------------------
//    End Sort Functions
// -----------------------------------------

// -----------------------------------------
//    Start Commandline Interface Code
// -----------------------------------------
void showMenu()
{
	cout << "\033[1;36mWelcome to Student Struct! Please choose one of the following options:\033[0m\n";
	cout << "1) Display list sorted by Name\n";
	cout << "2) Display list sorted by Student ID\n";
	cout << "3) Display list sorted by Grade\n";
	cout << "4) Display list sorted by Birthday\n";
	cout << "5) Display list sorted by Home Town\n";
	cout << "6) Exit\n";
}

void showInvalidInputErrorMessage()
{
	std::cout << "\033[1;31mPlease enter a valid number (1-6):\033[0m\n";
}


void showStudentList(Student* stuPtr[10])
{
	cout << endl;
	cout << left << setw(20) << "Name" << setw(15) << "Student ID" << setw(10) << "Grade" << setw(25) << "Birthday" << setw(20) << "Home Town" << endl;
	cout << left << setw(20) << "----" << setw(15) << "----------" << setw(10) << "-----" << setw(25) << "--------" << setw(20) << "---------" << endl;
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		cout << left << setw(20) << stuPtr[i]->name << setw(15) << stuPtr[i]->studentId << setw(10) << stuPtr[i]->grade << setw(25) << stuPtr[i]->birthday.toString() << setw(20) << stuPtr[i]->hometown << endl;
	}
	cout << endl;
}

void showSelectedInputMessage(int input, string filter)
{
	cout << "\033[1;32mYou have selected " << input <<". List will be ordered by " << filter <<":\033[0m\n";
}

// -----------------------------------------
//    End Commandline Interface Code
// -----------------------------------------

void runStudentStructProgram()
{
	Student studentArray[AMOUNT_OF_STUDENTS];
	Student* stuPtr[AMOUNT_OF_STUDENTS];

	populateArray(studentArray);
	populatePointer(studentArray, stuPtr);

	bool run = true;

	while(run)
	{
		showMenu();

		int input;
		std::cin >> input;

		while (std::cin.fail() || input > 6 || input <= 0) {
			showInvalidInputErrorMessage();
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> input;
		}

		system("CLS");

		switch (input)
		{
			case 1:
				showSelectedInputMessage(input, "name");
				sortByName(stuPtr);
				break;
			case 2:
				showSelectedInputMessage(input, "student ID");
				sortByStudentId(stuPtr);
				break;
			case 3:
				showSelectedInputMessage(input, "grade");
				sortByGrade(stuPtr);
				break;
			case 4:
				showSelectedInputMessage(input, "birthday");
				sortByBirthday(stuPtr);
				break;
			case 5:
				showSelectedInputMessage(input, "home town");
				sortByHomeTown(stuPtr);
				break;
			case 6:
				run = false;
				break;
			default:
				showInvalidInputErrorMessage();
				break;
		}

		if(input > 0 && input < 6)
		{
			showStudentList(stuPtr);
		}
	}
}

int main()
{
	runStudentStructProgram();

	return 0;
}
