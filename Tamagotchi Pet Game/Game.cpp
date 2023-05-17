#include "Game.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <windows.h>
using namespace std;

Game::Game() : pet(nullptr) {}

Game::~Game() {}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Game game;
    game.run();
    return 0;
}

void Game::run() {
    bool exit = false;
    while (!exit) {
        mainMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                createPetMenu();
                break;
            case 2:
                loadPetMenu();
                break;
            case 3:
                if (pet) {
                    interactionMenu();
                } else {
                    std::cout << "You need to create or load a pet first!" << std::endl;
                }
                break;
            case 4:
                if (pet) {
                    savePetMenu();
                } else {
                    std::cout << "You need to create or load a pet first!" << std::endl;
                }
                break;
            case 5:
                exit = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

void Game::mainMenu() {
    cout << "   /\\_/\\  \n";
    cout << "  ( o.o ) \n";
    cout << "   > ^ <  \n";
    cout << "+---------+\n";
    cout << "| Main Menu |\n";
    cout << "+---------+\n";
    cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣶⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⠇
    )" << std::endl;
    cout << "+-----------------+\n";
    cout << "| 1. Create a new pet |\n";
    cout << "+-----------------+\n";
    cout << "| 2. Load an existing pet |\n";
    cout << "+-----------------+\n";
    cout << "| 3. Interact with your pet |\n";
    cout << "+-----------------+\n";
    cout << "| 4. Save your pet |\n";
    cout << "+-----------------+\n";
    cout << "| 5. Exit |\n";
    cout << "+-----------------+\n";
}

void Game::createPetMenu() {
    std::cout << "Create a New Pet" << std::endl;
    std::cout << "1. Dragon" << std::endl;
    std::cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣤⡼⠀⢀⡀⣀⢱⡄⡀⠀⠀⠀⢲⣤⣤⣤⣤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣿⣿⣿⡿⠛⠋⠁⣤⣿⣿⣿⣧⣷⠀⠀⠘⠉⠛⢻⣷⣿⣽⣿⣿⣷⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣴⣞⣽⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠠⣿⣿⡟⢻⣿⣿⣇⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣟⢦⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣿⡾⣿⣿⣿⣿⣿⠿⣻⣿⣿⡀⠀⠀⠀⢻⣿⣷⡀⠻⣧⣿⠆⠀⠀⠀⠀⣿⣿⣿⡻⣿⣿⣿⣿⣿⠿⣽⣦⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣼⠟⣩⣾⣿⣿⣿⢟⣵⣾⣿⣿⣿⣧⠀⠀⠀⠈⠿⣿⣿⣷⣈⠁⠀⠀⠀⠀⣰⣿⣿⣿⣿⣮⣟⢯⣿⣿⣷⣬⡻⣷⡄⠀⠀⠀
⠀⠀⢀⡜⣡⣾⣿⢿⣿⣿⣿⣿⣿⢟⣵⣿⣿⣿⣷⣄⠀⣰⣿⣿⣿⣿⣿⣷⣄⠀⢀⣼⣿⣿⣿⣷⡹⣿⣿⣿⣿⣿⣿⢿⣿⣮⡳⡄⠀⠀
⠀⢠⢟⣿⡿⠋⣠⣾⢿⣿⣿⠟⢃⣾⢟⣿⢿⣿⣿⣿⣾⡿⠟⠻⣿⣻⣿⣏⠻⣿⣾⣿⣿⣿⣿⡛⣿⡌⠻⣿⣿⡿⣿⣦⡙⢿⣿⡝⣆⠀
⠀⢯⣿⠏⣠⠞⠋⠀⣠⡿⠋⢀⣿⠁⢸⡏⣿⠿⣿⣿⠃⢠⣴⣾⣿⣿⣿⡟⠀⠘⢹⣿⠟⣿⣾⣷⠈⣿⡄⠘⢿⣦⠀⠈⠻⣆⠙⣿⣜⠆
⢀⣿⠃⡴⠃⢀⡠⠞⠋⠀⠀⠼⠋⠀⠸⡇⠻⠀⠈⠃⠀⣧⢋⣼⣿⣿⣿⣷⣆⠀⠈⠁⠀⠟⠁⡟⠀⠈⠻⠀⠀⠉⠳⢦⡀⠈⢣⠈⢿⡄
⣸⠇⢠⣷⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⠿⠿⠋⠀⢻⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢾⣆⠈⣷
⡟⠀⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣶⣤⡀⢸⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡄⢹
⡇⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠈⣿⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⢸
⢡⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠶⣶⡟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼
⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡁⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣼⣀⣠⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
)" << std::endl;
    std::cout << "2. Unicorn" << std::endl;
    std::cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣸⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⣨⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠉⢰⠿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡗⠃⢀⡿⢷⡄⠀⠀⣠⣶⣦⣄⠀⢀⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢴⡆⠀⠀⠈⣿⡤⠞⠀⢸⢿⣦⡴⠟⠛⠓⢻⣷⢿⣵⢹⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣽⣧⡀⠀⠀⢸⡆⢀⣴⡿⠋⠁⠀⠀⠀⣰⠟⡵⠋⢸⠈⣯⠛⢶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠙⠳⡾⠋⠁⠀⠀⣷⢋⡞⠁⢀⡴⠒⠋⣹⠟⡞⠁⠀⢸⠀⣿⠀⠀⠈⠻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡇⠀⠀⠀⣠⡿⢿⡇⢰⡏⢀⣠⣼⡟⣸⠁⠀⠀⢸⠀⣿⠙⢦⡀⠀⠈⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⣠⡾⠋⠀⠈⢷⡈⢧⣸⣧⡘⠓⠇⠀⠀⠀⡞⠀⣿⠀⠀⠹⣄⠀⠈⡿⠳⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠀⠀⠀⠙⠓⠛⠋⠁⠀⠀⠀⠀⠸⠃⢸⡟⣧⠀⠀⠘⣆⣼⠇⠀⡾⣷⣀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠀⣀⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠀⢘⡷⠶⠖⠛⠁⠀⣴⣷⠏⠉⠻⣦⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣴⠟⠁⠀⠀⠀⢀⣾⣿⠉⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣀⣀⣤⣶⣿⡞⠉⠙⣆⠀⠹⣦⠀⠀⠀⠀
⠀⠀⢀⣴⠟⠉⡇⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣤⣿⣽⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠈⠈⡇⠀⡇⠀⠀⠘⡇⠀⢻⡆⠀⠀⠀
⠀⣰⢟⣑⡀⠸⡇⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣻⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⢀⡇⢠⡇⠀⠀⠀⢷⠀⠘⣇⠀⢀⡀
⢰⡏⠀⠿⠏⠀⢻⡄⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡴⠃⢀⡞⣠⡟⢹⣄⠀⠀⢸⡀⠀⠻⠶⢾⡇
⢸⡇⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠷⠶⣾⠷⠚⢹⡄⠀⠙⢦⣀⠀⠹⠦⠤⢤⣾⠃
⠀⢿⣄⠀⠀⠀⠀⢹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡄⠀⠀⠹⢦⡀⠀⠈⠛⠲⠶⡞⠻⣧⠀
⠀⠈⠻⢧⣄⣀⠀⣸⣇⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣄⠀⠀⠀⠉⠓⢦⡀⠀⠀⣿⠀⢹⡇
⠀⠀⠀⠀⠈⠉⠉⠉⠁⠀⠈⠉⠙⠛⠶⢤⣤⣀⣀⣠⡤⠾⣻⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠳⣤⡀⠀⠀⠀⢹⡀⢀⡿⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡟⠀⠀⢙⣷⡄⠀⢸⢁⣾⡇⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡟⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⠴⠞⠋⠀⢀⣠⠞⢀⣽⣠⡾⢛⡿⠀⢀⡿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⠭⣿⣿⣭⣤⠴⠛⠙⠉⠀⡸⠁⢀⣾⠃⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡟⠀⢀⡿⠀⠀⠀⠀⢰⡇⠀⡾⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠀⢸⠀⠀⠀⠀⠀⠀⢳⣸⣇⣀⣀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠘⣆⠀⠀⠀⠀⠀⠀⠀⠉⣹⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⠀⠀⠙⢦⣀⡀⠀⠀⣀⣠⣾⡟⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠶⠤⣤⣄⣀⣀⣀⣀⣀⣀⣀⣀⣤⡼⠷⣤⣀⡀⠈⠉⢉⣉⣭⠾⠋⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠈⠉⠉⠛⠛⠋⠉⠁⠀⠀⠀⠀⠀
)" << std::endl;
    std::cout << "3. Mew" << std::endl;
    std::cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣶⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⠿⠋⢀⣀⣀⣀⣀⣤⣤⣶⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⢋⣉⣁⣉⣥⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣾⣿⣿⠿⠛⠉⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠻⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣴⡿⠟⠉⠀⠀⠀⠀⠀⠀⣽⣿⡿⠻⢿⣿⣿⣿⣿⣿⣿⣿⠀⢀⣤⠈⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⠀⠀⣀⠙⣿⣿⣿⣿⣿⣿⠀⠸⣿⣷⣿⣿⠟⠀⠀⠀⠀⠀⠀⣀⣀⣀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣀⡀⠀⠀
