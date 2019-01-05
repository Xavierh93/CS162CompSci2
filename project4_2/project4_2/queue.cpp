//  This is the file for the queue class.
//  Created by Xavier on 2/21/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "queue.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;



//  Constructor
Queue::Queue()
{
    head = nullptr;
    tail = nullptr;
    points = 0;
}

//  Deconstructor
Queue::~Queue()
{
    Node *ptr = head;
    while (ptr != 0)
    {
        Node *next = ptr -> next;
        delete ptr;
        ptr = next;
    }
}

//  Sets points for team
void Queue::setPoints(int points)
{
    this -> points = points;
}


//  Returns points for team
int Queue::getPoints()
{
    return points;
}


//  Checks if the queue is empty
bool Queue::isEmpty() const
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//  Adds a user entered value to the tail of the queue
void Queue::addHeadNode(Character *fighter)
{
    
    Node *ptr = new Node();
    
    ptr -> opponent = fighter;
    if (isEmpty())
    {
        tail = head = ptr;
    }
    //  Adjusts all pointers in the queue if there is more than one value in the queue
    else
    {
        ptr -> prev = tail;
        tail -> next = ptr;
        tail = ptr;
    }
}


//  Adds node to the back of the list
void Queue::addTailNode(Character *fighter)
{
    Node *temp = new Node();
    
    temp -> opponent = fighter;
    if(tail == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

//  Displays the front value of the queue
Character* Queue::getFront()
{
    Node *ptr = head;
    if (isEmpty())
    {
        return nullptr;
    }
    else
    {
        return ptr -> opponent;
    }
}


//  Removes the front value of the queue
void Queue::removeFront()
{
    Node *ptr = head;
    
    if (isEmpty())
    {
        cout << endl << "The queue is currently empty." << endl;
    }
    
    //  If there is only one value in the queue
    else if (head -> next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    
    //  If there is more than one value in the queue
    else
    {
        head = head -> next;
        head -> prev = ptr -> prev;
        delete ptr;
    }
}

 
//  Moves the node at the front of the list to the back of the list
void Queue::moveToLastNode()
{
    if (head == tail)
    {
        return;
    }
    else
    {
        Node *ptr = head;
        head = ptr -> next;
        ptr -> next = nullptr;
        tail -> next = ptr;
        tail = ptr;
    }
}




