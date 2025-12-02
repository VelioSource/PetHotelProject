#include "PetHotel.h"
#include "Animal.h"
#include "Reservation.h"
#include "Kennel.h"

// Constructor
PetHotel::PetHotel(std::string n, std::string a)
{
    name = n;
    address = a;

    int idCounter = 1;

    // ----------- 10 LARGE DOG KENNELS (>25kg) -----------
    for (int i = 0; i < 10; i++)
    {
        Kennel* k = new Kennel(idCounter, "large","dog", 1 );
        kennels.push_back(k);
        idCounter++;
    }

    // ----------- 20 MEDIUM DOG KENNELS (10–25kg) -----------
    for (int i = 0; i < 20; i++)
    {
        Kennel* k = new Kennel(idCounter, "medium", "dog",2 );
        kennels.push_back(k);
        idCounter++;
    }

    // ----------- 50 SMALL KENNELS (<10kg dogs AND cats) -----------
    for (int i = 0; i < 50; i++)
    {
        // small dog kennel, but cats also allowed in small (handled in canAccept)
        Kennel* k = new Kennel(idCounter, "small","dog", 2 );
        kennels.push_back(k);
        idCounter++;
    }

    // ----------- 30 RODENT KENNELS (capacity 4) -----------
    for (int i = 0; i < 30; i++)
    {
        Kennel* k = new Kennel(idCounter, "rodent", "rodent", 4);
        kennels.push_back(k);
        idCounter++;
    }



}

// Destructor
PetHotel::~PetHotel()
{

}

// ----------------- Getters -----------------

std::string PetHotel::getName() const
{
    return name;
}

std::string PetHotel::getAddress() const
{
    return address;
}

std::vector<Animal*> PetHotel::getAnimals() const
{
    return animals;
}

std::vector<Reservation*> PetHotel::getReservations() const
{
    return reservations;
}

std::vector<Kennel*> PetHotel::getKennels() const
{
    return kennels;
}

// ----------------- Setters -----------------

void PetHotel::setName(const std::string& petName)
{
    name = petName;
}

void PetHotel::setAddress(const std::string& petAddress)
{
    address = petAddress;
}

void PetHotel::setAnimals(const std::vector<Animal*>& newAnimals)
{
    animals = newAnimals;
}

void PetHotel::setReservations(const std::vector<Reservation*>& newReservations)
{
    reservations = newReservations;
}

void PetHotel::setKennels(const std::vector<Kennel*>& newKennels)
{
    kennels = newKennels;
}

// ------------- Controller Actions -------------

void PetHotel::addReservation(Reservation* r)
{
    reservations.push_back(r);
}

Reservation* PetHotel::findReservationById(int id)
{
    for (int i = 0; i < reservations.size(); i++)
    {
        if (reservations[i]->getId() == id)
            return reservations[i];
    }
    return NULL;
}

bool PetHotel::removeReservation(Reservation* r)
{
    for (int i = 0; i < reservations.size(); i++)
    {
        if (reservations[i] == r)
        {
            reservations.erase(reservations.begin() + i);
            return true;
        }
    }
    return false;
}

std::vector<Kennel*> PetHotel::findAvailableKennelsFor(Animal* a)
{
    std::vector<Kennel*> result;

    for (int i = 0; i < kennels.size(); i++)
    {
        Kennel* k = kennels[i];
        if (!k->isFull() && k->canAccept(a))
        {
            result.push_back(k);
        }
    }

    return result;
}

void PetHotel::addAnimal(Animal* a)
{
	animals.push_back(a);
}