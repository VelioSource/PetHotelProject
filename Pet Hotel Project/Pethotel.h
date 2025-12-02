#pragma once
#include <string>
#include <vector>

class Animal;
class Reservation;
class Kennel;

class PetHotel
{
private:
    std::string name;
    std::string address;
    std::vector<Animal*> animals;
    std::vector<Reservation*> reservations;
    std::vector<Kennel*> kennels;

public:
    // Constructor & Destructor
    PetHotel(std::string n = "Unknown", std::string a = "Unknown");
    ~PetHotel();

    // Getters
    std::string getName() const;
    std::string getAddress() const;
    std::vector<Animal*> getAnimals() const;
    std::vector<Reservation*> getReservations() const;
    std::vector<Kennel*> getKennels() const;

    // Setters
    void setName(const std::string& petName);
    void setAddress(const std::string& petAddress);
    void setAnimals(const std::vector<Animal*>& newAnimals);
    void setReservations(const std::vector<Reservation*>& newReservations);
    void setKennels(const std::vector<Kennel*>& newKennels);

    // Controller
    void addReservation(Reservation* r);
    Reservation* findReservationById(int id);
    bool removeReservation(Reservation* r);
    std::vector<Kennel*> findAvailableKennelsFor(Animal* a);
    void addAnimal(Animal* a);

};
