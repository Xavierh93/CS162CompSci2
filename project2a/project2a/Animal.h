#pragma once
#include<iostream> 
using namespace std;
class Animal
{
public:

	//constructors
	Animal();
	Animal(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff);

	//setters
	void setAge(int age);
	void setCost(double cost);
	void setNumberOfBabies(int numberOfBabies);
	void setBaseFoodCost(double baseFoodCost);
	void setpayoff(int payoff);

	//gettors
	int getAge();
	double getCost();
	int getNumberOfBabies();
	double getBaseFoodCost();
	int getPayoff();

	//distructors
	~Animal();

private:

	int age;
	double cost;
	int numberOfBabies;
	double baseFoodCost;
	int payoff;
};

