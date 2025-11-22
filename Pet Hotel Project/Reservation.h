#pragma once
#include <string>
#include <vector>

class Animal;   // forward declaration

class Reservation
{
private:
    int id;
    std::string startDate;
    std::string endDate;
    std::vector<Animal*> animals;

public:
    // Constructor / Destructor
    Reservation(int id = 0, std::string start = "", std::string end = "");
    ~Reservation();

    // Getters
    int getId() const;
    std::string getStartDate() const;
    std::string getEndDate() const;
    std::vector<Animal*> getAnimals() const;

    // Setters
    void setId(int newId);
    void setStartDate(const std::string newStart);
    void setEndDate(const std::string newEnd);
    void setAnimals(const std::vector<Animal*> newAnimals);

    // Controller helper
    void addAnimal(Animal* a);
};
