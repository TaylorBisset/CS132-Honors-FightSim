// game_functions.cpp

#include <iostream>
#include <fstream>
#include <thread>

#include "game_functions.hpp"

void sleep(int seconds)
{
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void QuitGame()
{
	cout << "\nThank you for playing!\nCome back soon!\n\n";
	// OS independent program termination sequence. 
#ifdef _WIN32
	cout << endl;
	system("pause");
#else
	cout << endl;
	cout << "Press any key to continue . . . ";
	cin.get();
#endif
	exit(0);
}
