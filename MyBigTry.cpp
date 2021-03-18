#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
using namespace std;
// M - 1
// My Input and Output will be given as string.
// For calculation, we convert string into vector. And result will be stored in vector, we convert it into string for output.

// For user, BigInt is a data type.

// M - 2  #define   vector<short>   BigInt

// M - 3  class BigInt   Best Approach

// In this file, we use method - 3.

// +Infinit  = BigInt_Max
// -Infinite = BigInt_Min

// Utility Class

class Exception : public runtime_error
{
	public :
		Exception() : runtime_error ("Math error : Attempted to divide by zero...\n")
		{

		}
};




//			Utility Functions and Templates
template <class Type>
int digitCount (Type number)
{
	if (!number)
		return 1;
	int digit = 0;
	while (number)
	{
		digit++;
		number /= 10;
	}
	return digit;
}

// This utility function takes absolute value (data part of BigInt object) as an argument
bool lessThan (string number1, string number2)		//    n1 < n2
{
	unsigned long length1 = number1.length(), length2 = number2.length();
	if (length1 < length2)
		return true;
	else if (length1 > length2)
		return false;
	else
	{
		for (unsigned long i = 0; i < length1; i++)
		{
			if (number1[i] < number2[i])
				return true;
			else if (number1[i] > number2[i])
				return false;
		}
		return false;
	}
}


// This utility function takes absolute value (data part of BigInt objects) as an argument
string addition (string num1, string num2)
{
	vector<short> v1, v2, sum;

	// Push Values from string to vector
	for (auto itr1 : num1)
		v1.push_back (itr1 - '0');
	for (auto itr2 : num2)
		v2.push_back (itr2 - '0');

	// Reverse both vectors
	reverse (v1.begin(), v1.end());
	reverse (v2.begin(), v2.end());

	long long int len = (v1.size() > v2.size()) ? v2.size() : v1.size();

	int carry = 0;
	int i = 0;
	for (i; i < len; i++)
	{
		int current_sum = v1[i] + v2[i] + carry;
		carry = current_sum / 10;

		sum.push_back (current_sum % 10);
	}

	while (carry)				//    827 + 299999458,          827 + 99999458
	{
		if (v1.size() != len)
		{
			int current_sum = v1[i++] + carry;
			sum.push_back (current_sum % 10);
			carry = current_sum / 10;
		}
		else if (v2.size() != len)
		{
			int current_sum = v2[i++] + carry;
			sum.push_back (current_sum % 10);
			carry = current_sum / 10;
		}
		else
		{
			sum.push_back (carry);
			carry /= 10;
		}
	}

	while (v1.size() != len && v1.size() > i)
	{
		int current_sum = v1[i++] + carry;
		sum.push_back (current_sum % 10);
		carry = current_sum / 10;
	}

	while (v2.size() != len && v2.size() > i)
	{
		int current_sum = v2[i++] + carry;
		sum.push_back (current_sum % 10);
		carry = current_sum / 10;
	}

	while (sum.size() != 1 && sum[sum.size() - 1] == 0)
		sum.pop_back();

	reverse (sum.begin(), sum.end());

	string result = "";
	for (auto it : sum)
		result += (it + '0');

	return result;
}

string subtract (string num1, string num2)			// num1 ~ num2   is same as  |num1 - num2|
{
	// Check for bigger and smaller
	string bigger = lessThan (num1, num2) ? num2 : num1;
	string smaller = lessThan (num1, num2) ? num1 : num2;

	vector<short> vb, vs, diff;		// vb for big vector,	vs for small vector

	// Push Values from string to vector
	for (auto itr1 : bigger)
		vb.push_back (itr1 - '0');
	for (auto itr2 : smaller)
		vs.push_back (itr2 - '0');

	// Reverse both vectors
	reverse (vb.begin(), vb.end());
	reverse (vs.begin(), vs.end());

	long long int min_len = (vb.size() > vs.size()) ? vs.size() : vb.size();

	long long int borrow  = 0;
	long long int i = 0;

	for (i; i < min_len; i++)
	{
		if (vb[i] < vs[i])		// Reversed Form :	500007 - 8
		{
			int save = i;	// Save variable stores position of that index, which takes borrow.

			while (vb[i + 1] == 0)
				i++;

			vb[i + 1]--;
			borrow = 1;

			while (vb[i] == 0 && save != i)
			{
				vb[i] = 9;
				i--;
			}


			diff.push_back (10 * borrow + vb[i] - vs[i]);
		}
		else
			diff.push_back (vb[i] - vs[i]);
	}

	for (i; i < vb.size(); i++)
		diff.push_back (vb[i]);

	while (diff.size() != 1 && diff[diff.size() - 1] == 0)
		diff.pop_back();

	reverse (diff.begin(), diff.end());

	string result = "";
	for (auto it : diff)
		result += (it + '0');

	return result;
}

