#pragma once
#include <time.h>
#include "Animal.h"
class Tiger :
	public Animal
{
public:
	Tiger();
	void spendADay();
	void getBonus();
	bool bornBaby();
	~Tiger();
};

