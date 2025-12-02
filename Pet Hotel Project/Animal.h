#pragma once
#include <string>

class Animal
{
protected:
    int id;
    std::string name;
    std::string breed;
    std::string birthDate;
    std::string careSchedule;

public:
    // Constructor / Destructor
    Animal(int id = 0, std::string name = "", std::string breed = "", std::string birthDate = "", std::string careSchedule = "");
    
    virtual ~Animal();

    //Virtual Functions
    virtual std::string makeSound() const = 0;
    virtual std::string getCareInfo() const = 0;
    virtual std::string getType() const = 0;

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getBreed() const; 
    std::string getBirthDate() const;
    std::string getCareSchedule() const;

    // Setters
    void setId(int newId);
    void setName(const std::string newName);
    void setBreed(const std::string newBreed);
    void setBirthDate(const std::string newDate);
    void setCareSchedule(const std::string newSchedule);
};
