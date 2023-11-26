// game_functions.cpp

#include "game_functions.hpp"

char ll = 200;
char ul = 201;
char ur = 187;
char lr = 188;
char hl = 186;
char vl = 205;

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
		// main menu top line
		cout << "\t" << ul;
		for (int i = 0; i < 31; i++)
		{
			cout << vl;
		}
		cout << ur << endl;

		cout << "\t" << hl << "                               " << hl << "\n";
		cout << "\t" << hl << " \033[1mWelcome to the Armamentarium!\033[0m " << hl << "\n";
		cout << "\t" << hl << "                               " << hl << "\n";
		cout << "\t" << hl << "   \033[1;6mWhat would you like to do?\033[0m  " << hl << "\n";
		cout << "\t" << hl << "                               " << hl << "\n";
		cout << "\t" << hl << "   1  New Game                 " << hl << "\n";
		cout << "\t" << hl << "   2  Load Game                " << hl << "\n";
		cout << "\t" << hl << "   3  Leave Game               " << hl << "\n";
		cout << "\t" << hl << "                               " << hl << "\n";

		// main menu end line
		cout << "\t" << ll;
		for (int i = 0; i < 31; i++)
		{
			cout << vl;
		}
		cout << lr << endl << endl << "\t";

		int choice;
		string name;
		cin >> choice;

		switch (choice)
		{
		case 1:
			// NewGame();
			break;
		case 2:
			// LoadGame();
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
