// item.hpp

/*
This header file defines the `Item` class, a subclass of the `Entity` class. 
It serves as the main class for all item entities in the game, 
 inheriting basic properties from the general entity class. 
It includes functions for setting and getting item type, value, and displaying item details.
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
