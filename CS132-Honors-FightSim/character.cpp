// character.cpp

/*
Implements the Character class, a subclass of the Entity class. 
Manages character-specific attributes like health, attack, defense, level, experience, and coins. 
Includes methods for displaying details and handling character actions.
*/

#include "character.hpp"
#include "game_functions.hpp"

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
	coins(0),
	attackBonus(0), 
	defenseBonus(0) {}

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
	level(level), experience(experience), coins(coins), 
	attackBonus(0), defenseBonus(0) {}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
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
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
// Attack Setter
void Character::setAttack(int newAttack)
{
	attack = newAttack; // baseAttack + attackBonus (given by weapons)
}

// Attack Getter
int Character::getAttack() const
{
	return attack;
}

// Base Attack Setter
void Character::setBaseAttack(int newBaseAttack)
{
	baseAttack = newBaseAttack; // equal to level
}

// Base Attack Getter
int Character::getBaseAttack() const
{
	return baseAttack;
}

// Attack Bonus Setter
void Character::setAttackBonus(int newAttackBonus)
{
	attackBonus = newAttackBonus;
}

// Attack Bonus Getter
int Character::getAttackBonus() const
{
	return attackBonus;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
// Defense Setter
void Character::setDefense(int newDefense)
{
	defense = newDefense; // baseDefense + defenseBonus (given by armor)
}

// Defense Getter
int Character::getDefense() const
{
	return defense;
}

// Base Defense Setter
void Character::setBaseDefense(int newBaseDefense)
{
	baseDefense = newBaseDefense; // equal to level
}

// Base Defense Getter
int Character::getBaseDefense() const
{
	return baseDefense;
}

// Defense Bonus Setter
void Character::setDefenseBonus(int newDefenseBonus)
{
	defenseBonus = newDefenseBonus;
}

// Defense Bonus Getter
int Character::getDefenseBonus() const
{
	return defenseBonus;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
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
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
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
	int requiredExp = level * 10;

	if (experience >= requiredExp)
	{
		level++;
		setLevel(level);
		cout << "\n\t\aCongratulations!\n\t\tYou are now\033[1m level " << level << "\033[0m\n";
		setMaxHealth(level * 10);
		setBaseAttack(level);
		setAttack(getBaseAttack() + getAttackBonus());
		setBaseDefense(level);
		setDefense(getBaseDefense() + getDefenseBonus());
	}
	setExperience(experience);
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
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
		cout << "\n\tYou received \033[33m" << coinChange << " coins.\033[0m\n";	// yellow
	}
	cout << "\tCurrent amount: \033[33;1m" << coins << " coins.\033[0m\n";			// yellow bold
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
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
	cout << "\t\033[33;1mCoins: " << getCoins() << "\033[0m";						// yellow bold
	cout << endl;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void Character::hit(Character& target)
{
	int minDamage = getLevel();
	int damage = max(minDamage, getAttack() - target.getDefense()); 
	// subtracts health according to difference
	target.modifyCurrentHealth(-damage);
	// announces damage dealt from one to another
	cout << getName() << " hits " << target.getName() << " for \033[1m" << damage << " damage!\033[0m\n";
}
