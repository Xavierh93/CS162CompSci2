//  This is the function file for the function that reads the paragraph string from the input file stream, then counts the letter frequencies in the paragraph, and stores the frequencies in the array.
//  Created by Xavier on 1/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include "count_letters.hpp"
using namespace std;

void count_letters(ifstream &inputFile, int* array) {
    string str;
    string input;
    const int alphabet = 26; //Constant variable since there are 26 letters in the alphabet
    int i = 0;
    char c;
    array[alphabet] = {0}; //Initializes array to 0
    
    
    while (getline(inputFile, input))   //Stores characters in input string until a newline is reached because \n is the default delimiting character
    {
        if (input.empty())  //String class member function that skips blank spaces
            break;
        else
            str = str + input;  //Stores the string from input into str and concatinates the characters
    }

    //Runs while i (which is initialized to 0 obviously) is less than the length of the string stored in the str object.
    for (i = 0; i < str.length(); i++)
    {
        c = tolower(str[i]);  //Lowers the characters if they are uppercase
    
        if (static_cast<int>(c) >= 97 && static_cast<int>(c) <= 122) //This sets c to int and compares to the ASCII codes for alphabet
        {
            array[static_cast<int>(c) - 97] += 1;   //Updates the count of the characters
        }
    }
}
