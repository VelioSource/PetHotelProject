#include "Kennel.h"
#include "Dog.h"
#include "Cat.h"
#include "Rodent.h"

Kennel::Kennel(int id, std::string size, std::string type, int capacity)
{
    this->id = id;
    this->size = size;
    this->type = type;
    this->capacity = capacity;
}

Kennel::~Kennel()
{
}

int Kennel::getId() const { return id; }
std::string Kennel::getSize() const { return size; }
std::string Kennel::getType() const { return type; }
int Kennel::getCapacity() const { return capacity; }
std::vector<Animal*> Kennel::getAnimals() const { return animals; }

void Kennel::setId(int newId) { id = newId; }
void Kennel::setSize(std::string newSize) { size = newSize; }
void Kennel::setType(std::string newType) { type = newType; }
void Kennel::setCapacity(int newCapacity) { capacity = newCapacity; }
void Kennel::setAnimals(std::vector<Animal*> newAnimals) { animals = newAnimals; }

int Kennel::getCurrentCount() const
{
    return animals.size();
}

bool Kennel::isFull() const
{
    return getCurrentCount() >= capacity;
}

bool Kennel::isEmpty() const
{
    return animals.empty();
}

bool Kennel::canAccept(Animal* a) const
{
    if (a == NULL) return false;

    // Rodent logic
    Rodent* r = dynamic_cast<Rodent*>(a);
    if (type == "rodent")
    {
        if (r == NULL) return false;       // only rodents allowed
        if (isFull()) return false;        // max 4

        if (!animals.empty())
        {
            Rodent* existing = dynamic_cast<Rodent*>(animals[0]);
            if (existing == NULL) return false;
            // must match rodent type
            if (existing->getType() != r->getType())
                return false;
        }
        return true;
    }

    // Dog logic
    Dog* d = dynamic_cast<Dog*>(a);
    if (type == "dog")
    {
        if (d == NULL) return false;

        int w = d->getWeight();

        if (size == "large" && w > 25) return !isFull();
        if (size == "medium" && w >= 10 && w <= 25) return !isFull();
        if (size == "small" && w < 10) return !isFull();

        return false;
    }

    // Cat logic
    Cat* c = dynamic_cast<Cat*>(a);
    if (c != NULL)
    {
        // cats can go into any small kennel
        if (size == "small") return !isFull();
    }


    return false;
}

bool Kennel::addAnimal(Animal* a)
{
    if (canAccept(a))
    {
        animals.push_back(a);
        return true;
    }
    return false;
}

bool Kennel::removeAnimal(Animal* a)
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
