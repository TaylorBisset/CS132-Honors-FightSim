/*
weapon.hpp
Weapon subclass for all weapon items in the game.
This class is the main weapon class from which all damage items will inherit.
*/

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include "entity.hpp"
#include "item.hpp"

class Weapon : public Item
{
public:
	Weapon(const string& name, const string& description, const string& type, int value, int damage) :
		Item(name, description, type, value), damage(damage) {}

	// Damage
	void setDamage(int newDamage)
	{
		damage = newDamage;
	}
	int getDamage()	const
	{
		return damage;
	}

	// Display: name, description, type, value, and damage
	void displayDetails() const override
	{
		Item::displayDetails();
		cout << "\t\t\033[31;3mDamage: " << getDamage() << "\033[0m" << endl; // red italic
	}

private:
	int damage;
};

#endif // !WEAPON_HPP
