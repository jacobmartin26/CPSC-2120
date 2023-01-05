#include "doublyLinkedSwap.h"
#include <iostream>

using namespace std;

void swapWithNext(Node * p)
{
    Node * temp1; //= new Node(); // responsible for next values
    Node * temp2; //= new Node(); // responsible for prev values
    
    if (p->prev != nullptr && p->prev->prev != nullptr 
     && p->next != nullptr && p->next->next != nullptr)
    {
        temp2 = p->prev;
        temp1 = p->next;
        p->next = p->next->next;
        p->next->prev = p;
        temp1->next = p;
        p->prev = temp1;
        temp1->prev = temp2;
        temp2->next = temp1;
    }
}