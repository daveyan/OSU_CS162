#pragma once
#include "Creature.hpp"
class Barbarian : virtual public Creature
{
public:
	Barbarian();
	virtual int creatureAttack();
	virtual int creatureDefend(int attackDamage);

};