string multiply (string num1, string num2)
{
	// Check for bigger and smaller
	// Here we do not need to check values
	string bigger = (num1.length() <= num2.length()) ? num2 : num1;
	string smaller = (num1.length() <= num2.length()) ? num1 : num2;

	vector<short> vb, vs;		// vb for big size vector,	vs for small size vector

	// Push Values from string to vector
	for (auto itr1 : bigger)
		vb.push_back (itr1 - '0');
	for (auto itr2 : smaller)
		vs.push_back (itr2 - '0');

	// Reverse both vectors
	reverse (vb.begin(), vb.end());
	reverse (vs.begin(), vs.end());

	long long int min_len = (vb.size() > vs.size()) ? vs.size() : vb.size();
	long long int i = 0;
	long long int carry = 0;

	vector<short> vtemp_mul;
	string mul = "0";

	for (int i = 0; i < min_len; i++)
	{
		long long int  maintain_zero = i;

		while (maintain_zero--)
			vtemp_mul.push_back (0);

		for (int j = 0; j < vb.size(); j++)
		{
			long long int current = vs[i] * vb[j] + carry;
			carry = current / 10;
			vtemp_mul.push_back (current % 10);
		}

		while (carry)
		{
			vtemp_mul.push_back (carry % 10);
			carry = carry / 10;
		}

		while (vtemp_mul.size() != 1 && vtemp_mul[vtemp_mul.size() - 1] == 0)
			vtemp_mul.pop_back();

		reverse (vtemp_mul.begin(), vtemp_mul.end());

		// Convert vtemp_mul to string to perform addition
		string temp_mul = "";
		for (auto itr : vtemp_mul)
			temp_mul.push_back (itr + '0');

		mul = addition (mul, temp_mul);

		vtemp_mul.clear();
		vtemp_mul.shrink_to_fit();
	}

	return mul;
}


/*			Terminology
	dividend = Bhaajya
	divisor = Bhaajak
	Quotient = Bhaagfal
	remainder = Sheshfal

	Dividend = Divisor * Quotient + Remainder
*/

string division (string num1, string num2)
{
	string result = "0";
	string mulTable[11];
	if (num2 == "0")
		throw Exception();
	else if (num1 == "0")
		return result;
	else if (lessThan (num1, num2))
		return result;
	else
	{
		for (int i = 0; i < 11; i++)
		{
			string multiplier = to_string (i);
			mulTable[i] = multiply (num2, multiplier);
		}

		int minLength = num2.length(), maxLength = num1.length();

		string tempDividend = "";
		for (int i = 0; i < minLength; i++)
			tempDividend += num1[i];

		string partialDividend = tempDividend;

		string ratio = "0";
		string multiplier = "10";

		for (int i = minLength + 1; i <= maxLength + 1; i++)
		{
			int count = 0;
			while (lessThan (mulTable[count], partialDividend))
				count++;
			if (mulTable[count] != partialDividend)
				count--;
			string counter = to_string (count);
			ratio = addition (multiply (ratio, multiplier), counter);
			if (!count)
			{
				string nextDigit = "";
				nextDigit += num1[i - 1];
				partialDividend = addition (multiply (partialDividend, multiplier), nextDigit);
			}
			else
			{
				partialDividend = subtract (partialDividend, mulTable[count]);

				string nextDigit = "";
				nextDigit += num1[i - 1];
				partialDividend = addition (multiply (partialDividend, multiplier), nextDigit);
			}
		}
		result = ratio;
	}
	return result;
}









/*
	How to define zero :- b == "0" && sign == "zero"
*/


