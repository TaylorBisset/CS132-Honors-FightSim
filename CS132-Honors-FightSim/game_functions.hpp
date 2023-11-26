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
void SaveGame(const Character& playerCharacter, const string& fileName);
void LoadGame(Character& playerCharacter);

void IdleMenu(Character playerCharacter);

void InitializeOpponent(Character& opponent);
void Fight(Character& player, Character& opponent);

#endif // GAME_FUNCTIONS_HPP
