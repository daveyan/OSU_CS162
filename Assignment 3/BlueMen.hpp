/*********************************************************************
** Program Filename: BlueMen.hpp
** Author: David Yan
** Date: 2/14/16
** Description: BlueMen class header.
*********************************************************************/
#pragma once
#include "Creature.hpp"
class BlueMen :
	public Creature
{
public:
	BlueMen();
	virtual int creatureAttack();
	virtual int creatureDefend(int attackDamage);

};

