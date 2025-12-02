#pragma once
#include "Animal.h"
using namespace std;


class Dog : public Animal
{
private:
	int weight;
public:
	Dog(int id, string name, string breed, string birthDate, string careSchedule, int weight);
	virtual ~Dog();

	virtual string makeSound() const;
	virtual int calculateAge() const;
	virtual string getCareInfo() const;
	virtual string getType() const;

	int getWeight() const;
	void setWeight(int newWeight);
};

