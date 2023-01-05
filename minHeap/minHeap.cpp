#include <iostream>
#include "minHeap.h"

using namespace std;

void minHeap::siftUp(int spot) // moves the element upwards
{
    int child = spot;
    int parent = (spot - 1) / 2;

    while (child != 0 && heap[parent] > heap[child]) // compare with parents

    {
        int temp = heap[parent]; //swap child and parent

        heap[parent] = heap[child];

        heap[child] = temp;

        child = parent;  // current parent is child

        parent = (parent - 1) / 2;  // new parent
    }
}

void minHeap::siftDown(int pos) // move element down

{

    int parent = pos;
    int left = 2 * parent + 1; //left child
    int right = 2 * parent + 2; //right child
    int swap = -1;

    if (left < (int)heap.size() && heap[left] < heap[parent])  //checking left
    {

        swap = left;

    }

    if (right < (int)heap.size() && heap[right] < heap[parent]) //checking right
    {
        if (swap == -1)
        {
            swap = right;
        }
        else
        {
            if (heap[right] < heap[left])
            {
                swap = right; // min
            }
        }
    }

    if (swap == -1)
    {
        return; // no swap
    }

    int temp = heap[parent]; // swap parent
    heap[parent] = heap[swap];
    heap[swap] = temp;

    siftDown(swap); // recursive call

}

minHeap::minHeap(vector<int> data)
{
    heap.resize(0); // reset heap

    for (int i = 0; i < (int)data.size(); i++)
    {
        heap.push_back(data[i]); // populate vector
    }

    for (int i = heap.size() - 1; i >= 0; i--)
    {
        siftDown(i); // bottom up insertion
    }
}

void minHeap::insert(int value)
{
    heap.push_back(value); //insertion

    int spot = heap.size() - 1;

    siftUp(spot); //move element up
}

int minHeap::removeMin()
{
    if (heap.size() == 0)
    {
        return -1; // empty heap
    }

    int temp = heap[0]; // swap heap[0]

    heap[0] = heap[heap.size() - 1];

    heap[heap.size() - 1] = temp;

    heap.pop_back(); // remove element

    siftDown(0);  // move heap[0] down to maintain minHeap

    return temp;
}