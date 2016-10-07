// CSCI 2530
// Assignment: 3
// Author:     Nigel Smith
// File:       equiv.cpp
// Tab stops:  4
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "equiv.h"

using namespace std;

//converts int to strings for printing
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

/****************************************************
*                      newER                       *
****************************************************
* Initialzes the the array of Ints ER that will be *
* used in the rest of the program and returns e.   *
****************************************************/
int * newER(int n)
{
	int * e = (int*)malloc((n + 1) * sizeof(int));
	for (int i = 1; i <= n; i++)
	{
		e[i] = i;
	}

	return e;
}

/****************************************************
*                      leader                      *
****************************************************
* Identifies the Leader of x in R                  *
* returns the x index of R                         *
****************************************************/
int leader(int * R, int x)
{
	if (R[x] != x)
		R[x] = leader(R, R[x]);

	return R[x];
}

/****************************************************
*                    equivalent                    *
****************************************************
* Returns true or false in relation to if x and y  *
* are equivalent.                                  *
****************************************************/
bool equivalent(int * R, int x, int y)
{
	if (leader(R, x) == leader(R, y)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

/****************************************************
*                      merge                       *
****************************************************
* returns the combination of x and y               *
****************************************************/
void merge(int * R, int x, int y)
{
	int xl = leader(R, x);
	int yl = leader(R, y);

	if (xl != yl)
	{
		R[xl] = yl;
	}
}

/****************************************************
*                  destroyER                       *
****************************************************
* destroys ER from memory                          *
****************************************************/
void destroyER(int * R)
{
	free(R);
}

/****************************************************
*                      showER                      *
****************************************************
* prints R                                         *
****************************************************/
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
