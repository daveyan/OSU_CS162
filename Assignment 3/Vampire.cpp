/*********************************************************************
** Program Filename: Vampire.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Vampire class implementation.
*********************************************************************/
#include "Vampire.hpp"

#include <iostream>
#include <string>

using namespace std;

Vampire::Vampire()
{
	name = "Vampire";
	attackDie.setDieSides(12);
	defenseDie.setDieSides(6);
	armor = 1;
	strength = 18;
	isAlive = true;
}
/*********************************************************************
** Function: creatureAttack
** Description: returns an integer depending on the roll of the die/dice
** associated with the creature.
** Parameters:
*********************************************************************/
int Vampire::creatureAttack()
{
	//1 ATTACK DICE (12 SIDES)
	return attackDie.rollDie();
}
/*********************************************************************
** Function: creatureDefends
** Description: returns an integer of the total damage dealt after
** taking into consideration the armor of the creature. there is a 50/50
** percent chance that the vampire will generate 99 defense.
** Parameters: attackDamage
*********************************************************************/
int Vampire::creatureDefend(int attackDamage)
{

	int totalDamage;
	//1 DEFENSE DICE (6 SIDES)
	int defensePoints = defenseDie.rollDie();
	//VAMPIRE CHARM - 50% chance to take no damage
	int charm = (rand() % 2);
	if (charm == 1) {
		cout << "Vampire uses CHARM" << endl;
		defensePoints = 99;
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


