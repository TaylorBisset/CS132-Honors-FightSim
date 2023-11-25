// armor.cpp

#include "armor.hpp"

// Constructor
Armor::Armor(const string& name, const string& description, const string& type, int value, int protection) :
    Item(name, description, type, value), protection(protection) {}

// Protection Setter
void Armor::setProtection(int newProtection)
{
    protection = newProtection;
}

// Protection Getter
int Armor::getProtection() const
{
    return protection;
}

// Display: | name and description | type and value | protection |
void Armor::displayDetails() const
{
    Item::displayDetails();
    cout << "\t\t\033[31;3mProtection: " << getProtection() << "\033[0m" << endl; // green italic
}
