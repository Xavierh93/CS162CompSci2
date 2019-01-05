//  This is the function file for the Selection Sort function
//  Created by Xavier on 2/27/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "selectionSort.hpp"
#include <string>
#include <fstream>
using namespace std;


//  Selection Sort function
// Citation:: C++ Early Objects Ninth Edition by Tony Gaddis, Judy Walters, and Godfrey Muganda
void selectionSort(string fileName, int array[], int size)
{
    int start, minIndex, minValue;
    
    for (start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        
        for (int index = start + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
                
            }
        }
        array[minIndex] = array[start];
        array[start] = minValue;
    }
    return;
}
