#pragma once
#include <string>
#include <vector>

class Animal;

class Kennel
{
private:
    int id;
    std::string size;      // "large", "medium", "small", "rodent"
    std::string type;      // "dog", "cat", "rodent"
    int capacity;
    std::vector<Animal*> animals;

public:
    // Constructor / Destructor
    Kennel(int id = 0, std::string size = "", std::string type = "", int capacity = 1);
    ~Kennel();

    // Getters
    int getId() const;
    std::string getSize() const;
    std::string getType() const;
    int getCapacity() const;
    std::vector<Animal*> getAnimals() const;

    // Setters
    void setId(int newId);
    void setSize(std::string newSize);
    void setType(std::string newType);
    void setCapacity(int newCapacity);
    void setAnimals(std::vector<Animal*> newAnimals);

    // Logic
    int getCurrentCount() const;
    bool isFull() const;
    bool isEmpty() const;
    bool canAccept(Animal* a) const;
    bool addAnimal(Animal* a);
    bool removeAnimal(Animal* a);
};
