#include "Penguin.h"



Penguin::Penguin() :Animal(0, 1000, 0, 10, 0)
{
}

void Penguin::spendADay()
{
	setAge(this->getAge() + 1); // increse one day in age
	setpayoff(getPayoff() + (0.1*getCost())); // 20% increment in payoff of Penguin
}

bool Penguin::bornBaby()
{
	if (getAge() >= 3)
	{
		setNumberOfBabies(getNumberOfBabies() + 5);
		return true;
	}
	return false;
}

Penguin::~Penguin()
{
}
