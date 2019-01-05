//  This is the class Ant file used to hold all the board coordinates for the ant the updated board and also the direction of the ant.
//  Created by Xavier on 1/12/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include <iostream>
#include "ant.hpp"
using namespace std;

Ant::Ant(){
    cout << "The constructor is running." << endl;
}

Ant::~Ant(){
    
}

Ant::Ant(int row, int column) {
    setDirection(north);
    setPrevRow(row);
    setPrevCol(column);
    setCurrentRow(row);
    setCurrentCol(column);
    setCurrentColor(' ');
}

void Ant::setDirection(Direction d) {
    direction = d;
}

Direction Ant::getDirection()   {
    return direction;
}

void Ant::setPrevRow(int pr) {
    prevRow = pr;
}

int Ant::getPrevRow() {
    return prevRow;
}

void Ant::setPrevCol(int pc) {
    prevCol = pc;
}

int Ant::getPrevCol() {
    return prevCol;
}

void Ant::setCurrentRow(int cr) {
    currentRow = cr;
}

int Ant::getCurrentRow() {
    return currentRow;
}

void Ant::setCurrentCol(int cc) {
    currentCol = cc;
}

int Ant::getCurrentCol() {
    return currentCol;
}

void Ant::setCurrentColor(char ccc) {
    currentColor = ccc;
}

char Ant::getCurrentColor() {
    return currentColor;
}
