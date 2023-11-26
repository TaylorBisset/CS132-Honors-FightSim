// character.cpp

#include "character.hpp"

// Default Constructor
Character::Character()
	: 
	Entity("", ""),
	maxHealth(10),
	currentHealth(10),
	attack(1),
	baseAttack(1),
	defense(1),
	baseDefense(1),
	level(1),
	experience(0),
	coins(0) {}

// Constructor
Character::Character(const string& name, const string& description,
	int maxHealth, int currentHealth,
	int attack, int baseAttack,
	int defense, int baseDefense,
	int level, int experience, int coins) 
	: 
	Entity(name, description),
	maxHealth(maxHealth), currentHealth(currentHealth),
	attack(attack), baseAttack(baseAttack),
	defense(defense), baseDefense(baseDefense),
	level(level), experience(experience), coins(coins) {}

// Max Health Setter
void Character::setMaxHealth(int newMaxHealth)
{
	maxHealth = newMaxHealth;
}

// Max Health Getter
int Character::getMaxHealth() const
{
	return maxHealth;
}

// Current Health Setter
void Character::setCurrentHealth(int newCurrentHealth)
{
	currentHealth = newCurrentHealth;
	if (currentHealth >= maxHealth)
	{
		currentHealth = maxHealth;
	}
}

// Current Health Getter
int Character::getCurrentHealth() const
{
	return currentHealth;
}

// Current Health Modifier
void Character::modifyCurrentHealth(int healthChange)
{
	currentHealth += healthChange;
	setCurrentHealth(currentHealth);
}

// Attack Setter
void Character::setAttack(int newAttack)
{
	attack = newAttack;
}

// Attack Getter
int Character::getAttack() const
{
	return attack;
}

// Base Attack Setter
void Character::setBaseAttack(int newBaseAttack)
{
	baseAttack = newBaseAttack;
}

// Base Attack Getter
int Character::getBaseAttack() const
{
	return baseAttack;
}

// Base Attack Modifier
void Character::modifyAttack(int attackBonus)
{
	attack = baseAttack + attackBonus;
	setAttack(attack);
}

// Defense Setter
void Character::setDefense(int newDefense)
{
	defense = newDefense;
}

// Defense Getter
int Character::getDefense() const
{
	return defense;
}

// Base Defense Setter
void Character::setBaseDefense(int newBaseDefense)
{
	baseDefense = newBaseDefense;
}

// Base Defense Getter
int Character::getBaseDefense() const
{
	return baseDefense;
}

// Base Defense Modifier
void Character::modifyDefense(int defenseBonus)
{
	defense = baseDefense + defenseBonus;
	setDefense(defense);
}

// Level Setter
void Character::setLevel(int newLevel)
{
	level = newLevel;
}

// Level Getter
int Character::getLevel() const
{
	return level;
}

// Experience Setter
void Character::setExperience(int newExperience)
{
	experience = newExperience;
}

// Experience Getter
int Character::getExperience() const
{
	return experience;
}

// Experience Modifier
void Character::modifyExperience(int experiencePoints)
{
	experience += experiencePoints;
	if (experience >= (level * 10))
	{
		level++;
		setLevel(level);
		cout << "Congratulations!\nYou are now level " << level << endl;
		maxHealth = level * 10;
		setMaxHealth(maxHealth);
		setBaseAttack(level);
		setBaseDefense(level);
	}
	setExperience(experience);
}

// Coins Setter
void Character::setCoins(int newCoins)
{
	coins = newCoins;
}

// Coins Getter
int Character::getCoins() const
{
	return coins;
}

// Coins Modifier
void Character::modifyCoins(int coinChange)
{
	coins += coinChange;
	if (coinChange > 0)
	{
		cout << "\nYou received " << coinChange << " coins.\n";
	}
	cout << "Current coin count: " << coins << endl;
}

// Display Details
void Character::displayDetails() const
{
	cout << endl;
	// name and description
	Entity::displayDetails();
	// health
	cout << "\t\033[32;1mHealth: " << getMaxHealth() << "\033[22m / ";				// green bold
	cout << getCurrentHealth() << "\033[0m" << endl;								// green
	// level
	cout << "\tLevel: " << getLevel() << endl;
	// experience
	cout << "\tExp: " << getExperience() << endl;
	// attack
	cout << "\t\033[31mAttack: " << getAttack() << "\033[0m" << endl;				// red
	cout << "\t\033[31;2mBase Attack: " << getBaseAttack() << "\033[0m" << endl;	// red faint
	// defense
	cout << "\t\033[34mDefense: " << getDefense() << "\033[0m\n";					// blue
	cout << "\t\033[34;2mBase Defense: " << getBaseDefense() << "\033[0m" << endl;	// blue faint
	// coins
	cout << "\t\033[33mCoins: " << getCoins() << "\033[0m";							// yellow
	cout << endl;
}
