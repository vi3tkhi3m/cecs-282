// Khiem Pham 
// CECS 282-01
// Program 5 - GoldRabbits
// Due date: 11/23/2020
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class BigInt {
private:
	vector<char> digits;

public:
	BigInt();
	BigInt(int n);
	BigInt(string n);
	BigInt operator+(BigInt n) const;
	BigInt operator+(int n) const;
	BigInt operator++(int n);
	BigInt operator-(BigInt n) const;
	BigInt operator-(int n) const;
	bool operator==(const BigInt& n) const;
	bool operator==(int n) const;
	bool operator<(const BigInt& n) const;
    bool operator>(const BigInt& n) const;
	bool operator<=(const BigInt& n) const;
	bool operator<=(int n) const;
	friend ostream& operator<<(ostream&, BigInt n);
	void print();
};

int goldRabbits(int);
BigInt goldRabbits(BigInt);
void pause() { cout << "\nPress Enter to continue..."; getchar(); }
void print(bool, BigInt&);

int main()
{
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);
	BigInt MAX(INT_MAX);
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;
	pause();
	cout << "\nB1:";
	B1.print();
	cout << endl;
	pause();

	for(BigInt i=0; i<=3000; i++)
	{
        goldRabbits(i);

        print(i < 8, i);
		if(i == 56)
			cout << "\n\n(some lines removed)\n";
        print(i > 55 && i <= 66, i);
		if(i == 2994)
			cout << "\n\n(many lines removed here)\n";
        print(i > 2993 && i <= 3000, i);
	}
	pause();

	cout << "\nThis is the value of goldRabbits(3000)\n\n";
	BigInt gR3000 = goldRabbits(BigInt(3000));
	gR3000.print();

	pause();

	int n = 500;
	try {

		cout << "The value of goldRabbits(n) is:" << goldRabbits(n) << endl;
	}
	catch (string error)
	{
		cout << error << endl;
		cout << "Transitioning to BigInt\n";
		cout << goldRabbits(BigInt(n));
	}

	pause();
	return 0;
}

int goldRabbits(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int a = goldRabbits(n - 1);
	int b = goldRabbits(n - 2);

	if (a > INT_MAX - b)
		throw string("Overflow Error - goldRabbits overflowed using " + std::to_string(n));

	return a + b;
}


BigInt goldRabbits(BigInt n)
{
	static map<BigInt, BigInt> bigIntMap;

	if (n == 0 || n == 1) {
		bigIntMap.insert({ n,BigInt(1) });
	}
	else {
		BigInt sum = bigIntMap[n - 1] + bigIntMap[n - 2];
		bigIntMap.insert({ n,sum });
	}
	
	return bigIntMap[n];
}

void print(bool condition, BigInt& i)
{
	if(condition)
        cout << "\ngoldRabbits(" << i << ") = " << goldRabbits(i);
}

BigInt::BigInt() :BigInt("0") {}

BigInt::BigInt(int n)
{
    const int CONVERSION = 10;
    do {
        digits.push_back(n % CONVERSION);
        n /= CONVERSION;
    } while (n != 0);
}

BigInt::BigInt(string n)
{
    for (int i = n.length() - 1; i >= 0; i--) {
        const int digit = n.at(i) - '0';
        digits.push_back(digit);
    }
}

bool BigInt::operator<(const BigInt& n) const
{
    if (digits.size() != n.digits.size())
        return (digits.size() < n.digits.size()) ? true : false;

    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != n.digits[i])
            return (digits[i] < n.digits[i]) ? true : false;
    }

    return false;
}

bool BigInt::operator>(const BigInt& n) const
{
    if (digits.size() != n.digits.size())
        return (digits.size() > n.digits.size()) ? true : false;

    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != n.digits[i])
            return (digits[i] > n.digits[i]) ? true : false;
    }

    return false;
}

bool BigInt::operator==(const BigInt& n) const
{
    bool result = false;

    if (digits.size() == n.digits.size())
    {
        result = true;
        for (int i = 0; i < digits.size(); i++)
            if (digits[i] != n.digits[i])
                result = false;
    }

    return result;
}

bool BigInt::operator==(const int n) const
{
    return (*this) == BigInt(n);
}

bool BigInt::operator<=(const BigInt& n) const
{
    return ((*this) == n || (*this) < n);
}

bool BigInt::operator<=(const int n) const
{
    return (*this) <= (BigInt(n));
}

BigInt BigInt::operator++(int n)
{
    *this = *this + 1;
    return *this;
}

BigInt BigInt::operator+(BigInt n) const
{
    BigInt temp(*this);

    while (temp.digits.size() != n.digits.size())
        (temp.digits.size() < n.digits.size()) ? temp.digits.push_back(0) : n.digits.push_back(0);

    int carry = 0;

    for (int i = 0; i < n.digits.size(); i++) {
        if (temp.digits[i] == 0 && n.digits[i] == 0 && i == carry != 0) {
            temp.digits[i] += carry;
            carry = 0;
        }

        temp.digits[i] += (n.digits[i] + carry);
        carry = 0;

        if (temp.digits[i] > 9) {
            carry++;
            temp.digits[i] %= 10;
            if (i == n.digits.size() - 1)
                temp.digits.push_back(carry);
        }
    }
    return temp;
}

BigInt BigInt::operator+(const int n) const
{
    return *this + BigInt(n);
}

BigInt BigInt::operator-(const BigInt n) const
{
    BigInt left = (*this);
    BigInt right = n;
    BigInt difference = left;

    while (left.digits.size() > right.digits.size())
        right.digits.push_back(0);

    for (int i = 0; i < left.digits.size(); i++) {
        if (left.digits[i] < right.digits[i]) {
            left.digits[i] = left.digits[i] + 10;
            left.digits[i + 1] = left.digits[i + 1] - 1;
        }

        difference.digits[i] = left.digits[i] - right.digits[i];

        if (left.digits[i] == 0 && right.digits[i] == 0 && i == left.digits.size() - 1)
            difference.digits.erase(difference.digits.end() - 1);
    }
	
    return difference;
}

BigInt BigInt::operator-(const int n) const
{
    return *this - BigInt(n);
}

ostream& operator<<(ostream&, BigInt n)
{
    const int SCIENTIFIC_NOTATION_SIZE = 12;
    const int length = n.digits.size();

    if (length > SCIENTIFIC_NOTATION_SIZE)
    {
        for (int i = length - 1; i >= length - (SCIENTIFIC_NOTATION_SIZE - 1); i--)
        {
            const int digit = n.digits[i];
            cout << digit;

            if (i == length - 1)
                cout << ".";
        }
        cout << "e" << length;
    }
    else
    {
        n.print();
    }

    return cout;
}

void BigInt::print()
{
    for (auto rit = digits.rbegin(); rit != digits.rend(); ++rit)
        cout << static_cast<int>(*rit);
}