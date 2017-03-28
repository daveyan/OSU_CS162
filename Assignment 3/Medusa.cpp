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
	name = "Medusa";
	attackDie.setDieSides(6);
	defenseDie.setDieSides(6);
	armor = 3;
	strength = 8;
	isAlive = true;
}
/*********************************************************************
** Function: creatureAttack
** Description: returns an integer depending on the roll of the die/dice
** associated with the creature. Medusa has a special feature where
** a double 6 roll will generate 99 damage.
** Parameters:
*********************************************************************/
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
/*********************************************************************
** Function: creatureDefends
** Description: returns an integer of the total damage dealt after
** taking into consideration the armor of the creature
** Parameters: attackDamage
*********************************************************************/
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



