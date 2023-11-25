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
	Item(const string& name, const string& description, const string& type, int value) :
		Entity(name, description), type(type), value(value) {}

	// Type
	void setType(const string& newType)
	{
		type = newType;
	}
	string getType() const
	{
		return type;
	}

	// Value
	void setValue(const int newValue)
	{
		value = newValue;
	}
	int getValue() const
	{
		return value;
	}

	// Display: name, description, type, and value
	virtual void displayDetails() const
	{
		Entity::displayDetails();
		cout << "\t" << getType() << endl;
		cout << "\t\t\033[33mValue: " << getValue() << " coins\033[0m" << endl; // yellow
	}

private:
	string type; // armor, weapon
	int	value;
};

#endif // !ITEM_HPP
