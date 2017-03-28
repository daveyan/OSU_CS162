/*********************************************************************
** Program Filename: Barbarian.hpp
** Author: David Yan
** Date: 2/14/16
** Description: Barbarian class header.
*********************************************************************/

#pragma once
#include "Creature.hpp"
class Barbarian : virtual public Creature
{
public:
	Barbarian();
	virtual int creatureAttack();
	virtual int creatureDefend(int attackDamage);

};

