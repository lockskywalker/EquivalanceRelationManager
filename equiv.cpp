#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "equiv.h"

using namespace std;

string integerTostring(int n)
{
	string ans = "";
	while (n != 0)
	{
		int rem = n % 10;
		ans = (char)('0' + rem) + ans;
		n = n / 10;
	}
	return ans;
}

int * newER(int n)
{
	int * e = (int*)malloc((n + 1) * sizeof(int));
	for (int i = 1; i <= n; i++)
	{
		e[i] = i;
	}

	return e;
}

int leader(int * R, int x)
{
	if (R[x] != x)
		R[x] = leader(R, R[x]);

	return R[x];
}

bool equivalent(int * R, int x, int y)
{
	return leader(R, x) == leader(R, y);
}

void merge(int * R, int x, int y)
{
	int xl = leader(R, x);
	int yl = leader(R, y);

	if (xl != yl)
	{
		R[xl] = yl;
	}
}

void destroyER(int * R)
{
	free(R);
}

void showER(int * R, int n)
{
	int parent = 1;
	string output = "";

	while (parent <= n)
	{
		output = "";
		output = output + "{ ";
		int count = 0;

		for (int i = 1; i <= n; i++)
		{
			if (leader(R, i) == parent)
			{
				output = output + integerTostring(i) + ", ";
				count++;
			}
		}

		if (count == 0)
		{
			parent++;
			continue;
		}

		output = output.substr(0, output.size() - 2);

		output = output + " }";

		cout << output;

		parent++;
	}

	cout << endl;
}