//  This is the function file for the showArray function
//  Created by Xavier on 2/27/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "showArray.hpp"
#include <iostream>
using namespace std;


//  This function displays the contents of the array passed in the parameter
void showArray(int array[], int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << array[count] << " ";
    }
    cout << endl;
}
