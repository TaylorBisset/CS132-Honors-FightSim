/*
armor.hpp
Armor subclass for all armor items in the game.
This class is the main armor class from which all protection items will inherit.
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
