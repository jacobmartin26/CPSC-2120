/*
 * Name: Jacob Martin
 * Date Submitted: 2/25/2022
 * Lab Section: 005
 * Assignment Name: Lab 4 - Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target)
{
        int pos = -1; //temp holds target position

        int mySize = data.size();

        for (int i = 0; i < mySize; i++)
        {
                if (data[i] == target)
                {
                        pos = i;
                        break;
                }
        }

        return pos;
}

/* 
    This function is called by the binarySearch function which passes 
    the needed arguments to this function. The function handles the 
    entire binary search process.
*/
template <class T>
int binarySearchHelper(std::vector<T> data, T target, int left, int right)
{
    if (left <= right)
    { 
        int middle = left + (right - left) / 2; // sets middle point of the vector

        if (data[middle] > target) // must be in left sub-vector
        {
            return binarySearchHelper(data, target, left, middle - 1); // searches left side recursively
        }
        
        if (data[middle] == target) // element is at the middle
        {
            return middle;
        }
        
        else // must be in right sub-vector
        {
            return binarySearchHelper(data, target, middle + 1, right); // searches right side
        }
    } 

    return -1; // target not in data
}

/*
    This function is called by main and is used
    only to pass necessary arguments to its helper
*/
template <class T>
int binarySearch(std::vector<T> data, T target)
{
    return binarySearchHelper(data, target, 0, data.size() - 1);
}