⠀⢠⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡀⢸⣿⣧⣿⣿⣿⣿⣿⣿⣦⣴⣿⣿⠟⠉⣀⣤⣤⣶⠶⠿⠛⠛⠛⠉⠉⠉⠁⠀⠀⠀⠀⠀⠉⠉⠛⠿⣷⡄
⢠⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⣠⣶⣤⣭⣭⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⡇
⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣉⠙⠿⣿⣿⣿⣿⡿⠟⢡⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠟⠀
⠘⢿⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⡾⠟⠋⠁⣀⣤⣤⣤⣤⣴⣶⣿⣿⣿⣿⣷⣦⡀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⠟⠁⠀⠀
⠀⠀⠉⠛⠿⠷⣶⣶⣶⣶⡶⠿⠟⠛⠉⠁⠀⠀⢠⣾⣿⡿⠟⠛⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⣠⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⢀⣤⣶⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⢹⣿⣿⣿⣿⣿⣿⣷⠘⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⡆⢻⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣟⢿⣿⣿⣿⣿⣿⣷⡄⠹⢿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠙⠿⣦⡙⢿⣿⣿⣿⣿⣿⣦⡄⠙⠛⢿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣶⣤⣄⠀⠈⠙⠛⠛⠛⠉⠀⠀⠀⠈⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡿⣿⣯⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠙⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣻⣿⣿⣹⡿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠻⠿⠃⠁⠀⠀⠀⠀⠀⠀⠀⠀
)" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            pet = std::make_unique<Dragon>();
            break;
        case 2:
            pet = std::make_unique<Unicorn>();
            break;
        case 3:
            pet = std::make_unique<Mew>();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            return;
    }

    std::cout << "Enter a name for your pet: ";
    std::string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    pet->setName(name);
}

