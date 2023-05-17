#ifndef MEW_H
#define MEW_H

#include "Pet.h"

class Mew : public Pet {
public:
    Mew(std::string name = "Mew", int hunger = 50, int sleepiness = 50, int boredom = 50, int happiness = 50);

    void usePsychicPowers();
    void learnMove();

    void save(std::ofstream& file) const override;
    void load(std::ifstream& file) override;
};

#endif
