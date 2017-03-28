/*********************************************************************
** Program Filename: HarryPotter.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Harry Potter class implementation.
*********************************************************************/

#include "HarryPotter.hpp"
#include <iostream>
#include <string>

using namespace std;


HarryPotter::HarryPotter()
{
	wins = 0;
	nickName = "NULL";
	name = "Wizard";
	attackDie.setDieSides(6);
	defenseDie.setDieSides(6);
	armor = 0;
	maxStrength = 10;
	strength = 10;
	isAlive = true;
	revived = false;
}

int HarryPotter::creatureAttack()
{
	//2 ATTACK DICE (6 SIDES)
	return (attackDie.rollDie() + attackDie.rollDie());
}

int HarryPotter::creatureDefend(int attackDamage)
{
	int totalDamage;
	//2 DEFENSE DICE (6 SIDES)
	int defensePoints = (defenseDie.rollDie() + defenseDie.rollDie());
	totalDamage = (attackDamage - defensePoints);
	if (totalDamage <= 0) {
		totalDamage = 0;
	}

	strength -= totalDamage;
	if (revived == false) {
		if (strength <= 0) {
			
			strength = 0;
			revived = true;
			cout << "Sensing that he will get knocked out by the next attack, ";
			cout<<nickName <<" drinks an odd potion" << endl;
			cout<< "He will be made stronger when he revives " << endl;
			strength = 20;
		}
	}
	else {
		if (strength <= 0) {
			isAlive = false;
			strength = 0;
		}
	}
	return totalDamage;
}


