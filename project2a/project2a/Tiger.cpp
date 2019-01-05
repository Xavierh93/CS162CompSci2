#include "Tiger.h"



Tiger::Tiger() :Animal(0, 10000, 0, 10 * 5, 0)
{
}

void Tiger::spendADay()
{
	setAge(this->getAge() + 1); // increse one day in age
	setpayoff(getPayoff() + (0.2*getCost())); // 20% increment in payoff of a tiger 
}

void Tiger::getBonus()
{
	srand(time(NULL)); //use srand to get diffrent number on every rand function call
	setpayoff(getPayoff() + (rand() % 250 + 250)); //genrate Bonus from 250 - 500 for a tiger
}

bool Tiger::bornBaby()
{
	if (getAge() >= 3)
	{
		setNumberOfBabies(getNumberOfBabies() + 1);
		return true;
	}
	return false;
}

Tiger::~Tiger()
{
}
