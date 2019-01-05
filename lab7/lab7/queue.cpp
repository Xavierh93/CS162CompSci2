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
}

//  Deconstructor
Queue::~Queue()
{
    QueueNode *garbage = head;
    
    while (garbage != nullptr)
    {
        head = head -> next;
        garbage -> next = nullptr;
        delete garbage;
        garbage = head;
    }
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
void Queue::addBack(int value)
{
    QueueNode *temp;
    temp = new QueueNode(value);
    if (isEmpty())
    {
        tail = head = temp;
        head -> next = tail -> next = nullptr;
        head -> prev = tail -> prev = nullptr;
    }
    //  Adjusts all pointers in the queue if there is more than one value in the queue
    else
    {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
        head -> prev = tail;
        tail -> next = head;
        
    }
}


//  Displays the front value of the queue
int Queue::getFront()
{
    if (isEmpty())
    {
        cout << endl << "The queue is currently empty." << endl;
        return 0;
    }
    else
    {
        return head -> val;
    }
}


//  Removes the front value of the queue
void Queue::removeFront()
{
    QueueNode *temp = head;
    
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
        head -> prev = temp -> prev;
        head -> prev -> next = head;
        delete temp;
    }
}

//  Prints the entire queue to the screen.
void Queue::printQueue()
{
    if (isEmpty())
    {
        cout << endl << "The queue is currently empty." << endl;
    }
    //  If there is more than one value in the queue
    else if (head != tail)
    {
        QueueNode *temp = head;
        while (temp -> next != head)
        {
            cout << temp -> val << " ";
            temp = temp -> next;
        }
        cout << temp -> val << endl;
    }
    //  If there is only one value in the queue
    else
    {
        cout << head -> val << endl;
    }
    cout << endl;
}

void Queue::moveToLastNode()
{
    if (head == tail)
    {
        return;
    }
    QueueNode *ptr = head;
    head = ptr -> next;
    ptr -> next = nullptr;
    
    tail -> next = ptr;
    tail = ptr;
    
}
