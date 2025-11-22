#include "PetHotel.h"
#include "Animal.h"
#include "Reservation.h"
#include "Kennel.h"

// Constructor
PetHotel::PetHotel(std::string n, std::string a)
{
    name = n;
    address = a;
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
