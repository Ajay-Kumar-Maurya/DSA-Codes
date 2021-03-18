#include<iostream>
using namespace std;

void bubblesort (string& s, int len)
{
	bool flag = 0;
	for (int i = 1; i <= len - 1; i++)
	{
		for (int j = 0; j <= len - 1 - i; j++)
		{
			if (s[j] > s[j + 1])
			{
				char temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
				flag = 1;
			}
		}
		if (!flag) break;
		flag = 0;
	}

}

int main()
{
	cout<<"Enter a string : ";
	string str;
	cin >> str;
	cout<<"Sorted string is : ";
	bubblesort (str, str.length());
	cout << str << endl;
	return 0;
}
