#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type
unordered_map<string, bool> visited;
unordered_map<string, string> pred;
unordered_map<string, int> dist;
unordered_map<string, vector < string>> nbrs;

int find(string, string, vector<string>&);
void build();

//Implement breadth-first search, refer to Lab 10

void wordLadder(string s, string t, int& steps, vector<string>& p)
{
    build();
 
    queue<string> check;

    check.push(s);

    visited[s] = true;
    dist[s] = 0;

    while (!check.empty())
    {
        string curr = check.front();

        check.pop();

        for (string x : nbrs[curr])
            if (!visited[x])
            {
                pred[x] = curr;
                dist[x] = 1 + dist[curr];
                visited[x] = true;

                check.push(x);
            }
    }

    steps = find(s, t, p);
}

int find(string start, string end, vector<string>& path)
{
    if (pred.find(end) == pred.end()) // end has pred
    {
        return 0;
    }

    if (start.compare(end) != 0)
    {
        int part = 1 + find(start, pred[end], path);

        path.push_back(end);

        return part;
    }
    else
    {
        path.push_back(end);

        return 0;
    }
}

void build(void)
{
    ifstream word_file("wordlist05.txt");
    string curr;

    while (word_file >> curr)
    {
        V.push_back(curr);
    }

    for (auto word : V)
    {
        for (int i = 0; i < word.length(); i++)
        {
            for (char letter = 'a'; letter <= 'z'; letter++)
            {
                if (letter == word.at(i))
                {
                    continue;
                }

                string current = word;

                current.at(i) = letter;
                nbrs[word].push_back(current);
            }
        }
    }
}

int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}
