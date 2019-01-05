/***********************************************************************
 ** Program name: Lab 10 - Fibonacci Numbers Calculation Comparisons
 ** Author: Xaiver Hollingsworth
 ** Date: 03/12/2018
 ** Description: This program measures and campares the running time of
 ** recursive and iterative implementations of the Fibonacci Numbers
 ** Calculations and displays them on the screen.
 ** Sources: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 **          http://www.cplusplus.com/reference/ctime/clock/
 **          https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
 ***********************************************************************/


#include "functions.hpp"
#include "iterative.hpp"
#include "recursive.hpp"
#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<long> *iterative = new vector<long>();
    vector<long> *recursive = new vector<long>();
    vector<int> *term = new vector<int>();
    runProgram(iterative, recursive, term);
    
    delete iterative;
    delete recursive;
    delete term;
    
    return 0;
}