class BigInt
{
	public :
		// Members
		string data;		// It stores data/value of big integer.
		string sign;		// It stores sign of big integer.

		// Default Constructor
		BigInt()
		{
			data = "0";
			sign = "zero";
		}

		/*	Note :- Here we do not need to create constructor for short and char.
			Due to type casting of argument, it will call constructor of int type.
		*/

		// Constructor To Convert int to BigInt
		BigInt (int num)
		{
			if (num < 0)
			{
				sign = "negative";
				num *= -1;			// If number is negative, then make it positive.
			}
			else if (num > 0)
				sign = "positive";
			else
				sign = "zero";

			int dig = digitCount<int> (num);

			if (!num)
				data = "0";
			while (num)
			{
				char rem = num % 10;
				data.push_back (rem + '0');
				num /= 10;
			}
			reverse (data.begin(), data.end());
		}

		// Constructor To Convert long long int to BigInt
		BigInt (long long int num)
		{
			if (num < 0)
			{
				sign = "negative";
				num *= -1;			// If number is negative, then make it positive.
			}
			else if (num > 0)
				sign = "positive";
			else
				sign = "zero";

			int dig = digitCount<int> (num);

			if (!num)
				data = "0";
			while (num)
			{
				char rem = num % 10;
				data.push_back (rem + '0');
				num /= 10;
			}
			reverse (data.begin(), data.end());
		}

		// Constructor To Convert string to BigInt
		BigInt (string str)
		{
			sign = "positive";
			if (str[0] == '-')
			{
				sign = "negative";
				str.erase (0, 1);
			}

			while (str[1] != '\0' && str[0] == '0')
				str.erase (0, 1);

			if (str.length() == 1 && str[0] == '0')
				sign = "zero";
			data = str;
		}

		// Constructor To Convert const char* to BigInt
		BigInt (const char* str)
		{
			int flag = 0;
			sign = "positive";
			if (str[0] == '-')
			{
				sign = "negative";
				flag = 1;
			}

			char *temp = (char *) calloc (strlen (str) + 1, sizeof (char));
			strcpy (temp, str + flag);

			unsigned int i = 0;
			while (temp[i + 1] != '\0' && temp[i] == '0')
				i++;

			char *number = (char *) calloc (strlen (temp + i) + 1, sizeof (char));
			strcpy (number, temp + i);
			if (strlen (number) == 1 && number[0] == '0')
				sign = "zero";

			data = number;

			free (temp);
			free (number);
		}

		// Constructor To Convert float to BigInt
		BigInt (float f)
		{
			long long int num = f;
			if (num < 0)
			{
				sign = "negative";
				num *= -1;			// If number is negative, then make it positive.
			}
			else if (num > 0)
				sign = "positive";
			else
				sign = "zero";

			int dig = digitCount<int> (num);

			if (!num)
				data = "0";
			while (num)
			{
				char rem = num % 10;
				data.push_back (rem + '0');
				num /= 10;
			}
			reverse (data.begin(), data.end());
		}

		// Constructor To Convert Double to BigInt
		BigInt (double f)
		{
			long long int num = f;
			if (num < 0)
			{
				sign = "negative";
				num *= -1;			// If number is negative, then make it positive.
			}
			else if (num > 0)
				sign = "positive";
			else
				sign = "zero";

			int dig = digitCount<int> (num);

			if (!num)
				data = "0";
			while (num)
			{
				char rem = num % 10;
				data.push_back (rem + '0');
				num /= 10;
			}
			reverse (data.begin(), data.end());
		}

		// Constructor To Convert Long Double to BigInt
		BigInt (long double f)
		{
			long long int num = f;
			if (num < 0)
			{
				sign = "negative";
				num *= -1;			// If number is negative, then make it positive.
			}
			else if (num > 0)
				sign = "positive";
			else
				sign = "zero";

			int dig = digitCount<int> (num);

			if (!num)
				data = "0";
			while (num)
			{
				char rem = num % 10;
				data.push_back (rem + '0');
				num /= 10;
			}
			reverse (data.begin(), data.end());
		}



		//	Destructor
		~BigInt()
		{

		}

		// Assignment Operator
		void operator = (const BigInt&);

