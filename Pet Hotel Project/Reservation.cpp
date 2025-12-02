#include "Reservation.h"
#include "Animal.h"
#include "Kennel.h"

Reservation::Reservation(int id, std::string start, std::string end, std::vector<Animal*> pets, bool putTogether)
{
    this->id = id;
    this->startDate = start;
    this->endDate = end;
	this->animals = pets;
	this->putTogether = putTogether;

}

Reservation::~Reservation()
{
}

int Reservation::getId() const { return id; }
std::string Reservation::getStartDate() const { return startDate; }
std::string Reservation::getEndDate() const { return endDate; }
std::vector<Animal*> Reservation::getAnimals() const { return animals; }
bool Reservation::getPutTogether() const { return putTogether; }

void Reservation::setId(int newId) { id = newId; }
void Reservation::setStartDate(std::string newStart) { startDate = newStart; }
void Reservation::setEndDate(std::string newEnd) { endDate = newEnd; }
void Reservation::setAnimals(std::vector<Animal*> newAnimals) { animals = newAnimals; }
void Reservation::setPutTogether(bool value) { putTogether = value; }

int Reservation::calculateDurationDays() const
{
  
    // assume format: YYYY-MM-DD
    // convert to integers and compute roughly:
    int y1 = stoi(startDate.substr(0, 4));
    int m1 = stoi(startDate.substr(5, 2));
    int d1 = stoi(startDate.substr(8, 2));

    int y2 = stoi(endDate.substr(0, 4));
    int m2 = stoi(endDate.substr(5, 2));
    int d2 = stoi(endDate.substr(8, 2));

    int days1 = y1 * 365 + m1 * 30 + d1;
    int days2 = y2 * 365 + m2 * 30 + d2;

    return days2 - days1;
}

bool Reservation::isDurationValid() const
{
    int d = calculateDurationDays();
    return (d >= 2 && d <= 28);
}

void Reservation::addAnimal(Animal* a)
{
    animals.push_back(a);
}


bool Reservation::removeAnimal(Animal* a)
{
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i] == a)
        {
            animals.erase(animals.begin() + i);
            return true;
        }
    }
    return false;
}


