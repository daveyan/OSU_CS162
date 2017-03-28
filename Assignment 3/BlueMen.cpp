/*********************************************************************
** Program Filename: BlueMen.cpp
** Author: David Yan
** Date: 2/14/16
** Description: BlueMen class implementation.
*********************************************************************/
#include "BlueMen.hpp"

#include <iostream>
#include <string>

using namespace std;


BlueMen::BlueMen()
{
	name = "Blue Men";
	attackDie.setDieSides(10);
	defenseDie.setDieSides(6);
	armor = 3;
	strength = 12;
	isAlive = true;
}
/*********************************************************************
** Function: creatureAttack
** Description: returns an integer depending on the roll of the die/dice
** associated with the creature
** Parameters:
*********************************************************************/
int BlueMen::creatureAttack()
{
	//2 ATTACK DICE (10 SIDES)
	return (attackDie.rollDie() + attackDie.rollDie());
}

/*********************************************************************
** Function: creatureDefends
** Description: returns an integer of the total damage dealt after
** taking into consideration the armor of the creature. Blue Men loses
** a defensive die roll per 4 strenght lost.
** Parameters: attackDamage
*********************************************************************/
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



