#include "review.h"

#include <iostream>

using namespace std;

int Fibonacci(int a)
{
	if (a <= 1)
	{
		return 1;
	}
	else
	{
		return Fibonacci(a - 1) + Fibonacci(a - 2);
	}
}
