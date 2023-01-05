#include "review.h"

#include <iostream>

using namespace std;

void ReadStdIn2()
{
    string userVar;
    int accum = 0;
    
    while (userVar != "q")
    {
        cin >> userVar;
        accum = accum + 1;
    }
    accum = accum - 1;
    cout << accum;
    
    return;
}