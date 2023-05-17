#ifndef PET_H
#define PET_H

#include <string>
#include <fstream>

class Pet {
public:
    Pet(std::string name = "Pet", int hunger = 50, int sleepiness = 50, int boredom = 50, int happiness = 50);
    virtual ~Pet() {}

    void setName(const std::string& name);

    virtual void feed();
    virtual void sleep();
    void play();
    void nextHour();

    void displayStatus() const;
    int getObedience() const;
    void setObedience(int obedience);
    int getHealth() const;
    void setHealth(int health);

    virtual void save(std::ofstream& file) const;
    virtual void load(std::ifstream& file);

protected:
    std::string name;
    int hunger;
    int sleepiness;
    int boredom;
    int happiness;
    int obedience;
    int health;
};

#endif
