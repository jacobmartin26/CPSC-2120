#include "IntegerArrayQueue.h"
#include <iostream>

using namespace std;

static int check;

bool IntegerArrayQueue::enqueue(int value)
{
    if ((front == 0 && array[front] != 0 && back == size - 1) 
         || (back == (front - 1) % size))
    {
        return false;
    }
    else
    {
        check++;
        
        cout << check;
        
        if (check > size - 1)
        {
            return false;
        }
        
        back++;
        
        if (back == size - 1 && front == 0)
        {
            return false;
        }
        
        if (size - 1 < back)
        {
            back = 0;
        }
        
        array[back] = value;
        
        return true;
    }
}

int IntegerArrayQueue::dequeue()
{
    if ((back != size - 1 && front != 0) && (back + 1) % size == front)
    {
        return 0;
    }
    
    else
    {
        check--;
        
        int temp; 
        
        temp = array[front];
        array[front] = 0;
        
        front++;
        
        if (size < front)
        {
            front = 0;
        }
        return temp;
    }
}