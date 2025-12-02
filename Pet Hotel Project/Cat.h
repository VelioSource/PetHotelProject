#pragma once
#include "Animal.h"

class Cat : public Animal
{
private:
	int weight;
public:
	Cat(int id, std::string name, std::string birthDate, std::string breed, std::string careSchedule, int weight);
	virtual ~Cat();
	
	virtual std::string makeSound() const;
	virtual int calculateAge() const;
	virtual std::string getCareInfo() const;
	virtual std::string getType() const;
	
	int getWeight() const;
	void setWeight(int newWeight);
};

