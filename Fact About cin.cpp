#include<iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;

	cin.ignore();

	string str;
	getline (cin, str);

	cout << "\n\n\nOutput ----\nx = " << x << "\nstr = " << str;

	return 0;
}


/*
cin does not shows unexpected behaviour like scanf() function.
If we use getline after cin, then we need to use cin.ignore() to ignore <Enter-Key>.
*/
