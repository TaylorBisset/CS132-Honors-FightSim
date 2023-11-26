// game_functions.hpp

#ifndef GAME_FUNCTIONS_HPP
#define GAME_FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <thread>

#include "character.hpp"

using namespace std;

void sleep(int seconds);
void QuitGame();
void GameMenu();

void NewGame();

void IdleMenu(Character playerCharacter);

#endif // GAME_FUNCTIONS_HPP
