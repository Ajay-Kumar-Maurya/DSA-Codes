#include <bits/stdc++.h>
using namespace std;

int count_hits (int Warr[], int Larr[], int size)		// a <= b <= c <= d
{
	int a, b, c, d;			// For value
	int ai, bi, ci, di;		// For index

	a = b = c = d = INT_MAX;
	ai = bi = ci = di = -1;

	// Finding Indices
	for (int i = 0; i < size; i++)
	{
		if (a > Warr[i])
		{
			d = c; c = b; b = a;
			di = ci; ci = bi; bi = ai;

			a = Warr[i];
			ai = i;
		}
		else if (b > Warr[i])
		{
			d = c; c = b;
			di = ci; ci = bi;

			b = Warr[i];
			bi = i;
		}
		else if (c > Warr[i])
		{
			d = c;
			di = ci;

			c = Warr[i];
			ci = i;
		}
		else
		{
			d = Warr[i];
			di = i;
		}
	}
	cout << endl << endl << "Values are : " << a << "  " << b << "  " << c << "  " << d;
	cout << endl << endl << "Indixes are : " << ai << "  " << bi << "  " << ci << "  " << di;

	int hits = 0;

	// Frog Sort and Counting hits
	if (ai >= bi)
	{
		//int req_hit = floor (((ai - bi) / Larr[bi]) + 1);
		int req_hit = ((ai - bi) / Larr[bi]) + 1;
		bi += req_hit * Larr[bi];
		hits += req_hit;
	}
	if (bi >= ci && ci != -1)
	{
		//int req_hit = floor (((bi - ci) / Larr[ci]) + 1);
		int req_hit = ((bi - ci) / Larr[ci]) + 1;
		ci += req_hit * Larr[ci];
		hits += req_hit;
	}
	if (ci >= di && di != -1)
	{
		//int req_hit = floor (((ci - di) / Larr[di]) + 1);
		int req_hit = ((ci - di) / Larr[di]) + 1;
		di += req_hit * Larr[di];
		hits += req_hit;
	}

	return hits;
}


int main()
{
	int N;
	cin >> N;

	int *Warr = new int[N];
	int *Larr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> Warr[i];

	for (int i = 0; i < N; i++)
		cin >> Larr[i];

	int hits = count_hits (Warr, Larr, N);
	cout << endl << endl << hits;

	delete[] Warr;
	delete[] Larr;

	return 0;
}
