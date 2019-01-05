#include "Zoo.h"



Zoo::Zoo()
{
	tiger_size = penguin_size = turtle_size = 10;
	tiger_length = penguin_length = turtle_length = 0;
	this->tiger = new Tiger[tiger_size];
	this->penguin = new Penguin[penguin_size];
	this->turtle = new Turtle[turtle_size];
}

void Zoo::addTiger()
{
	if (this->tiger_length >= this->tiger_size)
	{
		Tiger * temp = new Tiger[this->tiger_size];
		for (int i = 0; i < this->tiger_length; i++)
		{
			temp[i] = this->tiger[i];
		}
		delete[] this->tiger;
		this->tiger_size *= 2; // dubling the array size
		this->tiger = new Tiger[this->tiger_size];
		for (int i = 0; i < this->tiger_length; i++)
		{
			this->tiger[i] = temp[i];
		}
		delete[] temp;
	}
	this->tiger_length++;
}

void Zoo::addPenguin()
{
	if (this->penguin_length >= this->penguin_size)
	{
		Penguin * temp = new Penguin[this->penguin_size];
		for (int i = 0; i < this->penguin_length; i++)
		{
			temp[i] = this->penguin[i];
		}
		delete[] this->tiger;
		this->penguin_size *= 2; // Doubles array size
		this->penguin = new Penguin[this->penguin_size];
		for (int i = 0; i < this->penguin_length; i++)
		{
			this->penguin[i] = temp[i];
		}
		delete[] temp;
	}
	this->penguin_length++;
}

void Zoo::addTurtle()
{
	if (this->turtle_length >= this->turtle_size)
	{
		Turtle * temp = new Turtle[this->turtle_size];
		for (int i = 0; i < this->turtle_length; i++)
		{
			temp[i] = this->turtle[i];
		}
		delete[] this->tiger;
		this->turtle_size *= 2; // Doubles array size
		this->turtle = new Turtle[this->turtle_size];
		for (int i = 0; i < this->turtle_length; i++)
		{
			this->turtle[i] = temp[i];
		}
		delete[] temp;
	}
	this->turtle_length++;
}

void Zoo::killATiger(int index)

{
	if (index != this->tiger_length - 1)
	{
		for (int i = index; i < this->tiger_length - 1; i++)
		{
			this->tiger[i] = this->tiger[i + 1];
		}
	}
	this->tiger_length--;
}

void Zoo::killAPenguin(int index)
{
	if (index != this->penguin_length - 1)
	{
		for (int i = index; i < this->penguin_length - 1; i++)
		{
			this->penguin[i] = this->penguin[i + 1];
		}
	}
	this->penguin_length--;
}

void Zoo::killATurtle(int index)
{
	if (index != this->turtle_length - 1)
	{
		for (int i = index; i < this->turtle_length - 1; i++)
		{
			this->turtle[i] = this->turtle[i + 1];
		}
	}
	this->turtle_length--;
}

double Zoo::startZoo(int tigers, int penguins, int turtles)
{
	double cost = 0;
	this->tiger_length = tigers;
	this->penguin_length = penguins;
	this->turtle_length = turtles;
	cost += ((this->tiger[0].getCost()*0.2) + this->tiger[0].getCost()) * tigers;
	cost += ((this->penguin[0].getCost()*0.1) + this->penguin[0].getCost()) * penguins;
	cost += ((this->turtle[0].getCost()*0.05) + this->turtle[0].getCost()) * turtles;
	// set all buyed animal age is 1
	for (int i = 0; i < this->tiger_length; i++)
	{
		this->tiger[i].setAge(1);
	}
	for (int i = 0; i < this->penguin_length; i++)
	{
		this->penguin[i].setAge(1);
	}
	for (int i = 0; i < this->turtle_length; i++)
	{
		this->turtle[i].setAge(1);
	}
	return cost;
}

void Zoo::sickness()
{
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		if (this->tiger_length > 0)
		{
			killATiger(rand() % this->tiger_length); // kill a random tiger
			cout << "Tiger is Died Due to sickness\n";
		}
		break;
	case 1:
		if (this->penguin_length > 0)
		{
			killAPenguin(rand() % this->penguin_length); // kill a random penguin
			cout << "Penguin is Died Due to sickness\n";
		}
		break;
	case 2:
		if (this->turtle_length > 0)
		{
			killATurtle(rand() % this->turtle_length); // kill a random turtle
			cout << "Turtle is Died Due to sickness\n";
		}
		break;
	}
}

void Zoo::boom()
{
	for (int i = 0; i < this->tiger_length; i++)
	{
		this->tiger[i].getBonus();
	}
	cout << "All Tigers got BOOM\n";
}

