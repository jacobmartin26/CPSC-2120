/*
 * Name: Jacob Martin
 * Date Submitted: 3/9/2022
 * Lab Section: Section 5
 * Assignment Name: Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename)
 {
     string wordCurr;
     ifstream infile(filename);
     
     while(getline(infile, wordCurr))
     {
         words.insert(wordCurr);
     }
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
     string wordAlt; // alternate word/chars
     wordAlt = word;
     
     vector<string> listAlts; // vector of alternatives
     
     for (int i = 0; i < word.length(); i++) // loops through characters
     {
         for (char j = 'a'; j < 'z' + 1; j++) // loops through alphabet
         {
             wordAlt.replace(i, 1, 1, j); // replaces char at i
             
             if (wordAlt != word && words.find(wordAlt)) // if new word isnt the original & in string set
             {
                 listAlts.push_back(wordAlt);
             }
             wordAlt = word;
         }
     }
     return listAlts; // returns vector alternatives
 }