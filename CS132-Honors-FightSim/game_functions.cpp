// game_functions.cpp

#include "game_functions.hpp"

char dll = 200;
char dul = 201;
char dur = 187;
char dlr = 188;
char dhl = 186;
char dvl = 205;

char sll = 192;
char sul = 218;
char sur = 191;
char slr = 217;
char shl = 179;
char svl = 196;

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

void GameMenu()
{
	while (true)
	{
		cout << endl;
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
		// main menu top line
		cout << "\t" << dul;
		for (int i = 0; i < 31; i++)
		{
			cout << dvl;
		}
		cout << dur << endl;

		cout << "\t" << dhl << "                               " << dhl << "\n";
		cout << "\t" << dhl << " \033[1mWelcome to the Armamentarium!\033[0m " << dhl << "\n";
		cout << "\t" << dhl << "                               " << dhl << "\n";
		cout << "\t" << dhl << "   \033[1;6mWhat would you like to do?\033[0m  " << dhl << "\n";
		cout << "\t" << dhl << "                               " << dhl << "\n";
		cout << "\t" << dhl << "   1  New Game                 " << dhl << "\n";
		cout << "\t" << dhl << "   2  Load Game                " << dhl << "\n";
		cout << "\t" << dhl << "   3  Leave Game               " << dhl << "\n";
		cout << "\t" << dhl << "                               " << dhl << "\n";

		// main menu end line
		cout << "\t" << dll;
		for (int i = 0; i < 31; i++)
		{
			cout << dvl;
		}
		cout << dlr << endl << endl << "\t";

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

		int choice;
		string name;
		cin >> choice;

		switch (choice)
		{
		case 1:
			NewGame();
			break;
		case 2:
			// Load Game
			break;
		case 3:
			QuitGame();
			break;
		default:
			cout << "\nInvalid choice.\nPlease select a valid option.\n\n";
			break;
		}
	}
}

void NewGame()
{
	cout << "\n\tWhat is your name, warrior?\n\t";
	string playerName;
	cin >> playerName;

	Character playerCharacter(playerName, "A novice warrior.", 10, 10, 1, 1, 1, 1, 1, 0, 0);

	cout << "\n\tWelcome, " << playerCharacter.getName() << "!\n";
	sleep(1);
	cout << "\tI hope you find your experience here to be";
	sleep(1); cout << "."; sleep(1); cout << "."; sleep(1);
	cout << "."; sleep(1); cout << " entertaining.\n";
	sleep(1);
	cout << "\tHere's 10 coins to gear up with.\n";
	sleep(1);
	playerCharacter.modifyCoins(10);
	sleep(2);
	IdleMenu(playerCharacter);
}

void IdleMenu(Character playerCharacter)
{
	cout << "\n\tWelcome back, " << playerCharacter.getName() << endl << endl;
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// idle menu top line
	cout << "\t" << sul;
	for (int i = 0; i < 28; i++)
	{
		cout << svl;
	}
	cout << sur << endl;

	cout << "\t" << shl << "                            " << shl << "\n";
	cout << "\t" << shl << "         \033[1mEntering the\033[0m       " << shl << "\n";
	cout << "\t" << shl << "        \033[1mArmamentarium!\033[0m      " << shl << "\n";
	cout << "\t" << shl << "                            " << shl << "\n";
	cout << "\t" << shl << "       \033[1;6mMake your choice\033[0m     " << shl << "\n";
	cout << "\t" << shl << "                            " << shl << "\n";
	cout << "\t" << shl << "   1  Fight opponent        " << shl << "\n";
	cout << "\t" << shl << "   2  View stats            " << shl << "\n";
	cout << "\t" << shl << "   3  Equip gear            " << shl << "\n";
	cout << "\t" << shl << "   4  Buy gear              " << shl << "\n";
	cout << "\t" << shl << "   5  Save game             " << shl << "\n";
	cout << "\t" << shl << "   6  Exit the game         " << shl << "\n";
	cout << "\t" << shl << "                            " << shl << "\n";

	// idle menu end line
	cout << "\t" << sll;
	for (int i = 0; i < 28; i++)
	{
		cout << svl;
	}
	cout << slr << endl << endl << "\t";

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		// Implement the fight logic
		break;
	case 2:
		playerCharacter.displayDetails();
		break;
	case 3:
		// Implement the equip gear logic
		break;
	case 4:
		// Implement the buy gear logic
		break;
	case 5:
		// SaveGame()
		sleep(1);
		break;
	case 6:
		cout << "\nExiting the game.\n";
		QuitGame();
		return;
	default:
		cout << "\nInvalid choice.\nPlease select a valid option.\n\n";
		break;
	}
}
