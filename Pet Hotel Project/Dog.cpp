#include "Dog.h"
using namespace std;

Dog::Dog(int id, string name, string breed, string birthDate, string careSchedule, int weight)
	: Animal(id, name, breed, birthDate, careSchedule), weight(weight)
{
	this->weight = weight;
}

Dog::~Dog()
{
}

string Dog::makeSound() const
{
	return "Woof!";
}

string Dog::getCareInfo() const
{
	return careSchedule; //  expand this later
}

string Dog::getType() const
{
	return "Dog";
}

int Dog::getWeight() const
{
	return weight;
}

int Dog::calculateAge() const
{
	if (birthDate.length() != 10) return 0; // invalid format

	int birthYear = stoi(birthDate.substr(0, 4));
	int currentYear = 2025; //Hardcoded for now
	
	return currentYear - birthYear;

}

void Dog::setWeight(int newWeight)
{
	weight = newWeight;
}