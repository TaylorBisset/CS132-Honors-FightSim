/*
character.hpp
Character subclass for all character entities in the game.
This class is the main character class from which all characters will inherit.
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
	void modifyAttack(int attackBonus);

	void setDefense(int newDefense);
	int getDefense() const;
	void setBaseDefense(int newBaseDefense);
	int getBaseDefense() const;
	void modifyDefense(int defenseBonus);

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
	int defense;
	int baseDefense;
	int level;
	int experience;
	int coins;
};

#endif // CHARACTER_HPP
