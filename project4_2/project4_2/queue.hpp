//  This is the header file for the queue class.
//  Created by Xavier on 2/21/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include "character.hpp"
#include <stdio.h>
using namespace std;

class Queue
{
public:
    struct Node
    {
        Node *next;
        Node *prev;
        Character *opponent;
    };
    
    int points;
    Node *tail;
    Node *head;
    
    //  Constructor
    Queue();
    ~Queue();
    
    //  Member Functions
    void setPoints(int);
    int getPoints();
    bool isEmpty() const;
    void addHeadNode(Character*);
    void addTailNode(Character*);
    Character* getFront();
    void removeFront();
    void moveToLastNode();
};

#endif /* queue_hpp */

