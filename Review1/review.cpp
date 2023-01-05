#include "review.h"

#include <iostream>

using namespace std;

void ReadStdIn()
{
	int userInt;
	double userDouble;
	string userString;

	cin >> userInt >> userDouble >> userString;

	cout << userInt << endl;
	cout << userDouble << endl;
	cout << userString << endl;
}