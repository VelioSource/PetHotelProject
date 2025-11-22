#include "Reservation.h"
#include "Animal.h"

// Constructor
Reservation::Reservation(int id, std::string start, std::string end)
{
    this->id = id;
    this->startDate = start;
    this->endDate = end;
}

// Destructor
Reservation::~Reservation()
{
}

// ---------- Getters ----------
int Reservation::getId() const { return id; }
std::string Reservation::getStartDate() const { return startDate; }
std::string Reservation::getEndDate() const { return endDate; }
std::vector<Animal*> Reservation::getAnimals() const { return animals; }

// ---------- Setters ----------
void Reservation::setId(int newId) { id = newId; }
void Reservation::setStartDate(const std::string newStart) { startDate = newStart; }
void Reservation::setEndDate(const std::string newEnd) { endDate = newEnd; }
void Reservation::setAnimals(const std::vector<Animal*> newAnimals) { animals = newAnimals; }

// ---------- Helper ----------
void Reservation::addAnimal(Animal* a)
{
    animals.push_back(a);
}
