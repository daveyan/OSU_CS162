/*********************************************************************
** Program Filename: HarryPotter.hpp
** Author: David Yan
** Date: 2/14/16
** Description: Harry Potter class header.
*********************************************************************/
#pragma once
#include "Creature.hpp"
class HarryPotter :
	public Creature
{
private:
	bool revived;
public:
	HarryPotter();
	virtual int creatureAttack();
	virtual int creatureDefend(int attackDamage);
};

