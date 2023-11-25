/*
entity.hpp
Base class for all objects in the game.
This class is the base entity from which all objects will inherit.
*/

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <string>

using namespace std;

class Entity
{
public: 
	Entity(const string& name, const string& description) : 
		name(name), description(description) {}

	// Name
	void setName(const string& newName)
	{
		name = newName;
	}
	string getName() const
	{
		return name;
	}

	// Description
	void setDescription(const string& newDescription)
	{
		description = newDescription;
	}
	string getDescription() const
	{
		return description;
	}

	// Display: name and description
	virtual void displayDetails() const
	{
		cout << "\033[1m" << getName() << "\033[0m" << endl;
		cout << getDescription() << endl;
	}

private:
	string name;
	string description;
};

#endif // !ENTITY_HPP
