#include "Cat.h"

using namespace std;

Cat::Cat(int id, string name, string birthDate, string breed, string careSchedule, int weight)
	: Animal(id, name, breed, birthDate, careSchedule)
{
	this->weight = weight;
}

Cat::~Cat()
{
}

string Cat::makeSound() const
{
	return "Meow";
}

int Cat::calculateAge() const
{
	if (birthDate.length() != 10) return 0; // invalid format

	int birthYear = stoi(birthDate.substr(0, 4));
	int currentYear = 2025; //Hardcoded for now
	
	return currentYear - birthYear;
}

int Cat::getWeight() const
{
	return weight;
}

void Cat::setWeight(int newWeight)
{
	weight = newWeight;
}

string Cat::getCareInfo() const
{
	return careSchedule; //  (Not sure if it should be expanded)
}

string Cat::getType() const
{
	return "Cat";
}