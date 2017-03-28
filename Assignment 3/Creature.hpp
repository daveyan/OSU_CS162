/*********************************************************************
** Program Filename: Creature.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Creature class header file.
*********************************************************************/
#pragma once
#include "Die.hpp"
#include <string>
class Creature
{
protected:
	string name;
	Die attackDie;
	Die defenseDie;
	int armor;
	int strength;
	bool isAlive;
public:
	Creature();
	string getName();
	int getArmor();
	int getStrength();
	bool getIsAlive();
	void setArmor(int newArmor);
	void setStrength(int newStrength);
	void setIsAlive(bool status);
	//Virtual functions
	virtual int creatureAttack() = 0;
	virtual int creatureDefend(int attackDamage) = 0;

};

