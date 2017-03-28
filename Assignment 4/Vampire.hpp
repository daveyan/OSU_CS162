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

