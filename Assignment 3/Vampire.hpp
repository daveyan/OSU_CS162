/*********************************************************************
** Program Filename: Vampire.hpp
** Author: David Yan
** Date: 2/14/16
** Description: Vampire class header.
*********************************************************************/
#pragma once
#include "Creature.hpp"
class Vampire :
	public Creature
{
public:
	Vampire();
	virtual int creatureAttack();
	virtual int creatureDefend(int attackDamage);
};

