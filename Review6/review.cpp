#include "review.h"

#include <iostream>

using namespace std;

void LoopThrough(double * data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i]++;
    }
}