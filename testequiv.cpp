// CSCI 2530
// Assignment: 3
// Author:     Nigel Smith
// File:       testequiv.cpp
// Tab stops:  4

// **Say what this program does here.  (replace this comment)**


#include <cstdio>
#include <iostream>
#include "equiv.h"
using namespace std;


int main(int argc, char** argv)
{
	int n = 7;
	int * R = newER(n);
	showER(R, n);
	///R = {1} {2} {3} {4} {5} {6} {7}


	merge(R, 1,5);
	showER(R, n);
	///R = {1, 5} {2} {3} {4} {6} {7}


	merge(R, 2, 7);
	showER(R, n);
	///R = {1, 5} {2, 7} {3} {4} {6}


	///equivalent(R, 1,5) yields true
	///equivalent(R, 1,7) yields false

	cout << "equivalent(R, 1,5) : " << equivalent(R, 1, 5) << endl;
	cout << "equivalent(R, 1,7) : " << equivalent(R, 1, 7) << endl;

	merge(R, 5, 7);
	showER(R, n);
	///R = {1, 2, 5, 7} {3} {4} {6}


	///equivalent(R, 2,5) yields true
	///equivalent(R, 2,3) yields false

	cout << "equivalent(R, 2,5) : " << equivalent(R, 2, 5) << endl;
	cout << "equivalent(R, 2,3) : " << equivalent(R, 2, 3) << endl;

	merge(R, 2, 3);
	showER(R, n);
	///R = {1, 2, 3, 5, 7} {4} {6}

	///equivalent(R, 3,7) yields true
	///equivalent(R, 4,7) yields false

	cout << "equivalent(R, 3,7) : " << equivalent(R, 3, 7) << endl;
	cout << "equivalent(R, 4,7) : " << equivalent(R, 4, 7) << endl;

	merge(R, 2, 3);
	showER(R, n);
	///R = {1, 2, 3, 5, 7} {4} {6}
	destroyER(R);
}
