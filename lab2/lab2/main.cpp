//  This program asks the user for a file name and then reads that file, counts the letter frequencies in the file, and writes the reults to different files for each paragraph.
//  Created by Xavier on 1/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include <fstream>
#include <string>
#include <iostream>
#include "output_letters.hpp"
#include "count_letters.hpp"
using namespace std;

int main() {
    //Create objects and variables
    ifstream fileInput;
    ofstream fileOutput;
    string iFilename, oFilename, displayFile;
    int array[26] = {0};    //Initialize the array to 0
    int n = 1;
    char choice, ch;
    
    
    cout << "Please enter the filename that you would like to be read: " << endl;
    cin >> iFilename;
    //Open the file. If the file does not open it repeats the prompt until given a proper filename to open.
    fileInput.open(iFilename.c_str(), ios::in);
    //While loop that starts if file cannot be found and prompts user to enter another filename until one is correctly opened
    while (!fileInput){
        cout << "Error opening file. Please try again: " << endl;
        cin >> iFilename;
        fileInput.open(iFilename.c_str(), ios::in);
    }
    
    //While loop that continues until the end of the file 
    while(!fileInput.eof())
    {
        count_letters(fileInput, array);
        cout << "Please enter the output filename for file " << n << ": ";
        cin >> oFilename;
        n += 1;
        fileOutput.open(oFilename.c_str(), ios::out);
        output_letters(fileOutput, array);
        fileOutput.close();
    }
    fileInput.close();
    
    //This section is just an added bonus to my program because I wanted to get more I/O practice. It is a loop that runs and asks the user if they would like to display the contents of any of the files that the user created until they select no
    cout << "Would you like to display the contents of a file you created? (Y/N): ";
    cin >> choice;
    
    //Do while that repeats until user selects no.
    if(choice == 'Y' || choice =='y') do {
        cout << "Please enter the file's contents you would like displayed: ";
        cin >> displayFile;
        fileInput.open(displayFile.c_str(), ios::in);
        while(!fileInput){
            cout << "Error opening file. Please try again: " << endl;
            cin >> displayFile;
            fileInput.open(displayFile.c_str(), ios::in);
        }
        fileInput.get(ch);
        while(!fileInput.fail()) {
            cout.put(ch);
            fileInput.get(ch);
        }
        fileInput.close();
        cout << "Would you like to display the contents of another file you created? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    else {
        cin.ignore();   //Skips over \n character to properly display goodbye message
    }
    cout << "Thank you for using my program" << endl;
    return 0;
}
