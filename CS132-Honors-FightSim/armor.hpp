// armor.hpp
 
/*
This file defines the `Armor` class, a subclass of the `Item` class. 
It serves as the main class for all armor items in the game, 
 inheriting properties from the general item class. 
It includes functions for setting and getting protection values and displaying item details.
*/

#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <iostream>
#include <string>
#include "entity.hpp"
#include "item.hpp"

class Armor : public Item
{
public:
	Armor(const string& name, const string& description, const string& type, int value, int protection);

	void setProtection(int newProtection);
	int getProtection()	const;

	void displayDetails() const override;

private:
	int protection;
};

#endif // !ARMOR_HPP
