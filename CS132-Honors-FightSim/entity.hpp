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
	Entity(const string& name, const string& description);

	void setName(const string& newName);
	string getName() const;

	void setDescription(const string& newDescription);
	string getDescription() const;

	virtual void displayDetails() const;

private:
	string name;
	string description;
};

#endif // !ENTITY_HPP
