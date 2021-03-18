#include <bits/stdc++.h>
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
			return "t2 < t1";
		else if (t1.hour == 12 && t2.hour == 12)
		{
			if (t1.minute > t2.minute)
				return "t2 < t1";
			else if (t1.minute == t2.minute)
				return "t2 == t1";
			else
				return "t1 < t2";
		}
		else
		{
			if (t1.hour > t2.hour)
				return "t2 < t1";
			else if (t1.hour == t2.hour)
			{
				if (t1.minute > t2.minute)
					return "t2 < t1";
				else if (t1.minute == t2.minute)
					return "t2 == t1";
				else
					return "t1 < t2";
			}
			else
				return "t1 < t2";
		}
	}
	else if (t1.meridian == "PM" && t2.meridian == "AM")
		return "t2 < t1";
	else
	{
		if (t1.hour == 12 && t2.hour != 12)
			return "t1 < t2";
		else if (t2.hour == 12 && t1.hour != 12)
			return "t2 < t1";
		else if (t1.hour == 12 && t2.hour == 12)
		{
			if (t1.minute > t2.minute)
				return "t2 < t1";
			else if (t1.minute == t2.minute)
				return "t2 == t1";
			else
				return "t1 < t2";
		}
		else
		{
			if (t1.hour > t2.hour)
				return "t2 < t1";
			else if (t1.hour == t2.hour)
			{
				if (t1.minute > t2.minute)
					return "t2 < t1";
				else if (t1.minute == t2.minute)
					return "t2 == t1";
				else
					return "t1 < t2";
			}
			else
				return "t1 < t2";
		}
	}
}

int main()
{
	string P;
	getline (cin, P);

	string L;
	getline (cin, L);

	string R;
	getline (cin, R);

	mytime tP, tL, tR;

	stringstream sso;

	sso << P;
	sso >> tP.hour >> tP.colon >> tP.minute >> tP.meridian;
	sso.str ("");
	sso.clear();

	sso << L;
	sso >> tL.hour >> tL.colon >> tL.minute >> tL.meridian;
	sso.str ("");
	sso.clear();

	sso << R;
	sso >> tR.hour >> tR.colon >> tR.minute >> tR.meridian;
	sso.str ("");
	sso.clear();

	cout << tP.hour << "     " << tP.minute << "     " << tP.meridian << endl;
	cout << tL.hour << "     " << tL.minute << "     " << tL.meridian << endl;
	cout << tR.hour << "     " << tR.minute << "     " << tR.meridian << endl;

	string val1 = timecmp (tP, tL);
	cout << val1<<endl;

	string val2 = timecmp(tP, tL);
	cout<<val2;

	return 0;
}
