//  This is the function file for the binarySearch function
//  Created by Xavier on 2/27/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "binarySearch.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


//  This function was used from the C++ Early Objects ninth edition textbook
//  written by Tony Gaddis, Judy Walters, and Godfrey Muganda
void binarySearch(ifstream &iFile, int value, int size, string fileName)
{
    int array[size];
    
    //  Stores the file received as a reference into an array so it is easier to process.
    while(!iFile.eof())
    {
        for (int i = 0; i < size; i++)
        {
            iFile >> array[i];
        }
    }
    int first = 0;
    int last = size-1;
    int middle;
    int position = -1;
    bool found = false;
    int count = 0;
    
    while (!found && first <= last)
    {
        middle = (first + last)/2;
        if (array[middle] == value)
        {
            found = true;
            position = middle;
            count++;
        }
        else if (array[middle] > value)
        {
            last = middle - 1;
            count++;
        }
        else
        {
            first = middle + 1;
            count++;
        }
    }
    if (!found)
    {
        cout << "The target value " << value << " was not found in the file " << fileName << endl;
        return;
    }
    else
    {
        cout << "The target value " << value << " was found in " << count << " number of iterations in file " << fileName << "." << endl;
        return;
    }
}
