// game_functions.cpp

#include <iostream>
#include <fstream>
#include <thread>

#include "game_functions.hpp"

void sleep(int seconds)
{
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}
