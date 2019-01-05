//  This is the header file for the queue class.
//  Created by Xavier on 2/21/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>

class Queue
{
    struct QueueNode
    {
        QueueNode *next;
        QueueNode *prev;
        int val;
        QueueNode(int value, QueueNode *next1 = nullptr)
        {
            val = value;
            next = next1;
        }
    };
    
    // These track the head and tail of the queue
    QueueNode *head;
    QueueNode *tail;
    
public:
    //  Constructor and Deconstructor
    Queue();
    ~Queue();
    
    //  Member Functions
    bool isEmpty() const;
    void addBack(int);
    int getFront();
    void removeFront();
    void printQueue();
    void moveToLastNode();
};

#endif /* queue_hpp */
