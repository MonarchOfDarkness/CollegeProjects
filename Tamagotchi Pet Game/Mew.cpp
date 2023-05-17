#include "Mew.h"
#include <iostream>

Mew::Mew(std::string name, int hunger, int sleepiness, int boredom, int happiness)
    : Pet(name, hunger, sleepiness, boredom, happiness) {}

void Mew::usePsychicPowers() {
    std::cout << name << " uses its psychic powers!" << std::endl;
}

void Mew::learnMove() {
    std::cout << name << " learns a new move!" << std::endl;
}

void Mew::save(std::ofstream& file) const {
    file << "Mew" << std::endl;
    Pet::save(file);
}

void Mew::load(std::ifstream& file) {
    Pet::load(file);
}
