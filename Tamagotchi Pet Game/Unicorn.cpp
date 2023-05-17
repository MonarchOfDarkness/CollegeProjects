#include "Unicorn.h"
#include <iostream>

Unicorn::Unicorn(std::string name, int hunger, int sleepiness, int boredom, int happiness)
    : Pet(name, hunger, sleepiness, boredom, happiness) {}

void Unicorn::heal() {
    std::cout << name << " heals itself and others!" << std::endl;
}

void Unicorn::useMagic() {
    std::cout << name << " uses its magical powers!" << std::endl;
}

void Unicorn::save(std::ofstream& file) const {
    file << "Unicorn" << std::endl;
    Pet::save(file);
}

void Unicorn::load(std::ifstream& file) {
    Pet::load(file);
}
