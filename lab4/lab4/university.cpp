//  This is the University class file
//  Created by Xavier on 1/31/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include "university.hpp"
#include "building.hpp"
#include "person.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//  Default constructor
University::University() {
   
}

void University::setName(string name) {
    this->name = name;
}


void University::printBuildings() {
    cout << "Building details: " << endl;
    for(int i = 0; i < buildings.size(); i++) {
        buildings[i].printBuilding();
    }
}

void University::printPersons() {
        cout << "Persons: " << endl;
        for(int i = 0; i < persons.size(); i++) {
            persons[i]->printPerson();
    }
}

//  Function which displays all the people stored in the vector and then asks the user which person they want to do work
void University::editPersons() {
    int choice;
    
    cout << "Please select the number of the person you would like to edit." << endl;
    for(int i = 0; i < persons.size(); i++) {
        cout << i+1 << ": ";
        persons[i]->printName();
    }
    cin >> choice;
    while(choice < 1 && choice > persons.size()) {
        cin.clear();
        cin.ignore();
        cout << "Selection incorrect. You must enter an integer listed above. Please try again: ";
        cin >> choice;
    }
    persons[choice - 1]->do_work();
}


