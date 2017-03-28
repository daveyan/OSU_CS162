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
	wins = 0;
	nickName = "NULL";
	name = "Vampire";
	attackDie.setDieSides(12);
	defenseDie.setDieSides(6);
	armor = 1;
	maxStrength = 18;
	strength = 18;
	isAlive = true;
}

int Vampire::creatureAttack()
{
	//1 ATTACK DICE (12 SIDES)
	return attackDie.rollDie();
}

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


