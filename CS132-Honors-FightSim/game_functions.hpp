// game_functions.hpp

/*
This header file includes various functions related to game mechanics. 
It provides functions for managing game flow, 
 such as sleeping for a specified duration, quitting the game, 
 displaying the game menu, starting a new game, saving and loading game data, 
 handling the idle menu, initializing opponents, and managing character fights.
*/

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
