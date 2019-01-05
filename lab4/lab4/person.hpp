//  This the header file for the Person, Student, and instructor class.
//  Created by Xavier on 1/31/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef person_hpp
#define person_hpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;



//  Base class Person
class Person {
protected:
    string name;
    int age;
    const int MAXVALUE = 15;
    const int MINVALUE = 1;
public:
    Person();
    Person(string name, int age);
    ~Person() {};
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    //  Use virtual functions to give objects the correct function to use
    virtual void do_work() {};
    virtual void printPerson() {};
    virtual void printName() {};
    
};

// Derived class Student
class Student : public Person {
protected:
    double gpa;
    
public:
    Student();
    void setGpa(double gpa);
    double getGpa();
    void do_work();
    void printPerson();
    void printName();
};

//  Derived class Person
class Instructor : public Person {
private:
    double rating;
public:
    Instructor ();
    void setRating(double rating);
    double getRating();
    void do_work();
    void printPerson();
    void printName();
};

#endif /* person_hpp */

