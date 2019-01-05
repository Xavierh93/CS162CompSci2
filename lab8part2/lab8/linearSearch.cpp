//  This is the function file for the Linear Search function
//  Created by Xavier on 2/27/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "linearSearch.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//  This is the linear search function. It was used from the C++ Early Objects ninth edition textbook written by Tony Gaddis, Judy Walters, and Godfrey Muganda
void linearSearch(string fileName, int array[], int size, int target)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while (index < size && !found)
    {
        if (array[index] == target)
        {
            found = true;
            position = index;
        }
        index++;
    }
    if (position == -1)
    {
        cout << target << " was not found in file " << fileName << endl;
    }
    else
    {
        cout << target << " has been found in file " << fileName << " in " << index << " number of comparisons." << endl;
    }
    return;
}
