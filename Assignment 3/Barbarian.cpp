/*********************************************************************
** Program Filename: Barbarian.cpp
** Author: David Yan 
** Date: 2/14/16
** Description: Barbarian class implementation. 
*********************************************************************/

#include "Barbarian.hpp"

#include <iostream>
#include <string>

using namespace std;

Barbarian::Barbarian()
{
	name = "Barbarian";
	attackDie.setDieSides(6);
	defenseDie.setDieSides(6);
	armor = 0;
	strength = 12;
	isAlive = true;
}
/*********************************************************************
** Function: creatureAttack
** Description: returns an integer depending on the roll of the die/dice
** associated with the creature
** Parameters:
*********************************************************************/
int Barbarian::creatureAttack()
{
	//2 ATTACK DICE (6 SIDES)
	return (attackDie.rollDie() + attackDie.rollDie());
}
/*********************************************************************
** Function: creatureDefends
** Description: returns an integer of the total damage dealt after 
** taking into consideration the armor of the creature
** Parameters: attackDamage
*********************************************************************/
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
