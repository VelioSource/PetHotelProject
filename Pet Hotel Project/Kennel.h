#pragma once
#include <string>
#include <vector>

class Animal;  // forward declaration

class Kennel
{
private:
    int id;
    std::string size;     // "small", "medium", "large", "rodent"
    int capacity;
    std::string type;     // "dog", "cat", "rodent"
    std::vector<Animal*> animals;

public:
    // Constructor / Destructor
    Kennel(int id = 0, std::string size = "", int capacity = 1, std::string type = "");
    ~Kennel();

    // Getters
    int getId() const;
    std::string getSize() const;
    int getCapacity() const;
    std::string getType() const;
    std::vector<Animal*> getAnimals() const;

    // Setters
    void setId(int newId);
    void setSize(const std::string newSize);
    void setCapacity(int newCap);
    void setType(const std::string newType);
    void setAnimals(const std::vector<Animal*> newAnimals);

    // Controller helper
    void addAnimal(Animal* a);
};
