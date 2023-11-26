// game_functions.cpp

#include "game_functions.hpp"

char dll = static_cast <char>(200);
char dul = static_cast <char>(201);
char dur = static_cast <char>(187);
char dlr = static_cast <char>(188);
char dhl = static_cast <char>(186);
char dvl = static_cast <char>(205);

char sll = static_cast <char>(192);
char sul = static_cast <char>(218);
char sur = static_cast <char>(191);
char slr = static_cast <char>(217);
char shl = static_cast <char>(179);
char svl = static_cast <char>(196);

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
	Character playerCharacter;

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
			LoadGame(playerCharacter);
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

void SaveGame(const Character& playerCharacter, const string& fileName)
{
	ofstream saveFile(fileName);

	if (saveFile.is_open())
	{
		saveFile << playerCharacter.getName()			<< endl;
		saveFile << playerCharacter.getDescription()	<< endl;

		saveFile << playerCharacter.getLevel()			<< endl;
		saveFile << playerCharacter.getExperience()		<< endl;

		saveFile << playerCharacter.getMaxHealth()		<< endl;
		saveFile << playerCharacter.getCurrentHealth()	<< endl;

		saveFile << playerCharacter.getAttack()			<< endl;
		saveFile << playerCharacter.getBaseAttack()		<< endl;

		saveFile << playerCharacter.getDefense()		<< endl;
		saveFile << playerCharacter.getBaseDefense()	<< endl;

		saveFile << playerCharacter.getCoins()			<< endl;

		saveFile.close();
		cout << "Game saved successfully!\n";
	}
	else
	{
		// Error opening
		cerr << "Unable to open the save file!\n";
	}
	sleep(1);
}

void LoadGame(Character& playerCharacter)
{
	string fileName = "SaveGame.txt";
	ifstream loadFile(fileName);

	if (loadFile.is_open())
	{
		string name, description;
		int level, experience, maxHealth, currentHealth, attack, baseAttack, defense, baseDefense, coins;

		loadFile >> name >> ws;
		getline(loadFile, description);
		loadFile
			>> level >> experience 
			>> maxHealth >> currentHealth 
			>> attack >> baseAttack 
			>> defense >> baseDefense 
			>> coins;

		playerCharacter.setName(name);
		playerCharacter.setDescription(description);
		playerCharacter.setLevel(level);
		playerCharacter.setExperience(experience);
		playerCharacter.setMaxHealth(maxHealth);
		playerCharacter.setCurrentHealth(currentHealth);
		playerCharacter.setAttack(attack);
		playerCharacter.setBaseAttack(baseAttack);
		playerCharacter.setDefense(defense);
		playerCharacter.setBaseDefense(baseDefense);
		playerCharacter.setCoins(coins);

		cout << "Game loaded successfully!\n";
	}
	else
	{
		// Error opening
		cerr << "Unable to open the save file for loading!\n";
		return;
	}
	sleep(1);
	IdleMenu(playerCharacter);
}

void IdleMenu(Character playerCharacter)
{
	while (true)
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
			SaveGame(playerCharacter, "SaveGame.txt");
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
}

void InitializeOpponent(Character& opponent) 
{
	opponent.setName("Goblin");
	opponent.setDescription("A nasty opponent");
	opponent.setLevel(1);
	opponent.setExperience(0);
	opponent.setMaxHealth(10);
	opponent.setCurrentHealth(opponent.getMaxHealth());
	opponent.setAttack(1);
	opponent.setDefense(1);
	opponent.setCoins(5);
}
