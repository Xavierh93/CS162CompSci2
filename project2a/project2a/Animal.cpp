#include "Animal.h"

Animal::Animal()
{
	this->age = 0;
	this->numberOfBabies = 0;
	this->cost = 0;
	this->baseFoodCost = 0;
	this->payoff = 0;
}

Animal::Animal(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff)
{
	this->age = age;
	this->numberOfBabies = numberOfBabies;
	this->cost = cost;
	this->baseFoodCost = baseFoodCost;
	this->payoff = payoff;
}

void Animal::setAge(int age)
{
	this->age = age;
}

void Animal::setCost(double cost)
{
	this->cost = cost;
}

void Animal::setNumberOfBabies(int numberOfBabies)
{
	this->numberOfBabies = numberOfBabies;
}

void Animal::setBaseFoodCost(double baseFoodCost)
{
	this->baseFoodCost = baseFoodCost;
}

void Animal::setpayoff(int payoff)
{
	this->payoff = payoff;
}

int Animal::getAge()
{
	return age;
}

double Animal::getCost()
{
	return cost;
}

int Animal::getNumberOfBabies()
{
	return this->numberOfBabies;
}

double Animal::getBaseFoodCost()
{
	return this->baseFoodCost;
}

int Animal::getPayoff()
{
	return this->payoff;
}

Animal::~Animal()
{
	this->age = 0;
	this->numberOfBabies = 0;
	this->cost = 0;
	this->baseFoodCost = 0;
	this->payoff = 0;
}
