//  This is the function file for the copyArray function
//  Created by Xavier on 2/27/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "copyArray.hpp"
#include <fstream>
using namespace std;

//  Function to copy the array to the output file
void copyArray(ofstream &oFile, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        oFile << array[i] << " ";
    }
}

