/*********************************************************************
** Program Filename: BlueMen.cpp
** Author: David Yan
** Date: 2/28/16
** Description: BlueMen class implementation.
*********************************************************************/

#include "BlueMen.hpp"

#include <iostream>
#include <string>

using namespace std;


BlueMen::BlueMen()
{
	wins = 0;
	nickName = "NULL";
	name = "Blue Men";
	attackDie.setDieSides(10);
	defenseDie.setDieSides(6);
	armor = 3;
	maxStrength = 12;
	strength = 12;
	isAlive = true;
}

int BlueMen::creatureAttack()
{
	//2 ATTACK DICE (10 SIDES)
	return (attackDie.rollDie() + attackDie.rollDie());
}

int BlueMen::creatureDefend(int attackDamage)
{
	int defensePoints;
	int totalDamage;
	//3 DEFENSE DICE (3 SIDES)
	if (strength > 8) {
		defensePoints =(defenseDie.rollDie() + defenseDie.rollDie() + defenseDie.rollDie());
	}
	else if (strength > 4) {
		defensePoints = (defenseDie.rollDie() + defenseDie.rollDie());
	}
	else if (strength > 0) {
		defensePoints = (defenseDie.rollDie());
	}


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