void Zoo::bornbaby()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++) 
	{
		int animaltype = rand() % 3;
		if (animaltype == 0) //if tiger
		{
			if (this->tiger_length > 0)
			{
				if (this->tiger[rand() % this->tiger_length].bornBaby())
				{
					this->addTiger(); // birth one baby of tiger...
					cout << "Tiger Born A baby Tiger\n";
					return;
				}
			}
		}
		else if (animaltype == 1) //if tiger
		{
			if (this->penguin_length > 0) 
			{
				if (this->penguin[rand() % this->penguin_length].bornBaby())
				{
					for (int j = 0; j < 5; j++)
					{
						this->addPenguin(); // birth 5 baby of penguin...
					}
					cout << "Penguin Born 5 baby Penguins\n";
					return;
				}
			}
		}
		else
		{
			if (this->turtle_length > 0) {
				if (this->turtle[rand() % this->turtle_length].bornBaby())
				{
					for (int j = 0; j < 10; j++)
					{
						this->addTurtle(); // birth 10 baby of turtle...
					}
					cout << "Turtle Born 10 baby Turtles\n";
					return;
				}
			}
		}
	}

	for (int i = 0; i < this->tiger_length; i++)
	{
		if (this->tiger[i].bornBaby())
		{
			this->addTiger();
			cout << "Tiger Born A baby Tiger\n";
			return;
		}
	}
	for (int i = 0; i < this->penguin_length; i++)
	{
		if (this->penguin[i].bornBaby())
		{
			for (int j = 0; j < 5; j++)
			{
				this->addPenguin();
			}
			cout << "Penguin Born 5 baby Penguins\n";
			return;
		}
	}
	for (int i = 0; i < this->turtle_length; i++)
	{
		if (this->turtle[i].bornBaby())
		{
			for (int j = 0; j < 10; j++)
			{
				this->addTurtle();
			}
			cout << "Turtle gave birth to 10 baby Turtles\n";
			return;
		}
	}
	cout << "There are not any adult animals to give birth at this time\n";
}

void Zoo::printProfit()
{
	double sum = 0;
	for (int i = 0; i < this->tiger_length; i++)
	{
		sum += this->tiger[i].getPayoff();
	}
	cout << "Tiger No. " << this->tiger_length << " Profit: " << sum << endl;
	sum = 0;
	for (int i = 0; i < this->penguin_length; i++)
	{
		sum += this->penguin[i].getPayoff();
	}
	cout << "penguin No. " << this->penguin_length << " Profit: " << sum << endl;
	sum = 0;
	for (int i = 0; i < this->turtle_length; i++)
	{
		sum += this->turtle[i].getPayoff();
	}
	cout << "Turtle No. " << this->turtle_length << " Profit: " << sum << endl;
}

//calculate food cost of all animals
double Zoo::foodCostADay()
{
	double sum = 0;
	for (int i = 0; i < this->tiger_length; i++)
	{
		sum += this->tiger[i].getBaseFoodCost();
	}
	for (int i = 0; i < this->penguin_length; i++)
	{
		sum += this->penguin[i].getBaseFoodCost();
	}
	for (int i = 0; i < this->turtle_length; i++)
	{
		sum += this->turtle[i].getBaseFoodCost();
	}
	return sum;
}

double Zoo::buyAnAdultAnimal(int type)
{
	double cost;
	switch (type)
	{
	case 0:
		this->addTiger();
		this->tiger[this->tiger_length - 1].setAge(3); // Make the tiger an adult
		cost = ((this->tiger[this->tiger_length - 1].getCost()*0.2) * 3) + this->tiger[this->tiger_length - 1].getCost();
		break;
	case 1:
		this->addPenguin();
		this->penguin[this->penguin_length - 1].setAge(3); // Make the penguin an adult
		cost = ((this->penguin[this->penguin_length - 1].getCost()*0.1) * 3) + this->penguin[this->penguin_length - 1].getCost();
		break;
	case 2:
		this->addTurtle();
		this->turtle[this->turtle_length - 1].setAge(3); // Make the turtle an adult
		cost = ((this->turtle[this->turtle_length - 1].getCost()*0.05) * 3) + this->turtle[this->turtle_length - 1].getCost();
		break;
	default:
		this->addTurtle();
		this->turtle[this->turtle_length - 1].setAge(3); // Make the turtle an adult
		cost = ((this->turtle[this->turtle_length - 1].getCost()*0.05) * 3) + this->turtle[this->turtle_length - 1].getCost();
		break;
	}
	return cost;
}

Zoo::~Zoo()
{
}
