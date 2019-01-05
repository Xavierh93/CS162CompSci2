//  This if the file for the function sumOfArray which calculates the sum of an array
//  of integers and prints it out.
//  Created by Xavier Elon Hollingsworth on 2/7/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.

#include "sumOfArray.hpp"
#include <iostream>
using namespace std;


//  This function receives a dynamic array pointer and the size of the array as parameters. If the size is 1 it returns the value of the first element in the array. If the value is greater it recursively calls the function and add its to the first element until the size equals 1
int sumOfArray(int *array, int size)
{
    if(size == 1)   {
        return array[0];
    }
    else
    {
        return array[0] + sumOfArray(array+1, size-1);
    }
    
}


