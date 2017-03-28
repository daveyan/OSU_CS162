/*********************************************************************
** Program Filename: Creature.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Creature class implementation file. This is an abstract
** class
*********************************************************************/
#include "Creature.hpp"
#include <string>


Creature::Creature()
{

}

string Creature::getName()
{
	return name;
}

int Creature::getArmor()
{
	return armor;
}

int Creature::getStrength()
{
	return strength;
}

bool Creature::getIsAlive()
{
	return isAlive;
}

void Creature::setArmor(int newArmor)
{
	armor = newArmor;
}

void Creature::setStrength(int newStrength)
{
	strength = newStrength;
}

void Creature::setIsAlive(bool status)
{
	isAlive = status;
}

int Creature::creatureAttack()
{
	return 0;
}

int Creature::creatureDefend(int attackDamage)
{
	return 0;
}

