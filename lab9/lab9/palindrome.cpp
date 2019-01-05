//  This is the function file for the pal;indrome portion of the program.
//  Created by Xavier on 3/9/18.
//  Copyright © 2018 Xavier. All rights reserved.


#include "palindrome.hpp"
#include "functions.hpp"
#include "queue.hpp"
#include <string>
#include <iostream>
#include <stack>
using namespace std;

void palindrome()
{
    char pali[100];
    int length;
    
    cout << "Enter a string that you would like to be displayed as a palindrome: ";
    cin.ignore();
    cin.getline(pali, 100);
    
    cout << "The string you entered displayed as a palindrome is: ";
    
    length = strlen(pali);
    cout << pali;
    
    reverse(pali, length);
    cout << pali;
    cout << endl << endl;
}

void reverse(char *pali, int length)
{
    stack<char> palin;
    
    for (int i = 0; i < length; i++)
    {
        palin.push(pali[i]);
    }
    for (int i = 0; i < length; i++)
    {
        pali[i] = palin.top();
        palin.pop();
    }
}
