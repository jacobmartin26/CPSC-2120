/*
 * Name: Jacob Martin
 * Date Submitted: 3 / 17 / 2022
 * Assignment Name: Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    string myWord; // holds a word from list
    
    vector<string> anaVec;
    
    for(int i = 0; i < wordlist.size(); i++) // loop through list
    {
        myWord = wordlist[i]; // gets a word from list
        
        unordered_map<char, int> myMap; // create map
        
        int otherLen = myWord.length();
        int myLen = word.length();
        
        if(myLen != otherLen) // could not be an anagram if lengths do not match
        {
            continue;
        }
        
        for(int j = 0; j < myLen; j++)
        {
            myMap[word[j]]++; // increment keys
        }
        
        for(int z = 0; z < otherLen; z++)
        {
            if(myMap.find(myWord[z]) == myMap.end()) // not an anagram if a character is missing
            {
                break;
            }
            else
            {
                myMap[myWord[z]]--; // decrement value for amount of chars
                
                if(myMap[myWord[z]] == 0)
                {
                    myMap.erase(myWord[z]); // map empty if chars == 0
                }
            }
        }
        
        if(myMap.size() == 0) // anagram found
        {
            anaVec.push_back(myWord);
        }
    }
    return anaVec; // return the anagram vector
}