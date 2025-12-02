#pragma once
#include <string>
#include <vector>

class Animal;
class Kennel;

class Reservation
{
private:
    int id;
    std::string startDate;     // format: YYYY-MM-DD (simple string)
    std::string endDate;
    std::vector<Animal*> animals;
	bool putTogether;        // whether animals can be grouped in same kennel

public:
    // Constructor / Destructor
    Reservation(int id = 0, std::string start = "", std::string end = "", std::vector<Animal*> pets = {}, bool putTogether = false);
    ~Reservation();

    // Getters
    int getId() const;
    std::string getStartDate() const;
    std::string getEndDate() const;
    std::vector<Animal*> getAnimals() const;
	bool getPutTogether() const;

    // Setters
    void setId(int newId);
    void setStartDate(std::string newStart);
    void setEndDate(std::string newEnd);
    void setAnimals(std::vector<Animal*> newAnimals);
	void setPutTogether(bool value);

    // Logic
    int calculateDurationDays() const;     // returns reservation length
    bool isDurationValid() const;          // between 2 and 28 days
    void addAnimal(Animal* a);

    bool removeAnimal(Animal* a);

};
