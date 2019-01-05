//  This is the header file for the Building class.
//  Created by Xavier on 1/31/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#ifndef building_hpp
#define building_hpp
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;


class Building
{
protected:
    string name;
    int size;
    string address;
    
public:
    Building();
    Building(string name, int size, string address);
    void printBuildings();
    void printBuilding();
    void setName(string name);
    void setSize(int size);
    void setAddress(string address);
};

#endif /* building_hpp */
