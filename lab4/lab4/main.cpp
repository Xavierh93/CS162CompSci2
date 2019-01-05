//  This program is a simulated database for Oregon State University where it can display the buildings, display the people, and choose a person to do work. It uses polymorphism and inheritance to achieve this.
//  Created by Xavier on 1/31/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include "person.hpp"
#include "university.hpp"
#include "building.hpp"


#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
     int choice = 0;
    //  Create all necessary objects and instantiate it them with programmer input
    Student student;
    Instructor instructor;
    
    student.setName("Elon Musk");
    student.setAge(42);
    student.setGpa(4.0);
    
    instructor.setName("Bill Gates");
    instructor.setAge(60);
    instructor.setRating(5.0);
    
    Building building;
    Building building2;
    
    building.setName("SHepard Hall");
    building.setSize(9727);
    building.setAddress("2001 SW Campus Way, Corvallis, OR 97331");
    
    building2.setName("Magruder Hall");
    building2.setSize(118691);
    building2.setAddress("700 SW 30th St, Corvallis, OR 97331");
    
    University university;
    
    university.setName("Oregon State University");
    //  Stores objects into vectors
    university.persons.emplace_back(&student);
    university.persons.emplace_back(&instructor);
    university.buildings.push_back(building);
    university.buildings.push_back(building2);
    
    //  Generate random seed for do_work functions
    unsigned seed;
    seed = time(0);
    srand(seed);
    //  Run menu until user decides to quit
    while(choice != 4){
        cout << "--- Welcome to the University Database ---" << endl;
        cout << "*Please select an integer option below*" << endl;
        cout << "1. Print information about all of the buildings." << endl;
        cout << "2. Print information about everybody at the university." << endl;
        cout << "3. Choose a person to do work." << endl;
        cout << "4. Exit the program." << endl;
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
            cin.clear();
            cin.ignore();
            cout << "Selection incorrect. Please enter 1, 2, 3, or 4." << endl;
            cin >> choice;
        }
        
        switch(choice) {
            case 1:
                university.printBuildings();
                break;
            case 2:
                university.printPersons();
                cout << endl;
                break;
            case 3:
                university.editPersons();
                break;
            case 4:
                exit(0);
                break;
    
    return 0;
}
    }
}


