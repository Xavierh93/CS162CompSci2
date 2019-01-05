//  This is the file for the function that prints a string produced by the user in reverse.
//  Created by Xavier Elon Hollingsworth on 2/7/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.


#include "reverseString.hpp"
#include <iostream>
#include <string>
using namespace std;

//  This function takes the constant string str as a reference which was entered by the user. It sets the variable chars equal to the size of str. If chars is equal to 1 it prints out str. If not it prints out the last character of str by subtractig chars from 1. Then it recursively calls this function with str as an object calling substr(subtract string) function with the parameters 0 (for the beginning of the string) and chars - 1 (for the last character in chars. The substr function removes everything in the string not between chars -1 and 0.
void reverseString(const string &str)
{
    size_t chars = str.size();
    if (chars == 1) {
        cout << str << endl;
    }else {
        cout << str[chars -1];
        reverseString(str.substr(0, chars -1));
        
    }
}
