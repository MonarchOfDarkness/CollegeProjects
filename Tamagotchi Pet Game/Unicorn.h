#ifndef UNICORN_H
#define UNICORN_H

#include "Pet.h"

class Unicorn : public Pet {
public:
    Unicorn(std::string name = "Unicorn", int hunger = 50, int sleepiness = 50, int boredom = 50, int happiness = 50);

    void heal();
    void useMagic();

    void save(std::ofstream& file) const override;
    void load(std::ifstream& file) override;
};

#endif
