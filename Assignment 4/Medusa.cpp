/*********************************************************************
** Program Filename: Medusa.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Medusa class implementation.
*********************************************************************/

#include "Medusa.hpp"
#include "Die.hpp"

#include <iostream>
#include <string>

using namespace std;

Medusa::Medusa()
{
	wins = 0;
	nickName = "NULL";
	name = "Medusa";
	attackDie.setDieSides(6);
	defenseDie.setDieSides(6);
	armor = 3;
	maxStrength = 8;
	strength = 8;
	isAlive = true;
}

int Medusa::creatureAttack()
{
	int totalDamage;
	//2 ATTACK DICE (6 SIDES)
	totalDamage = attackDie.rollDie() + attackDie.rollDie();

	//MEDUSA GLARE - if I roll a 12 (6+6) it will automatically kill the opponent.
	if (totalDamage == 12) {
		cout << "Medusa uses GLARE!" << endl;
		return 99;
	}
	return totalDamage;
}

int Medusa::creatureDefend(int attackDamage)
{
	int totalDamage;
	//1 DEFENSE DICE (6 SIDES)
	int defensePoints = defenseDie.rollDie();
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