		// Mathematical Operator
		BigInt operator + (const BigInt&);
		BigInt operator - (const BigInt&);
		BigInt operator * (const BigInt&);
		BigInt operator / (const BigInt&);
		BigInt operator % (const BigInt&);

		// Mathematical and Assignment Operator
		void operator += (const BigInt&);
		void operator -= (const BigInt&);
		void operator *= (const BigInt&);
		void operator /= (const BigInt&);
		void operator %= (const BigInt&);

		// Pre and Post Operator Overloading
		BigInt& operator ++ ();			// Prefix
		BigInt& operator -- ();			// Prefix
		BigInt operator ++ (int);		// Postfix
		BigInt operator -- (int);		// Postfix

		// Unary Minus Operator Overloading
		BigInt operator - ();

		// Conditional Operator
		bool operator == (const BigInt&);
		bool operator != (const BigInt&);
		bool operator < (const BigInt&);
		bool operator <= (const BigInt&);
		bool operator > (const BigInt&);
		bool operator >= (const BigInt&);


		// Utility
		BigInt BigAbs ();
		BigInt Factorial ();
		bool IsPalindrome ();
		bool IsPrime ();			// TODO
};


//		Operator Overloading
void BigInt::operator = (const BigInt& b2)
{
	this->data = b2.data;
	this->sign = b2.sign;
	return;
}


BigInt BigInt::operator + (const BigInt& b2)
{
	BigInt sum;
	if (this->sign == "zero")
		sum = b2;
	if (b2.sign == "zero")
		sum = *this;
	if (this->sign != "zero" && b2.sign != "zero")
	{
		if (this->sign == b2.sign)
		{
			sum.data = addition (this->data, b2.data);
			sum.sign = this->sign;
		}
		else
		{
			if (this->data == b2.data)
			{
				BigInt temp (0);
				sum = temp;
			}
			else
			{
				sum.data = subtract (this->data, b2.data);
				if (lessThan (this->data, b2.data))	// Here do not use < or > operator because it compares string lexicographical
					sum.sign = b2.sign;
				else
					sum.sign = this->sign;
			}
		}
	}
	return sum;
}


BigInt BigInt::operator - (const BigInt& b2)
{
	BigInt result;
	if (b2.sign == "zero")
		result = *this;
	if (this->sign == "zero" && b2.sign != "zero")
	{
		result = b2;
		result.sign = "positive";
		if (b2.sign == "positive")
			result.sign = "negative";
	}
	if (this->sign != "zero" && b2.sign != "zero")
	{
		if (this->sign != b2.sign)
		{
			result.data = addition (this->data, b2.data);
			result.sign = this->sign;
		}
		else
		{
			result.data = subtract (this->data, b2.data);
			if (this->data == b2.data)
				result.sign = "zero";
			else if (lessThan (this->data, b2.data))
			{
				// Here do not use < or > operator because it compares string lexicographically.
				result.sign = "positive";
				if (this->sign == "positive")
					result.sign = "negative";
			}
			else
				result.sign = this->sign;
		}
	}
	return result;
}


BigInt BigInt::operator * (const BigInt& b2)
{
	BigInt result;

	if (this->sign == "zero" || b2.sign == "zero")
		return result;
	else if (this->sign == b2.sign)
	{
		result.sign = "positive";
		result.data = multiply (this->data, b2.data);
	}
	else
	{
		result.sign = "negative";
		result.data = multiply (this->data, b2.data);
	}
	return result;
}


BigInt BigInt::operator / (const BigInt& b2)
{
	BigInt result;
	try
	{
		result.data = division (this->data, b2.data);
	}
	catch (Exception& e)
	{
		cerr << "Runtime Exception Occurred : Division By Zero in operation ";
		cerr << "\"" << this->data << " / " << b2.data << "\"" << endl;
		cout << e.what();
		exit (0);
	}

	(this->sign == b2.sign) ? result.sign = "positive" : result.sign = "positive";

	result.sign = "negative";
	if (this->sign == b2.sign)
		result.sign = "positive";

	return result;
}

