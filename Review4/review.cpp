#include "review.h"

#include <iostream>

using namespace std;

void ReadWrite()
{
    string userVar;
    string allEntries;
    
    while (userVar != "q")
    {
        cin >> userVar;
        
        allEntries = allEntries + userVar + " ";
        
        if (userVar == "q")
        {
           allEntries.pop_back();
           allEntries.pop_back();
        }
    }
    
    cout << allEntries << endl;
    
    return;
}