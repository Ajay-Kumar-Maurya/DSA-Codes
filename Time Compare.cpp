
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

struct mytime
{
	string meridian;
	char colon;
	short hour;
	short minute;
};

string timecmp (mytime t1, mytime t2)
{
	if (t1.meridian == "AM" && t2.meridian == "PM")
		return "t1 < t2";
	else if (t1.meridian == "AM" && t2.meridian == "AM")
	{
		if (t1.hour == 12 && t2.hour != 12)
			return "t1 < t2";
		else if (t2.hour == 12 && t1.hour != 12)
			return "t1 > t2";
		else if (t1.hour == 12 && t2.hour == 12)
		{
			if (t1.minute > t2.minute)
				return "t1 > t2";
			else if (t1.minute == t2.minute)
				return "t1 == t2";
			else
				return "t1 < t2";
		}
		else
		{
			if (t1.hour > t2.hour)
				return "t1 > t2";
			else if (t1.hour == t2.hour)
			{
				if (t1.minute > t2.minute)
					return "t1 > t2";
				else if (t1.minute == t2.minute)
					return "t1 == t2";
				else
					return "t1 < t2";
			}
			else
				return "t1 < t2";
		}
	}
	else if (t1.meridian == "PM" && t2.meridian == "AM")
		return "t1 > t2";
	else
	{
		if (t1.hour == 12 && t2.hour != 12)
			return "t1 < t2";
		else if (t2.hour == 12 && t1.hour != 12)
			return "t1 > t2";
		else if (t1.hour == 12 && t2.hour == 12)
		{
			if (t1.minute > t2.minute)
				return "t1 > t2";
			else if (t1.minute == t2.minute)
				return "t1 == t2";
			else
				return "t1 < t2";
		}
		else
		{
			if (t1.hour > t2.hour)
				return "t1 > t2";
			else if (t1.hour == t2.hour)
			{
				if (t1.minute > t2.minute)
					return "t1 > t2";
				else if (t1.minute == t2.minute)
					return "t1 == t2";
				else
					return "t1 < t2";
			}
			else
				return "t1 < t2";
		}
	}
}
// This function string as output.
// Output Format :  t1  <operator>  t2

int main()
{

	cout<<"Enter time 1 :  ";

	string P;
	getline (cin, P);

	cout<<"Enter time 2 :  ";
	string L;
	getline (cin, L);

	mytime tP, tL;

	std::stringstream sso;

	sso << P;
	sso >> tP.hour >> tP.colon >> tP.minute >> tP.meridian;
	sso.str ("");
	sso.clear();

	sso << L;
	sso >> tL.hour >> tL.colon >> tL.minute >> tL.meridian;
	sso.str ("");
	sso.clear();


	cout << tP.hour << "     " << tP.minute << "     " << tP.meridian << endl;
	cout << tL.hour << "     " << tL.minute << "     " << tL.meridian << endl;

	cout<<"\nOutput is :  ";
	string val = timecmp (tP, tL);
	cout << val << endl;


	return 0;
}

