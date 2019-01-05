//  Created by Xavier on 1/31/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "person.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//  Base Class - Person
Person::Person() {
    this->name = " ";
    this ->age = 0;
}

Person::Person(string name, int age) : name(name), age(age)
{
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getName() {
    return name;
}

void Person::setAge(int age) {
    this->age = age;
}

int Person::getAge() {
    return age;
}




//  Derived Student class

Student::Student() {
    this->name = " ";
    this->age = 0;
    this->gpa = 0.0;
}

void Student::setGpa(double gpa) {
    this->gpa = gpa;
}

double Student::getGpa() {
    return gpa;
}

//  Function generates random number within programmer specified range and displays it in a message
void Student::do_work() {
    int number;
   
    number = (rand() % (MAXVALUE - MINVALUE + 1)) + MINVALUE;
    cout << name << " did " << number << " hours of homework." << endl;
}

void Student::printPerson() {
    cout << "Name: " << name << endl << "Age: " << age << endl << "GPA: " << getGpa() << endl << endl;
}

void Student::printName() {
    cout << name << endl;
}


//  Derived Instructor class
Instructor::Instructor() {
    this->name = " ";
    this->age = 0;
    this->rating = 0.0;
}

void Instructor::setRating(double rating) {
    this->rating = rating;
}

double Instructor::getRating() {
    return rating;}

//  Function generates random number within programmer specified range and displays it in a message
void Instructor::do_work() {
    int number;
    
    number = (rand() % (MAXVALUE - MINVALUE + 1)) + MINVALUE;
    cout << name << " graded papers for " << number << " hours." << endl;
}

void Instructor::printPerson() {
    cout << "Name: " << name << endl << "Age: " << age << endl << "Rating: " << rating << endl << endl;
}

void Instructor::printName() {
    cout << name << endl;
}
