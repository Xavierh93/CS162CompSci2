//  This is the file for the menu function in the program.
//  Created by Xavier on 2/21/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "menu.hpp"
#include "queue.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

void titleDisplay()
{
    cout << "***Welcome to a Circularly Linked Queue***" << endl << endl;
}

//  The entire program runs from this function
void menuDisplay()
{
    //  Variables
    int choice = 0;
    int value;
    // Create object
    Queue q;
    
    //  Loops the menu display until user decides to terminate the program
    while (choice != 6)
    {
        cout << endl << "Choose from the following options: " << endl << endl;
        cout << "1: Enter a value to be added to the back of the queue." << endl;
        cout << "2: Display the first node (front) value from the queue." << endl;
        cout << "3: Remove the first node (front) value from the queue." << endl;
        cout << "4: Display the queue contents." << endl;
        cout << "5: Move front node to the back." << endl;
        cout << "6: Exit program." << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        //  Input validation
        while (choice < 1 || choice > 6)
        {
            cin.clear();
            cin.ignore();
            cout << "Selection not valid. Please try again: ";
            cin >> choice;
        }
        
        switch (choice)
        {
            case 1:
                cout << endl << "Please enter a positive integer: ";
                cin >> value;
                while (value < 1 || value > 1000000)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Selection not valid. Please try again." << endl;
                    cout << "Please enter a positive integer: ";
                    cin >> value;
                }
                q.addBack(value);
                cin.clear();
                cin.ignore();
                break;
            case 2:
                cout << endl << "The first node value in the queue is: " << q.getFront() << endl;
                cin.clear();
                cin.ignore();
                break;
            case 3:
                q.removeFront();
                cin.clear();
                cin.ignore();
                break;
            case 4:
                cout << endl << "The current queue is: ";
                q.printQueue();
                cin.clear();
                cin.ignore();
                break;
            case 5:
                q.moveToLastNode();
                cout << endl << "The current queue is: ";
                q.printQueue();
                cin.clear();
                cin.ignore();
                break;
            case 6:
                cout << endl << "Now terminating program..." << endl << endl;
                usleep(1000000);
                exit(0);
        }
    }
}