BigInt BigInt::operator % (const BigInt& b2)
{
	string quotient;
	try
	{
		quotient = division (this->data, b2.data);
	}
	catch (Exception& e)
	{
		cerr << "Runtime Exception Occurred : Modulo By Zero in operation ";
		cerr << "\"" << this->data << " % " << b2.data << "\"" << endl;
		exit (0);
	}

	BigInt result;

	if (this->sign == "negative")
		result.sign = "negative";
	else
		result.sign = "positive";

	result.data = subtract (this->data, multiply (quotient, b2.data));

	return result;
}


//	+=     -=     *=    /=    %=
void BigInt::operator += (const BigInt& b2)
{
	*this = *this + b2;
}

void BigInt::operator -= (const BigInt& b2)
{
	*this = *this - b2;
}

void BigInt::operator *= (const BigInt& b2)
{
	*this = *this * b2;
}

void BigInt::operator /= (const BigInt& b2)
{
	*this = *this / b2;
}

void BigInt::operator %= (const BigInt& b2)
{
	*this = *this % b2;
}

BigInt& BigInt::operator ++ ()				// Prefix
{
	*this += 1;
	return *this;
}

BigInt& BigInt::operator -- ()				// Prefix
{
	*this -= 1;
	return *this;
}

BigInt BigInt::operator ++ (int unUsed)		// Postfix
{
	BigInt temp (*this);
	*this += 1;
	return temp;
}

BigInt BigInt::operator -- (int unUsed)		// Postfix
{
	BigInt temp (*this);
	*this -= 1;
	return temp;
}


BigInt BigInt::operator - ()				// Unary Minus
{
	BigInt temp;

	temp.data = this->data;

	if(this->sign == "zero")
		temp.sign = "zero";
	else if(this->sign == "positive")
		temp.sign = "negative";
	else
		temp.sign = "positive";

	return temp;
}

/*
	==,  !=,  >    <    >=     <=
*/

bool BigInt::operator == (const BigInt& b2)
{
	if ((this->sign == b2.sign) && (this->data == b2.data))
		return true;
	return false;
}

bool BigInt::operator != (const BigInt& b2)
{
	if (*this == b2)
		return false;
	return true;
}

bool BigInt::operator < (const BigInt& b2)
{
	if (this->sign == "negative" && (b2.sign == "positive" || b2.sign == "zero"))
		return true;
	else if (this->sign == "zero" && b2.sign == "positive")
		return true;
	else if (this->sign == "negative" && b2.sign == "negative" &&
			 !lessThan (this->data, b2.data) && ! (*this == b2))
		return true;
	else if (this->sign == "positive" && b2.sign == "positive" && lessThan (this->data, b2.data))
		return true;
	else
		return false;
}

bool BigInt::operator <= (const BigInt& b2)
{
	return (*this < b2 || *this == b2) ? true : false;
}

bool BigInt::operator > (const BigInt& b2)
{
	return (*this < b2 || *this == b2) ? false : true;
}

bool BigInt::operator >= (const BigInt& b2)
{
	return (*this < b2) ? false : true;
}



//	BigInteger Mathematics Utility Mathematics
BigInt BigInt::BigAbs ()
{
	BigInt mod (*this);
	if (mod.sign != "zero")
		mod.sign = "positive";
	return mod;
}

BigInt BigInt::Factorial ()
{
	BigInt temp = *this;
	BigInt result ("1");
	if (temp.sign == "negative")
		return "0";					// We cannot find factorial of negative integers.
	if (temp.data == "0")
		return result;
	BigInt i ("1");
	for (; i != temp; i++)
		result *= i;
	return result * i;
}


// Insertion and Extraction Operator
istream& operator >> (istream& in, BigInt& bigNumber)	// Here we cannot use const because we want to modify its value.
{
	string str;
	in >> str;
	bigNumber = str;
	return in;
}

ostream& operator << (ostream& out, const BigInt& bigNumber)
{
	if (bigNumber.sign == "negative")
		out << "-";
	out << bigNumber.data;
	return out;
}












// Driver Code
int main()
{
	BigInt big1;

	big1 = 'A';
	big1 = 12232;
	big1 = 3435435342332;
	big1 = "45345453468070746468686783523258890807867";
	float b = 5454634637.4;
	long long int a = b;
	cout<<a<<endl;
	big1 = b;

	cout<<big1;






	return 0;
}

