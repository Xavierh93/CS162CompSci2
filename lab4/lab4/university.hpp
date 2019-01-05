//  This is the header file for the University class
//  Created by Xavier on 1/31/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include "person.hpp"
#include <stdio.h>
#include <string>
#include <vector>
#ifndef university_hpp
#define university_hpp


using namespace std;

class Person;
class Building;

class University
{
public:
    string name;
    //  Create vectors to hold the objects created in the program
    vector<Person*> persons;
    vector<Building> buildings;
    
    University();
    void setName(string name);
    void printBuildings();
    void printPersons();
    void editPersons();
};



#endif

