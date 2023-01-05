/*
 * Name: Jacob Martin (jmart52)
 * Date Submitted: 2/2/2022
 * Lab Section: CPSC 2121-001
 * Assignment Name: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
    start = nullptr;
    mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    Node<T> *curr = start;
    Node<T> *temp = nullptr;
    
    while (curr != nullptr)
    {
        temp = curr->next;
        
        delete curr;
        
        curr = temp;
    }
    start = nullptr;
}

//Return the size of this list
template <class T>
int List<T>::size(){
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if(start == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
    Node<T> *insertFirstNode = new Node<T>(value);
    
    if (mySize == 0)
    {
        start = new Node<T>(value);
        
        mySize = mySize + 1;
    }
    
    else
    {
        insertFirstNode->next = start;
        start = insertFirstNode;
    }
    mySize = mySize + 1;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
    Node<T> *insertLastNode = new Node<T>(value);
    Node<T> *temp = nullptr;
    Node<T> *count = start;
    
    if (mySize == 0)
    {
        start = new Node<T>(value);
        
        mySize = mySize + 1;
    }
    
    else
    {
        while (count != nullptr)
        {
            temp = count;
            count = count->next;
        }
        temp->next = insertLastNode;
        
        mySize = mySize + 1;
        
        return;
    }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
    Node<T> *insertAtValNode = new Node<T>(value);
    Node<T> *temp = start;
    
    if (mySize == 0)
    {
        return;
    }
    
    else if (j == 0)
    {
        insertAtValNode->next = start;
        start = insertAtValNode;
    }
    
    else
    {
        for (int i = 0; i < j-1; i++)
        {
            if (temp != nullptr)
            {
                temp = temp->next;
            }
        }
        if (temp != nullptr)
        {
            insertAtValNode->next = temp->next;
            temp->next = insertAtValNode;
        }
        
        mySize = mySize + 1;
        
        return;
    }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
    start = start->next;
    
    mySize = mySize - 1;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
    Node<T> *removeLastNode = start;
    Node<T> *temp = nullptr;
    
    if (start == nullptr)
    {
        return;
    }
    
    while(removeLastNode->next != nullptr)
    {
        temp = removeLastNode;
        removeLastNode = removeLastNode->next;
    }
    
    if (temp == nullptr)
    {
        delete start;
        
        start = nullptr;
    }
    else
    {
        delete removeLastNode;
        
        temp->next = nullptr;
    }
    
    mySize = mySize - 1;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
    Node<T> *removeAtNode = start;
    Node<T> *temp = start;
    
    if (start == nullptr)
    {
        return;
    }
    
    if (j == 0)
    {
        start = removeAtNode->next;
        delete removeAtNode;
        
        return;
    }
    
    for (int i = 0; i < j-2; i++)
    {
        removeAtNode = removeAtNode->next;
    }
    temp = removeAtNode->next;
    removeAtNode->next = temp->next;
    delete temp;
   
    mySize = mySize - 1;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
    Node<T> *firstVal;
    firstVal = start;
    
    if (start == nullptr)
    {
        return T();
    }
    
    return firstVal->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
    Node<T> *lastVal = start;
    
    int iter = 0;
    
    if (start == nullptr)
    {
        return T();
    }
    else
    {
        while (lastVal->next != nullptr)
        {
            lastVal = lastVal->next;
        }
        
        return lastVal->value;
    }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
    Node<T> *atVal = start;
    
    int iter = 0;
    
    if (start == nullptr)
    {
        return T();
    }
    
    while (atVal != nullptr)
    {
        if (iter == j)
        {
            return (atVal->value);
        }
        iter++;
        atVal = atVal->next;
    }
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
    Node<T> *temp = start;
    
    int iter = 0;
    
    if (start == nullptr)
    {
        return -1;
    }
    
    while (temp != nullptr)
    {
        if (temp->value == key)
        {
            return iter;
        }
        iter++;
        temp = temp->next;
    }
    return -1;
}
