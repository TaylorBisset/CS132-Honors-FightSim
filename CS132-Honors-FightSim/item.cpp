// item.cpp

/*
Implements the `Item` class, a subclass of the `Entity` class. 
Manages item properties such as name, description, type, and value. 
Provides a method to display item details.
*/

#include "item.hpp"

// Constructor
Item::Item(const string& name, const string& description, const string& type, int value) 
	:
	Entity(name, description), type(type), value(value) {} 

// Type Setter
void Item::setType(const string& newType)
{
	type = newType;
}

// Type Getter
string Item::getType() const
{
	return type;
}

// Value Setter
void Item::setValue(const int newValue)
{
	value = newValue;
}

// Value Getter
int Item::getValue() const
{
	return value;
}

// Display: | name and description | type and value |
void Item::displayDetails() const
{
	Entity::displayDetails();
	cout << "\t" << getType() << endl;
	cout << "\t\t\033[33mValue: " << getValue() << " coins\033[0m" << endl;
}
