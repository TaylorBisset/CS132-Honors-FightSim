// weapon.hpp

/*
This file contains the definition of the `Weapon` class, a subclass of the `Item` class. 
It functions as the main class for all weapon items in the game, 
 inheriting characteristics from the general item class. 
It includes functions for setting and getting damage values and displaying item details.
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
	Weapon(const string& name, const string& description, const string& type, int value, int damage);

	void setDamage(int newDamage);
	int getDamage()	const;

	void displayDetails() const override;

private:
	int damage;
};

#endif // !WEAPON_HPP
