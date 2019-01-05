//  This is the file for the Building class
//  Created by Xavier on 1/31/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "building.hpp"
#include <iostream>
#include <string>
using namespace std;

//  Constructor
Building::Building() {
    this->name = " ";
    this->size = 0;
    this->address = " ";
}

void Building::setName(string name) {
    this->name = name;
}

void Building::setSize(int size) {
    this->size = size;
}

void Building::setAddress(string address) {
    this->address = address;
}

void Building::printBuilding() {
    cout << "Name of building: " << name << endl << "Address of building: " << address << endl << endl;
}
