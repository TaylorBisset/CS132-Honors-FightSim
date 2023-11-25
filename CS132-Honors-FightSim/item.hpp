/*
item.hpp
Item subclass for all item entities in the game.
This class is the main item class from which all items will inherit.
*/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include "entity.hpp"

class Item : public Entity
{
public:
	Item(const string& name, const string& description, const string& type, int value);

	void setType(const string& newType);
	string getType() const;

	void setValue(const int newValue);
	int getValue() const;

	virtual void displayDetails() const;

private:
	string type; // armor, weapon
	int	value;
};

#endif // !ITEM_HPP
