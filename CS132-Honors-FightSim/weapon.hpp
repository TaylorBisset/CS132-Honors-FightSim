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
	Weapon(const string& name, const string& description, const string& type, int value, int damage);
	void setDamage(int newDamage);
	int getDamage()	const;
	void displayDetails() const override;

private:
	int damage;
};

#endif // !WEAPON_HPP
