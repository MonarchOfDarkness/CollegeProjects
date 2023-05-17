#include "Pet.h"
#include <iostream>

Pet::Pet(std::string name, int hunger, int sleepiness, int boredom, int happiness)
    : name(name), hunger(hunger), sleepiness(sleepiness), boredom(boredom), happiness(happiness) {}

void Pet::setName(const std::string& name) {
    this->name = name;
}

void Pet::feed() {
    hunger -= 10;
    if (hunger < 0) hunger = 0;
}

void Pet::sleep() {
    sleepiness -= 10;
    if (sleepiness < 0) sleepiness = 0;
}

void Pet::play() {
    boredom -= 10;
    if (boredom < 0) boredom = 0;
}

int Pet::getObedience() const {
    return obedience;
}

void Pet::setObedience(int obedience) {
    this->obedience = obedience;
}

int Pet::getHealth() const {
    return health;
}

void Pet::setHealth(int health) {
    this->health = health;
}

void Pet::nextHour() {
    hunger += 5;
    if (hunger > 100) hunger = 100;

    sleepiness += 5;
    if (sleepiness > 100) sleepiness = 100;

    boredom += 5;
    if (boredom > 100) boredom = 100;

    if (hunger > 40) std::cout << name << " is hungry!" << std::endl;
    if (sleepiness > 40) std::cout << name << " is sleepy!" << std::endl;
    if (boredom > 40) std::cout << name << " is bored!" << std::endl;
}

void Pet::displayStatus() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hunger: " << hunger << "/100" << std::endl;
    std::cout << "Sleepiness: " << sleepiness << "/100" << std::endl;
    std::cout << "Boredom: " << boredom << "/100" << std::endl;
}

void Pet::save(std::ofstream& file) const {
    file << name << std::endl;
    file << hunger << std::endl;
    file << sleepiness << std::endl;
    file << boredom << std::endl;
    file << obedience << std::endl;
    file << health << std::endl;
}

void Pet::load(std::ifstream& file) {
    file >> name;
    file >> hunger;
    file >> sleepiness;
    file >> boredom;
    file >> obedience;
    file >> health;
}
    