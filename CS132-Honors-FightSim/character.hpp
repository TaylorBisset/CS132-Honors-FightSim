// character.hpp

/*

This header file defines the `Character` class, a subclass of the `Entity` class. 
It functions as the main class for all character entities in the game, 
 inheriting basic properties from the general entity class. 
It includes functions for managing character attributes
 such as health, attack, defense, level, experience, and coins. 
Additionally, it provides functions for hitting a target and displaying character details.
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "entity.hpp"

class Character : public Entity
{
public:
	Character();

	Character(const string& name, const string& description,
		int maxHealth, int currentHealth,
		int attack, int baseAttack,
		int defense, int baseDefense,
		int level, int experience, int coins);

	void setMaxHealth(int newMaxHealth);
	int getMaxHealth() const;

	void setCurrentHealth(int newCurrentHealth);
	int getCurrentHealth() const;
	void modifyCurrentHealth(int healthChange);

	void setAttack(int newAttack);
	int getAttack() const;
	void setBaseAttack(int newBaseAttack);
	int getBaseAttack() const;
	void setAttackBonus(int newAttackBonus);
	int getAttackBonus() const;

	void setDefense(int newDefense);
	int getDefense() const;
	void setBaseDefense(int newBaseDefense);
	int getBaseDefense() const;
	void setDefenseBonus(int newDefenseBonus);
	int getDefenseBonus() const;

	void setLevel(int newLevel);
	int getLevel() const;

	void setExperience(int newExperience);
	int getExperience() const;
	void modifyExperience(int experiencePoints);

	void setCoins(int newCoins);
	int getCoins() const;
	void modifyCoins(int coinChange);

	void displayDetails() const override;

	void hit(Character& target);

private:
	int maxHealth;
	int currentHealth;
	int attack;
	int baseAttack;
	int attackBonus;
	int defense;
	int baseDefense;
	int defenseBonus;
	int level;
	int experience;
	int coins;
};

#endif // CHARACTER_HPP
