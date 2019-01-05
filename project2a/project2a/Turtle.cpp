#include "Turtle.h"



Turtle::Turtle() :Animal(0, 10, 0, 5, 0)
{
}

void Turtle::spendADay()
{
	setAge(this->getAge() + 1); // increse one day in age
	setpayoff(getPayoff() + (0.05*getCost())); // 20% increment in payoff of Turtle
}

bool Turtle::bornBaby()
{
	if (getAge() >= 3)
	{
		setNumberOfBabies(getNumberOfBabies() + 10);
		return true;
	}
	return false;
}

Turtle::~Turtle()
{
}
