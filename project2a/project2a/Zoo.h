#pragma once
#include "Penguin.h"
#include "Tiger.h"
#include "Turtle.h"

class Zoo
{
public:
	//  Default constructor
	Zoo();

	double startZoo(int tigers, int penguins, int turtles);

	void sickness();

	void boom();

	//bornbaby
	void bornbaby();

	//printProfit
	void printProfit();

	//getFoodCost of a day
	double foodCostADay();

	//buy adult animal
	double buyAnAdultAnimal(int type);
	

	~Zoo();
private:

	//add animal in zoo
	void addTiger();
	void addPenguin();
	void addTurtle();

	//kill an animal from zoo
	void killATiger(int index);
	void killAPenguin(int index);
	void killATurtle(int index);

	Tiger *tiger;
	Penguin *penguin;
	Turtle *turtle;
	int tiger_size, penguin_size, turtle_size;
	int tiger_length, penguin_length, turtle_length;
};

