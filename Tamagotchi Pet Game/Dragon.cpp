#include "Dragon.h"
#include <iostream>

Dragon::Dragon(std::string name, int hunger, int sleepiness, int boredom, int happiness)
    : Pet(name, hunger, sleepiness, boredom, happiness) {}

void Dragon::breatheFire() {
    std::cout << name << " breathes fire!" << std::endl;
}

void Dragon::fly() {
    std::cout << name << " flies into the sky!" << std::endl;
}

void Dragon::fight() {
    std::cout << name << " fights with another dragon!" << std::endl;
}

void Dragon::hoard() {
    std::cout << name << " hoards some treasure!" << std::endl;
}

void Dragon::feed() {
    hunger -= 20; // dragons eat more than other pets
    if (hunger < 0) hunger = 0;
}

void Dragon::sleep() {
    sleepiness -= 20; // dragons sleep more than other pets
    if (sleepiness < 0) sleepiness = 0;
}

void Dragon::save(std::ofstream& file) const {
    file << "Dragon" << std::endl;
    Pet::save(file);
}

void Dragon::load(std::ifstream& file) {
    Pet::load(file);
}
