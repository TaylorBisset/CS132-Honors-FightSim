// entity.cpp

/*
Implements the `Entity` class, a base class for all objects in the game. 
Handles common attributes like name and description, with a method to display entity details.
*/

#include "entity.hpp"

// Constructor
Entity::Entity(const string& name, const string& description) 
	:
    name(name), description(description) {}

// Name Setter
void Entity::setName(const string& newName)
{
	name = newName;
}

// Name Getter
string Entity::getName() const
{
	return name;
}

// Description Setter
void Entity::setDescription(const string& newDescription)
{
	description = newDescription;
}

// Description Getter
string Entity::getDescription() const
{
	return description;
}

// Display: | name and description |
void Entity::displayDetails() const
{
	cout << "\033[1m" << getName() << "\033[0m" << endl; // bold
	cout << getDescription() << endl;
}
