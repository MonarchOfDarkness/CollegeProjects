#ifndef GAME_H
#define GAME_H

#include "Pet.h"
#include "Dragon.h"
#include "Unicorn.h"
#include "Mew.h"
#include <memory>

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void mainMenu();
    void createPetMenu();
    void loadPetMenu();
    void interactionMenu();
    void savePetMenu();

    std::unique_ptr<Pet> pet;
};

#endif
