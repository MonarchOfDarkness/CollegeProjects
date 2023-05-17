#ifndef DRAGON_H
#define DRAGON_H

#include "Pet.h"

class Dragon : public Pet {
public:
    Dragon(std::string name = "Dragon", int hunger = 50, int sleepiness = 50, int boredom = 50, int happiness = 50);

    void breatheFire();
    void fly();
    void fight();
    void hoard();

    void feed() override;
    void sleep() override;
    void save(std::ofstream& file) const override;
    void load(std::ifstream& file) override;
};

#endif

