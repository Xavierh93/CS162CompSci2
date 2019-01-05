//  Lab 6 - This program creates a simple doubly-linked list data structure consisting of Node objects.
//  Created by Xavier on 2/15/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include <unistd.h>
#include <iostream>
using namespace std;

//  Node structure to create next and prev pointers and int val to hold the value of the node.
struct Node
{
    Node *next;
    Node *prev;
    int val;
};

//  *******************************************************************************************
//  DoublyLinkedList class: contains 5 functions:
//  1.  Add a node to the head of the list.
//  2.  Add a node to the tail of the list.
//  3.  Delete the first node from the head of the list.
//  4.  Delete the last node from the tail of the list.
//  5.  Traverse the node list in reverse order.
//  6. Traverse the list in original order.
//  *******************************************************************************************
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
public:
    //  Constructor to set head and tail to nullptr meaning the list is empty.
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    //  Function to add node to head of list
    void addHeadNode(int value)
    {
        Node *ptr = new Node();
        ptr -> val = value;
        if (tail == nullptr)
        {
            head = tail = ptr;
        }
        else
        {
            ptr -> next = head;
            head -> prev = ptr;
            head = ptr;
        }
    }
    
    //  Function to add node to tail of list
    void addTailNode(int value)
    {
        Node *ptr = new Node();
        
        ptr -> val = value;
        if (head == nullptr)
        {
            head = tail = ptr;
        }
        else
        {
            ptr -> prev = tail;
            tail -> next = ptr;
            tail = ptr;
        }
        
    }
    
    //  Function to delete first node from head of list
    void deleteFirstNode()
    {
        if (head != nullptr)
        {
                Node *ptr = head -> next;
                delete head;
                head = ptr;
        }
    }
    
    //  Function to delete last node from tail of list
    int deleteLastNode()
    {
         Node *ptr = tail;
        if (tail -> prev != nullptr)
        {
            tail -> prev -> next = nullptr;
        }
        tail = tail -> prev;
        int val = ptr -> val;
        delete ptr;
        return val;
    }
    
    //  Function to traverse the list in reverse order
    void traverseReversely()
    {
        Node *ptr = tail;
        cout << "The current node list in reverse is: ";
        if (ptr == nullptr)
        {
            cout << "The node list is empty." << endl;
            return;
        }
        while (ptr != nullptr)
        {
            cout << ptr -> val << " ";
            ptr = ptr -> prev;
        }
        cout << endl << endl;
    }
    
    //  Function to traverse the list in correct order
    void traverseList()
    {
        Node *ptr = head;
        cout << "The current node list is: ";
        if (ptr == nullptr)
        {
            cout << "The node list is empty. " << endl;
            return;
        }
        while (ptr != nullptr)
        {
            cout << ptr -> val << " ";
            ptr = ptr -> next;
        }
        cout << endl << endl;
    }
};


//  Function to display the menu. Runs recursively until the user decides to quit.
void displayMenu()
{
    int choice = 0;
    int number;
    DoublyLinkedList nodeList;
    
    cout << endl << "***Welcome to the Doubly-Linked List Program***" << endl << endl;
    
    //  Runs until user decides to exit the program
    while(choice != 6)
    {
        cout << "Please enter an option below:" << endl;
        cout << "1: Add a new node to the head." << endl;
        cout << "2: Add a new node to the tail." << endl;
        cout << "3: Delete the first node in the list." << endl;
        cout << "4: Delete the last node in the list." << endl;
        cout << "5: Traverse the list reversely." << endl;
        cout << "6: Exit the program." << endl;
        
        cin >> choice;
        
        
        //  Input validation
        while (choice < 1 || choice > 6)
        {
            cout << "Selection not valid. Please try again." << endl;
            cin.clear();
            cin.ignore();
            displayMenu();
        }
        switch (choice)
        {
            case 1:
                cout << "Please enter the value you would like to add: ";
                cin >> number;
                cin.clear();
                cin.ignore();
                while (number < 1)
                {
                    cout << "You must enter an integer greater than 0. Please try again: ";
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                }
                cout << endl;
                nodeList.addHeadNode(number);
                nodeList.traverseList();
                break;
            case 2:
                cout << "Please enter the value you would like to add: ";
                cin >> number;
                cin.clear();
                cin.ignore();
                while (number < 1)
                {
                    cout << "You must enter an integer greater than 0. Please try again: ";
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                }
                cout << endl;
                nodeList.addTailNode(number);
                nodeList.traverseList();
                break;
            case 3:
                nodeList.deleteFirstNode();
                nodeList.traverseList();
                break;
            case 4:
                nodeList.deleteLastNode();
                nodeList.traverseList();
                break;
            case 5:
                nodeList.traverseReversely();
                nodeList.traverseList();
                break;
            case 6:
                cout << endl << "Thank you for using my program :)" << endl << endl;
                usleep(1000000);
                exit(0);
        }
    }
}


int main() {
    displayMenu();
    return 0;
}
