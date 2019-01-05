//  This is the function file for the readFile function.
//  Created by Xavier on 2/27/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "readFile.hpp"
#include <fstream>
using namespace std;


//  This function reads the input file to an array passed as a parameter
void readFile(ifstream &iFile, int array[], int size)
{
    while(!iFile.eof())
    {
        for (int i = 0; i < size; i++)
        {
            iFile >> array[i];
        }
    }
}
