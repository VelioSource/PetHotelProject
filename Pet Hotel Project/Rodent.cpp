#include "Rodent.h"
using namespace std;

// Constructor
Rodent::Rodent(int id, string name, string birthDate, string breed, string careSchedule, string type)
	: Animal(id, name, breed, birthDate, careSchedule)
{
	this->type = type;
}
// Destructor
Rodent::~Rodent()
{
}

string Rodent::makeSound() const
{
	return "Squeak!";
}

int Rodent::calculateAge() const
{
	if (birthDate.length() != 10) return 0; // invalid format
	
	int birthYear = stoi(birthDate.substr(0, 4));
	int currentYear = 2025; //Hardcoded for now
	
	return currentYear - birthYear;

}

string Rodent::getType() const
{
	return "Rodent";
}

string Rodent::getRodentType() const
{
	return type;
}

void Rodent::setRodentType(const string newType)
{
	type = newType;
}

void Rodent::setType(const string newType)
{
	type = newType;
}


string Rodent::getCareInfo() const
{
	return careSchedule; //  expand this later
}
