/*********************************************************************
 ** Program name: lab5 - Recursion
 ** Author: Xavier Hollingsworth
 ** Date: 02/07/2018
 ** Description: This program presents a menu to the user that allows
    them to select from 3 recursive functions. The first prints a string
    in reverse. The second calculates the sum of an array of integers.
    The third calculates the triangular number of an integer N.
 *********************************************************************/

#include "reverseString.hpp"
#include "sumOfArray.hpp"
#include "triangularNumber.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <cctype>

using namespace std;


//  This function displays the menu and runs recursively until the user decides to quit the program by entering '4' at the menu prompt. It contains calls to the 3 other recursive functions depending on what the user enters in the menu
void menuDisplay()
{
    //  Create variables and create dynamic array
    int choice;
    int size;
    int *array = new int [size];
    int sum = 0;
    int N = 0;
    string reverseMe;
    
    //  Menu Display
    cout << endl;
    cout << "-------Please select an option below------" << endl;
    cout << "1: Print a string in reverse." << endl;
    cout << "2: Calculate the sum of an array of integers." << endl;
    cout << "3: Calculate the triangular number of an integer N." << endl;
    cout << "4: Quit the program." << endl;
    cin >> choice;
    while(choice < 1 || choice > 4)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection incorrect." << endl;
        menuDisplay();
    }
    
    //  Switch to determine what the user entered. Calls recursive functions accordingly
    switch(choice)
    {
        //  Case to display the reverse of a string entered by the user.
        case 1:
            cout << "Enter the string to reverse: ";
            cin.clear();
            cin.ignore();
            getline(cin, reverseMe);
            
            //  Makes sure the user only inputs characters
            while(reverseMe.find_first_of("0123456789") != -1)
            {
                cout << "No digits are allowed in the string." << endl;
                cout << "Please re-enter the string you would like to reverse: ";
                getline(cin, reverseMe);
            }
            reverseString(reverseMe);
            //  Delete dynamic array in every case to prevent memory leak
            delete [] array;
            array = nullptr;
            usleep(1500000);
            menuDisplay();
            break;
            
        //  Case to calculate the sum of a user entered aray.
        case 2:
            cout << endl << "Enter the number of integers you would like to enter into an array  to be summed separated by spaces and then press enter: ";
            cin >> size;
            while(size < 0 || size > 100)
            {
                cin.clear();
                cin.ignore();
                cout << "Input incorrect. You must enter an integer greater than 0 and less than 100: ";
                cin >> size;
            }
            //  Gets user input for the integers to be stored in the array
            cout << "Please enter the integers of the array you would like to be summed: ";
            for(int i = 0; i < size; i++)   {
                cin >> array[i];
                while(array[i] < 0 || array[i] > 10000)    {
                    cin.clear();
                    cin.ignore();
                    cout << "Input not correct. Please enter an integer between 0 and 10000: ";
                    cin >> array[i];
                }
            }
            cout << "The sum of the array is " << sumOfArray(array, size) << endl;
            delete [] array;
            array = nullptr;
            usleep(1500000);
            menuDisplay();
            break;
            
        //  Case to calculate the triangular number of an integer N.
        case 3:
            cout << "Enter an integer value to calculate the triangular number of :";
            cin >> N;
            while(N <= 0)
            {
                cin.clear();
                cin.ignore();
                cout << "You must enter an integer greater than 0. Please try again: ";
                cin >> N;
            }
            cout << endl;
            sum = triangularNumber(N);
            cout << "The triangular number of " << N << " is " << sum << endl;
            delete [] array;
            array = nullptr;
            usleep(1500000);
            menuDisplay();
            break;
            
        //  Case to terminate program
        case 4:
            cout << "Thank you for playing. Now terminating the program :)" << endl;
            usleep(1500000);
            delete [] array;
            array = nullptr;
            exit(0);
    }
    
}

int main() {
    
    //  Run the menu function until the user decides to quit.
    menuDisplay();
    
    return 0;
}
