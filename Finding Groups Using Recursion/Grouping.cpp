/*
 * Name: Jacob Martin
 * Date Submitted: 2/17/2022
 * Lab Section: Section 5
 * Assignment Name: Finding Groups Using Recursion
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() { return row; } //return row value
        int getCol() { return col; } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int position; //integer to hold current position when traversing grid
        int grid[10][10];
        vector<vector<GridSquare>> groups;
        vector<GridSquare> filled; //additional vector to hold filled positions of grid
    public:
        Grouping() : grid{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
};

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping (string fileName) //parameterized constructor
{
    filled.clear(); //empties the vector
    
    position = 0; //start in correct position
    
    ifstream MyFile(fileName); //read from file
    
    int tempVal;
    tempVal = 0;
    
    string fileTxt;
    
    while (getline(MyFile, fileTxt))
    {
        for (int iter = 0; iter < fileTxt.size(); iter++)
        {
            if (fileTxt[iter] != '.') //if no '.' then there must be an x
            {
                GridSquare mySquare(tempVal, iter);
                filled.push_back(mySquare); //fills the vector
            }
        }
        tempVal++;
    }
    MyFile.close(); //close file
    
    while (filled.size() > 0)
    {
        vector<GridSquare> temp;
        
        groups.push_back(temp);
        
        auto initial = filled[0];
        //initial = filled[0];
        
        findGroup(initial.getRow(), initial.getCol());
        
        position++;
    }
}

/* recursive function that takes a row and column value. Returns if the dimensions are
   bad, otherwise it will continue. Loops through and fills a vector using recursion 
   to find the needed row and column values/positions. Does not return anything.
*/
void Grouping::findGroup (int row, int col)
{
    if (col < 0 || col > 10 || row < 0 || row > 10) //returns if any dimensions are unsuitable
    {
        return;
    }
    GridSquare mySquare(row, col);
    
    for (auto initial = filled.begin() /* start at beginning */; 
         initial != filled.end() /* goes until reaching end */;
         initial++)
    {
        if ((*initial) == mySquare) //recursion begins if condition met
        {
            groups[position].push_back(mySquare); //fills vector
            filled.erase(initial); //removes initial value
            findGroup(row - 1, col);
            findGroup(row, col - 1);
            findGroup(row, col + 1);
            findGroup(row + 1, col); //recursion checks nearby positions
            
            return;
        }
    }
    return;
}



//Simple main function to test Grouping
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}