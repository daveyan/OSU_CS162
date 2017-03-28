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

