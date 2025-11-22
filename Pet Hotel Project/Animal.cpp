#include "Animal.h"

// Constructor
Animal::Animal(int id, std::string name, std::string breed, std::string birthDate, std::string careSchedule)
{
    this->id = id;
    this->name = name;
    this->breed = breed;
    this->birthDate = birthDate;
    this->careSchedule = careSchedule;
}

// Destructor
Animal::~Animal()
{
}

// ---------- Getters ----------
int Animal::getId() const { return id; }
std::string Animal::getName() const { return name; }
std::string Animal::getBreed() const { return breed; }
std::string Animal::getBirthDate() const { return birthDate; }
std::string Animal::getCareSchedule() const { return careSchedule; }

// ---------- Setters ----------
void Animal::setId(int newId) { id = newId; }
void Animal::setName(const std::string newName) { name = newName; }
void Animal::setBreed(const std::string newBreed) { breed = newBreed; }
void Animal::setBirthDate(const std::string newDate) { birthDate = newDate; }
void Animal::setCareSchedule(const std::string newSchedule) { careSchedule = newSchedule; }
