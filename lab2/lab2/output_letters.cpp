//  This is the function file for the function that asks the user for the filename the user would like to output to, then outputs the frequencies of letters to the output file in the format specified above.
//  Created by Xavier on 1/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include "output_letters.hpp"
using namespace std;

void output_letters(ofstream& outputFile, int* frequency) {
    int n = 0;
    
    for (n = 0; n < 26; n++)
    {
        outputFile << static_cast<char>((n + 97)) << " : " << frequency[n] << endl;  //Converts n to char and then adds appropriate number(97) to reach ASCII codes for lowercase alphabet (97-122)
    }
}

