// entity.hpp

/*
This file contains the definition of the base class `Entity`. 
It serves as the foundational class for all objects in the game, 
 providing basic attributes like name and description. 
It includes functions for setting and getting the name and description of an entity 
 and provides a virtual function for displaying entity details.
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
