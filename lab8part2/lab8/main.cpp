/***********************************************************************
 ** Program name: Lab 8
 ** Author: Xaiver Hollingsworth
 ** Date: 02/26/2018
 ** Description: This program creates 4 text files with integers in it unsorted.
 ** It then asks the user for a target value to search for. It first uses the linear
 ** search function to search for the target. Then it asks the user for the new output
 ** file names for each file and then uses the selection sort function to sort the
 ** integers in their own separate files and displays the sorted files.
 ** Then the program uses the binary search function to search for the same target value.
 ***********************************************************************/
#include "readFile.hpp"
#include "showArray.hpp"
#include "linearSearch.hpp"
#include "selectionSort.hpp"
#include "copyArray.hpp"
#include "displayFile.hpp"
#include "binarySearch.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    //  Initialzie variables
    const int length = 10;
    const int size = 9;
    int target;
    int num = 0;
    int count = 0;
    int n1array[size], n2array[length], n3array[length], n4array[length];
    string fileName1, fileName2, fileName3, fileName4;
    
    
    //  Create text files with numbers in them
    ofstream o1("numbers1.txt", ios::out);
    for (int i = 1; i < (size+1); i++)
    {
        o1 << i << " ";
    }
    o1.close();
    
    
    ofstream o2("numbers2.txt", ios::out);
    o2 << num << " ";
    for (int i = 1; i < (length); i++)
    {
        o2 << i << " ";
    }
    o2.close();

    
    ofstream o3("numbers3.txt", ios::out);
   for (int i = 1; i < (length); i++)
    {
        o3 << i << " ";
        count++;
        if (count == length/2)
        {
            o3 << num << " ";
        }
    }
    o3.close();
    
    ofstream o4("numbers4.txt", ios::out);
    for (int i = 1; i < (length); i++)
    {
        o4 << i << " ";
    }
    o4 << num << " ";
    o4.close();
    
    //  Create ifstream objects for file input functions
    ifstream iFile1, iFile2, iFile3, iFile4;
    
    iFile1.open("numbers1.txt");
    readFile(iFile1, n1array, size);
    iFile1.close();
    cout << "The values in numbers1.txt are currently: ";
    showArray(n1array, size);
    
    iFile2.open("numbers2.txt");
    readFile(iFile2, n2array, length);
    iFile2.close();
    cout << "The values in numbers2.txt are currently: ";
    showArray(n2array, length);
    
    iFile3.open("numbers3.txt");
    readFile(iFile3, n3array, length);
    iFile3.close();
    cout << "The values in numbers3.txt are currently: ";
    showArray(n3array, length);
    
    iFile4.open("numbers4.txt");
    readFile(iFile4, n4array, length);
    iFile4.close();
    cout << "The values in numbers4.txt are currently: ";
    showArray(n4array, length);
    
    //  Retrieves the target the user would like to search for and validates the user inout
    cout << "Enter the target value you would like to search for: ";
    cin >> target;
    while (target < 0 || (!cin >> target))
    {
        cin.clear();
        cin.ignore();
        cout << "Selection invalid. Enter the target value you would like to search for: ";
        cin >> target;
    }
    
    //  Call linear search function to search for the target in each file
    linearSearch("numbers1.txt", n1array, size, target);
    linearSearch("numbers2.txt", n2array, length, target);
    linearSearch("numbers3.txt", n3array, length, target);
    linearSearch("numbers4.txt", n4array, length, target);
    
    //  Use selection sort to sort the numbers in the arrays
    selectionSort("numbers1.txt", n1array, size);
    selectionSort("numbers2.txt", n2array, length);
    selectionSort("numbers3.txt", n3array, length);
    selectionSort("numbers4.txt", n4array, length);
    
    //  Create ofstream objects to perform output file functions
    ofstream oFile1, oFile2, oFile3, oFile4;
    
    //  Clear cin input
    cin.clear();
    cin.ignore();
    
    //  Asks user for new output file names and then displays the new sorted file
    cout << "Enter the output file name for file #1: ";
    getline(cin, fileName1);
    oFile1.open(fileName1.c_str(), ios::out);
    copyArray(oFile1, n1array, size);
    oFile1.close();
    iFile1.open(fileName1);
    displayFile(iFile1, fileName1);
    iFile1.close();
    
    cout << "Enter the output file name for file #2: ";
    getline(cin, fileName2);
    oFile2.open(fileName2.c_str(), ios::out);
    copyArray(oFile2, n2array, length);
    oFile2.close();
    iFile2.open(fileName2);
    displayFile(iFile2, fileName2);
    iFile2.close();

    cout << "Enter the output file name for file #3: ";
    getline(cin, fileName3);
    oFile3.open(fileName3.c_str(), ios::out);
    copyArray(oFile3, n3array, length);
    oFile3.close();
    iFile3.open(fileName3);
    displayFile(iFile3, fileName3);
    iFile3.close();
    
    cout << "Enter the output file name for file #4: ";
    getline(cin, fileName4);
    oFile4.open(fileName4.c_str(), ios::out);
    copyArray(oFile4, n4array, length);
    oFile4.close();
    iFile4.open(fileName4);
    displayFile(iFile4, fileName4);
    iFile4.close();
    
    
    //  Uses binary search to search for the target value entered earlier by the user
    iFile1.open(fileName1);
    binarySearch(iFile1, target, size, fileName1);
    iFile1.close();
    
    iFile2.open(fileName2);
    binarySearch(iFile2, target, length, fileName2);
    iFile2.close();
    
    iFile3.open(fileName3);
    binarySearch(iFile3, target, length, fileName3);
    iFile3.close();
    
    iFile4.open(fileName4);
    binarySearch(iFile4, target, length, fileName4);
    iFile4.close();
    
    return 0;
}
