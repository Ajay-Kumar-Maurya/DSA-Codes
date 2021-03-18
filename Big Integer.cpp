#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

vector<short> sum (vector<short> v1, vector<short> v2)
{
	vector<short> sum;

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

	reverse (sum.begin(), sum.end());

	return sum;
}


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




class Exception : public runtime_error
{
	public :
		Exception() : runtime_error ("Math error : Attempted to divide by zero...\n")
		{

		}
};




/*
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
		throw runtime_error ("Math error : Attempted to divide by zero...\n");
		//throw Exception();
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






int main()
{
	string big1, big2;
	cout << "Enter big integer 1  :  ";
	cin >> big1;
	cout << "Enter big integer 2  :  ";
	cin >> big2;

	//cout << multiply (big1, big2);
	//cout << division (big1, big2);
	try
	{
		string ds = division (big1, big2);
	}
	catch (runtime_error& e)
	{
		//cerr << "Runtime Exception Occurred : Division By Zero in operation ";
		//cerr << "\"" << *this << " / " << b2 << "\"" << endl;
		cout << "\nException Occured" << endl <<e.what();
		cout << "Any further advancement may produce erroneous result\n";
		cout << "\tDo you want to continue (y/n) :    ";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			cout<<"Great !!!";
		else
			exit (0);
	}


	return 0;
}


/*
	We use strings or arrays to store big integers.
	We store each digit of big integer as an element of array.
	We manually do the calulations.
*/
