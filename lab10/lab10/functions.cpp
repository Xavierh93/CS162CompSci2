//  This is the file that contains all of the functions that display the menu and the results of the runtimes.


#include "functions.hpp"
#include "iterative.hpp"
#include "recursive.hpp"
#include <iostream>
#include <vector>
using namespace std;


//  Function to view the runtimes for each implementation of the program.
void viewRuntimes(vector<long> *iterative, vector<long> *recursive, vector<int> *term)
{
    cout << endl << "Runtimes for the implementations of the Fibonacci Number Calculation: " << endl;
    for (int count = 0; count < iterative->size(); count++)
    {
        cout << "Fibonacci number: " << term->at(count) << "   Iterative: " << iterative->at(count) << " (s)" << "    Recursive: " << recursive->at(count) << " (s)" << endl;
    }
    cout << endl;
    runAgain(iterative, recursive, term);
    
}


//  Function to ask user if they want to run the program again or view .
void runAgain(vector<long> *iterative, vector<long> *recursive, vector<int> *term)
{
    int choice;
    
    cin.clear();
    cout << endl << "***Please select an option below***" << endl;
    cout << "1: Run program again." << endl;
    cout << "2: View runtimes of each program implementation." << endl;
    cout << "3: Exit program." << endl;
    cout << "Enter choice: ";
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: " << endl;
        cin >> choice;
    }
    if (choice == 1)
    {
        runProgram(iterative, recursive, term);
    }
    else if (choice == 2)
    {
        viewRuntimes(iterative, recursive, term);
    }
    else
    {
        return;
    }
}


//  Function that asks the user for the Fibonacci number they would like to calculate and then calls the iterative and recursive implementations of the program.
void runProgram(vector<long> *iterative, vector<long> *recursive, vector<int> *term)
{
    int n;
    
    cout << "Enter the Fibonacci number you would like to calculate: ";
    cin >> n;
    while (n <= 0 || n > 500)
    {
        cin.clear();
        cin.ignore();
        cout << "Input invalid. Please enter an integer between 1 and 500: ";
        cin >> n;
    }
    
    term->push_back(n);
    cout << endl;
    
    iterativeFibonacci(n, iterative);
    displayFibonacci(n, recursive);
    runAgain(iterative, recursive, term);
}

