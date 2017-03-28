/*********************************************************************
** Program Filename: Medusa.hpp
** Author: David Yan
** Date: 2/14/16
** Description: Medusa class header
*********************************************************************/
#pragma once
#include "Creature.hpp"
class Medusa :
	public Creature
{
public:
	Medusa();
	virtual int creatureAttack();
	virtual int creatureDefend(int attackDamage);

};

