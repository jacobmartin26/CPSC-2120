/*
 * Name: Jacob Martin
 * Date Submitted: 4 / 18 / 2022
 * Lab Section: 005
 * Assignment Name: Lab 9: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

bool valid(int**, int, int, int);

int findsolution(int** queenarray, int n, int col)
{
    int total = 0;

    int row;

    if (col == n)
    {

        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        row = i;

        if (valid(queenarray, n, col, row) == true)
        {
            queenarray[row][col] = 1; // place

            total = total + findsolution(queenarray, n, col + 1); // recursive call

            queenarray[row][col] = 0; // reset
        }
    }

    return total;
}

bool valid(int** queen, int n, int col, int row) // helper to see if queen can be placed
{
    for (int i = 0; i < n; i++) // row
    {
        if (queen[row][i] == 1)
        {
            return false;
        }
    }
    
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--) // north west spot
    {
        if (queen[x][y] == 1)
        {
            return false;
        }
    }
   
    for (int x = row, y = col; x < n && y >= 0; x++, y--) // south west spot
    {
        if (queen[x][y] == 1)
        {
            return false;
        }
    }

    return true;
}

int nQueens(int n) 
{
    int** queen = new int* [n];

    for (int i = 0; i < n; i++)
    {
        queen[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            queen[i][j] = 0;
        }
    }
   
    return findsolution(queen, n, 0); // return number of solutions
}

int main()
{
    cout << "1: "  << nQueens(1)  << endl;
    cout << "2: "  << nQueens(2)  << endl;
    cout << "3: "  << nQueens(3)  << endl;
    cout << "4: "  << nQueens(4)  << endl;
    cout << "5: "  << nQueens(5)  << endl;
    cout << "6: "  << nQueens(6)  << endl;
    cout << "7: "  << nQueens(7)  << endl;
    cout << "8: "  << nQueens(8)  << endl;
    cout << "9: "  << nQueens(9)  << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}