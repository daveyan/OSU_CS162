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

