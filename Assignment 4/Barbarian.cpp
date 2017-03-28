/*********************************************************************
** Program Filename: Barbarian.cpp
** Author: David Yan
** Date: 2/28/16
** Description: Barbarian class implementation.
*********************************************************************/
#include "Barbarian.hpp"

#include <iostream>
#include <string>

using namespace std;

Barbarian::Barbarian()
{
	wins = 0;
	nickName = "NULL";
	name = "Barbarian";
	attackDie.setDieSides(6);
	defenseDie.setDieSides(6);
	armor = 0;
	maxStrength = 12;
	strength = 12;
	isAlive = true;
}

int Barbarian::creatureAttack()
{
	//2 ATTACK DICE (6 SIDES)
	return (attackDie.rollDie() + attackDie.rollDie());
}

int Barbarian::creatureDefend(int attackDamage)
{
	int totalDamage;
	//2 DEFENSE DICE (6 SIDES)
	int defensePoints = (defenseDie.rollDie() + defenseDie.rollDie());

	totalDamage = (attackDamage - defensePoints);
	if (totalDamage <= 0) {
		totalDamage = 0;
	}

	strength -= totalDamage;
	if (strength <= 0) {
		isAlive = false;
		strength = 0;
		
	}
	return totalDamage;
}
