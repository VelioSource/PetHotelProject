#include "Kennel.h"
#include "Animal.h"

// Constructor
Kennel::Kennel(int id, std::string size, int capacity, std::string type)
{
    this->id = id;
    this->size = size;
    this->capacity = capacity;
    this->type = type;
}

// Destructor
Kennel::~Kennel()
{
}

// ---------- Getters ----------
int Kennel::getId() const { return id; }
std::string Kennel::getSize() const { return size; }
int Kennel::getCapacity() const { return capacity; }
std::string Kennel::getType() const { return type; }
std::vector<Animal*> Kennel::getAnimals() const { return animals; }

// ---------- Setters ----------
void Kennel::setId(int newId) { id = newId; }
void Kennel::setSize(const std::string newSize) { size = newSize; }
void Kennel::setCapacity(int newCap) { capacity = newCap; }
void Kennel::setType(const std::string newType) { type = newType; }
void Kennel::setAnimals(const std::vector<Animal*> newAnimals) { animals = newAnimals; }

// ---------- Helper ----------
void Kennel::addAnimal(Animal* a)
{
    animals.push_back(a);
}
