//  This is the function file for the displayFile function
//  Created by Xavier on 2/27/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "displayFile.hpp"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//  Displays the current file
void displayFile(ifstream &iFile, string fileName)
{
    char ch;
    ch = iFile.get();
    
    cout << "The sorted values in " << fileName << " are: ";
    while (ch != EOF)
    {
        cout << ch;
        ch =iFile.get();
    }
    cout << endl;
    iFile.close();
    return;
}
