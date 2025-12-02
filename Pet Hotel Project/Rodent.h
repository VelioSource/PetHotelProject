#pragma once
#include "Animal.h"
using namespace std;

class Rodent : public Animal
{
private:
	string type; // e.g., hamster, guinea pig
public:
	Rodent(int id, string name, string birthDate, string breed, string careSchedule, string type);
	virtual ~Rodent();
	
	virtual string makeSound() const;
	virtual int calculateAge() const;
	virtual string getCareInfo() const;


	string getType() const override;
	string getRodentType() const;
	void setRodentType(const string newType);
	void setType(const string newType);
};

