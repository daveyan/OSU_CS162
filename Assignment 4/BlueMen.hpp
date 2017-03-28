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

