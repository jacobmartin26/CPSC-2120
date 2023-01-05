/*
 * Name: Jacob Martin
 * Date Submitted: 2/25/2022
 * Lab Section: 005
 * Assignment Name: Lab 4 - Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
void mergeSortHelper1(std::vector<T>&, int, int);

template <class T>
void mergeSortHelper2(std::vector<T>&, int, int, int);

template <class T>
void elemSwap(T*, T*);

template <class T>
int split(std::vector<T>&, int, int);

template <class T>
void actualSort(std::vector<T>&, int, int);

template <class T>
std::vector<T> mergeSort(std::vector<T> lst)
{
    mergeSortHelper1(lst, 0, lst.size() - 1);
    
    return lst;
}

template <class T>
void mergeSortHelper1(std::vector<T> &lst, int const left, int const right)
{
        if(left >= right)
        {
            return;
        }

        int middle = left + (right - left) / 2;
        
        mergeSortHelper1(lst, left, middle);
        
        mergeSortHelper1(lst, middle + 1, right);
        
        mergeSortHelper2(lst, left, middle, right);
}

// Merges sub-vectors of lst
template <class T>
void mergeSortHelper2(std::vector<T> &lst, int const left, int const middle, int const right)
{
        std::vector<T> leftPart;
        std::vector<T> rightPart;
        
        int const temp1 = right - middle;
        int const temp2 = middle - left + 1;

        // create sub-vectors for left and right side
        for (int i = 0; i < temp2; i++)
        {
            leftPart.push_back(lst[left + i]);
        }
        
        for (int j = 0; j < temp1; j++)
        {
            rightPart.push_back(lst[middle + 1 + j]); 
        }

        int sub1 = 0;    // sub-vector 1 index
        int sub2 = 0;    // sub-vector 2 index
        int sub3 = left; // combined sub-vector index

        while (sub1 < temp2 && sub2 < temp1) // combine sub-vectors
        {
                if (leftPart[sub1] <= rightPart[sub2])
                {
                    lst[sub3] = leftPart[sub1];
                    sub1++;
                }
                else
                {
                    lst[sub3] = rightPart[sub2];
                    sub2++;
                }
                sub3++;
        }

        // Copy remaining elements of left sub-vector
        while (sub1 < temp2)
        {
            lst[sub3] = leftPart[sub1];
            sub1++;
            sub3++;
        }

        // Copy remaining elements of right sub-vector
        while (sub2 < temp1)
        {
            lst[sub3] = rightPart[sub2];
            sub2++;
            sub3++;
        }
        
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst)
{
    actualSort(lst, 0, lst.size() - 1);
    return lst;
}

//function to swap two elements by value
template <class T>
void elemSwap(T* a, T* b) 
{ 
        T t = *a; 
        *a = *b; 
        *b = t; 
}

/*
    This function takes a pivot and places values lower
    than it to the left and values higher than it to the
    right.
*/
template <class T>
int split (std::vector<T> &lst, int minVal, int maxVal) 
{ 
        auto pivot = lst[maxVal]; // pivot element 
        int index = (minVal - 1); // minVal index 

        for (int j = minVal; j <= maxVal - 1; j++) 
        { 
                if (lst[j] < pivot) // If current element is smaller than the pivot 
                { 
                        index++; // increment index of smaller element 
                        elemSwap(&lst[index], &lst[j]); // swaps values
                } 
        } 
        elemSwap(&lst[index + 1], &lst[maxVal]);

        return index + 1; 
}

/*
    This function is responsible for the actual
    sorting of the data. Starts at minVal and
    ends at maxVal.
*/
template <class T>
void actualSort(std::vector<T> &lst, int minVal, int maxVal) 
{ 
        if (minVal < maxVal)
        { 
                int splitVal = split(lst, minVal, maxVal); // partition index

                // sorts elements before and after split
                actualSort(lst, minVal, splitVal - 1); 
                actualSort(lst, splitVal + 1, maxVal); 
        } 
} 