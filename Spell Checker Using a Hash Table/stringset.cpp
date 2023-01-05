/*
 * Name: Jacob Martin
 * Date Submitted: 3/9/2022
 * Lab Section: Section 5
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    if (!find(word)) // if word is in string set or not
    {
        hash<string> hashString;
        
        string myWord;
        int point;
        
        if (num_elems >= size) // if size needs to be expanded or not
        {
            size = size * 2;
            
            vector<list<string>> tempTab(size); // temporary table
            
            for (int i = 0; i < size / 2; i++) // loops through table/lists and re-hash in temp table
            {
                for (list<string>::const_iterator iter = table[i].begin(); iter != table[i].end(); iter++)
                {
                    myWord = *iter;
                    point = hashString(myWord) % size;
                    
                    tempTab[point].push_back(myWord);
                    table[i].remove(word);
                }
            }
            table = tempTab; // old table is now the temp table
        }
        point = hashString(word) % size;
        table[point].push_back(word);
        
        num_elems++;
    }
}

bool Stringset::find(string word) const
{
    hash<string> hashString;
    int location;
    
    location = hashString(word) % size;
    
    for (list<string>::const_iterator iter = table[location].begin(); 
         iter != table[location].end(); iter++) // loop through all list values
    {
        if (*iter == word) // true if the word is present
        {
            return true;
        }
    }
    return false;
}

void Stringset::remove(string word)
{
    if (find(word)) // if word in list remove it from location
    {
        hash<string> hashString;
        int location;
        
        location = hashString(word) % size;
        
        table[location].remove(word);
        
        num_elems--;
    }
}