void Game::loadPetMenu() {
    std::cout << "Enter the name of the file to load: ";
    std::string filename;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, filename);
    try {
    std::ifstream file(filename);
    if (!file) {
        throw std::ios_base::failure("Failed to open file.");
    }
    std::string type;
    if (!(file >> type)) {
        throw std::ios_base::failure("Failed to read pet type.");
    }

    if (type == "Dragon") {
        pet = std::make_unique<Dragon>();
    } else if (type == "Unicorn") {
        pet = std::make_unique<Unicorn>();
    } else if (type == "Mew") {
        pet = std::make_unique<Mew>();
    } else {
        throw std::ios_base::failure("Invalid pet type in file.");
    }

    pet->load(file);
    if (!file) {
        throw std::ios_base::failure("Failed to load pet data.");
    }
} catch (const std::ios_base::failure& e) {
    std::cout << e.what() << std::endl;
    return;
}

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    std::string type;
    file >> type;

    if (type == "Dragon") {
        pet = std::make_unique<Dragon>();
    } else if (type == "Unicorn") {
        pet = std::make_unique<Unicorn>();
    } else if (type == "Mew") {
        pet = std::make_unique<Mew>();
    } else {
        std::cout << "Invalid pet type in file." << std::endl;
        return;
    }

    pet->load(file);
}

void Game::interactionMenu() {
    bool exit = false;
    while (!exit) {
        pet->displayStatus();
        pet->nextHour();

        std::cout << "Interaction Menu" << std::endl;
        std::cout << "1. Feed" << std::endl;
        std::cout << "2. Sleep" << std::endl;
        std::cout << "3. Play" << std::endl;
        if (auto dragon = dynamic_cast<Dragon*>(pet.get())) {
            std::cout << "4. Breathe Fire" << std::endl;
            std::cout << "5. Fly" << std::endl;
        } else if (auto unicorn = dynamic_cast<Unicorn*>(pet.get())) {
            std::cout << "4. Heal" << std::endl;
            std::cout << "5. Use Magic" << std::endl;
        } else if (auto mew = dynamic_cast<Mew*>(pet.get())) {
            std::cout << "4. Use Psychic Powers" << std::endl;
            std::cout << "5. Learn Move" << std::endl;
        }
        std::cout << "6. Back to Main Menu" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                pet->feed();
                break;
            case 2:
                pet->sleep();
                break;
            case 3:
                pet->play();
                break;
            case 4:
                if (auto dragon = dynamic_cast<Dragon*>(pet.get())) {
                    dragon->breatheFire();
                } else if (auto unicorn = dynamic_cast<Unicorn*>(pet.get())) {
                    unicorn->heal();
                } else if (auto mew = dynamic_cast<Mew*>(pet.get())) {
                    mew->usePsychicPowers();
                }
                break;
            case 5:
                if (auto dragon = dynamic_cast<Dragon*>(pet.get())) {
                    dragon->fly();
                } else if (auto unicorn = dynamic_cast<Unicorn*>(pet.get())) {
                    unicorn->useMagic();
                } else if (auto mew = dynamic_cast<Mew*>(pet.get())) {
                    mew->learnMove();
                }
                break;
            case 6:
    exit = true;
    break;
default:
    std::cout << "Invalid choice. Please try again." << std::endl;
    break;
}
}
}

void Game::savePetMenu() {
std::cout << "Enter the name of the file to save to: ";
std::string filename;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::getline(std::cin, filename);
try {
    std::ofstream file(filename);
    if (!file) {
        throw std::ios_base::failure("Failed to open file.");
    }

    pet->save(file);
    if (!file) {
        throw std::ios_base::failure("Failed to save pet data.");
    }
} catch (const std::ios_base::failure& e) {
    std::cout << e.what() << std::endl;
    return;
}

std::ofstream file(filename);
if (!file.is_open()) {
    std::cout << "Failed to open file." << std::endl;
    return;
}

pet->save(file);
}
