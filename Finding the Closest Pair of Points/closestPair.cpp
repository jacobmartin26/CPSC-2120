/*
 * Name: Jacob Martin
 * Date Submitted: 3/16/2022
 * Lab Section: 005
 * Assignment Name: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

double closestPair(string filename);

double checkGroups(point, vector<point>&, set<vector<point>>);

bool   checkDist(point, point, set<vector<point>>);

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename)
{
    ifstream input (filename); // open file

    int numPoints = 0; // points inputted and compared
    input >> numPoints;
        
    int b = sqrt(numPoints); // b x b and sqrt of numPoints should allow enough room for all poiints

    vector<vector<vector<point>>> grid(b, vector<vector<point>>(b)); // 2D vector for plane of all points
        
    for(int i = 0; i < numPoints; i++) // put all points in plane
    {
        point currVal;
                
        currVal.x = 0; // set to 0
        currVal.y = 0;
                
        input >> currVal.x;
        input >> currVal.y;

        int mapX;
        mapX = (int)(b * currVal.x);
                
        int mapY;
        mapY = (int)(b * currVal.y);

        grid[mapX][mapY].push_back(currVal);
    }

                
    double minVal = 1;
        
    set<vector<point>> pointChecked;

    for(int i = 0; i < b; i++)
    {
        for(int j = 0; j < b; j++)
        {
            for(auto currPoint : grid[i][j])
            {
                double temp = checkGroups(currPoint, grid[i][j], pointChecked);
                double comp = 2;
                                
                if(j != 0) // length from point to left bucket
                {
                    comp = checkGroups(currPoint, grid[i][j - 1], pointChecked);
                    temp = (comp < temp) ? comp:temp;
                                        
                    if(i != (b - 1)) // length from point to top left bucket
                    {
                        comp = checkGroups(currPoint, grid[i + 1][j - 1], pointChecked);
                        temp = (comp < temp) ? comp:temp;
                    }
                }
                                
                if(j != (b - 1)) // length from point to right bucket
                {
                    comp = checkGroups(currPoint, grid[i][j + 1], pointChecked);
                    temp = (comp < temp) ? comp:temp;
                                        
                    if(i != (b - 1)) // length from point to top right bucket
                    {
                        comp = checkGroups(currPoint, grid[i + 1][j + 1], pointChecked);
                        temp = (comp < temp) ? comp:temp;
                    }
                }
                                
                if(i != 0) // length from point to bottom bucket
                {
                    comp = checkGroups(currPoint, grid[i - 1][j], pointChecked);
                    temp = (comp < temp) ? comp:temp;
                                        
                    if(j != 0) // length from point to bottom left bucket
                    {
                        comp = checkGroups(currPoint, grid[i - 1][j - 1], pointChecked);
                        temp = (comp < temp) ? comp:temp;
                    }
                                        
                    if(j != (b - 1)) // length from point to bottom right bucket
                    {
                        comp = checkGroups(currPoint, grid[i - 1][j + 1], pointChecked);
                        temp = (comp < temp) ? comp:temp;
                    }
                }       
                                
                if(i != (b - 1)) // length from point to top bucket
                {
                    comp = checkGroups(currPoint, grid[i + 1][j], pointChecked);
                    temp = (comp < temp) ? comp:temp;

                }
                                
                if(temp < minVal) // initial temp should always be smaller than initial minimum value
                {
                   minVal = temp; 
                }
            }
        }
    }
    
    return minVal;
}

// Operator override used for checkDist to let the find method use the point struct
inline bool operator<(const point& left, const point& right)
{
    if(left.x < right.x)
    {
        if(left.y < right.y)
        {
            return true;
        }
    }
    return false;
}

// This helper function checks if two points have already been compared
bool checkDist(point left, point right, set<vector<point>> pair)
{
        
    // Possible combinations of points in vector
    vector<point> combo1 = {left,right}; // combination 1
    vector<point> combo2 = {right,left}; // combination 2
        
    auto findOne = pair.find(combo1);
    auto findTwo = pair.find(combo2);

    if(findOne != pair.end() || findTwo != pair.end()) // compared or not
    {
        return true;
    }
    else
    {
        return false;
    }
}

// This helper function checks input group of points against 1st parameter
double checkGroups(point curr, vector<point> &group, set<vector<point>> compared)
{
    double minVal = 2; // Set minimum higher than values can be

    for(auto points : group) // Loop through all points
    {
                
        if(points.x == curr.x and points.y == curr.y) // point validation / compare to self
        {
            continue;
        }
                
        if(!checkDist(curr, points, compared)) // call function to get what hasn't been checked
        {

            vector<point> temp(2, curr); // Distance vector of the two points being compared
                        
            temp[1] = points;
            compared.insert(temp);
                        
            double xCalc = curr.x - points.x;
            double yCalc = curr.y - points.y;
                        
            double pairDist = sqrt(pow(xCalc, 2) + pow(yCalc, 2));
                        
            if(pairDist < minVal) // Check new distance less than old min
            {
                minVal = pairDist; 
            }
        }
    }
    
    return minVal; // Returns minimum value
}

int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}