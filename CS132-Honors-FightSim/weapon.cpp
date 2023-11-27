// weapon.cpp

/*
Implements the `Weapon` class, which is a subclass of the `Item` class. 
Defines methods to set and get weapon damage and displays weapon details.
*/

#include "weapon.hpp"

// Constructor
Weapon::Weapon(const string& name, const string& description, const string& type, int value, int damage) 
    : 
    Item(name, description, type, value), damage(damage) {}

// Damage Setter
void Weapon::setDamage(int newDamage) 
{
    damage = newDamage;
}

// Damage Getter
int Weapon::getDamage() const 
{
    return damage;
}

// Display: | name and description | type and value | damage |
void Weapon::displayDetails() const 
{
    Item::displayDetails();
    cout << "\t\t\033[31;3mDamage: " << getDamage() << "\033[0m" << endl; // red italic
}
