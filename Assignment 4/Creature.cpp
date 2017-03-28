/*********************************************************************
** Program Filename: Creature.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Creature class implementation file. This is an abstract
** class
*********************************************************************/

#include "Creature.hpp"
#include <string>
#include <iostream>

using namespace std;

Creature::Creature()
{

}

string Creature::getNickName()
{
	return nickName;
}

string Creature::getName()
{
	return name;
}

int Creature::getWins()
{
	return wins;
}

int Creature::getArmor()
{
	return armor;
}

int Creature::getStrength()
{
	return strength;
}

bool Creature::getIsAlive()
{
	return isAlive;
}

void Creature::addWin()
{
	wins++;
}

int Creature::getTeamNum()
{
	return teamNum;
}

void Creature::setTeamNum(int num)
{
	teamNum = num;
}

void Creature::setNickName(string nName)
{
	nickName = nName;
}

void Creature::setArmor(int newArmor)
{
	armor = newArmor;
}

void Creature::setStrength(int newStrength)
{
	strength = newStrength;
}

void Creature::setIsAlive(bool status)
{
	isAlive = status;
}

int Creature::creatureAttack()
{
	return 0;
}

int Creature::creatureDefend(int attackDamage)
{
	return 0;
}

void Creature::recover()
{

	if (strength < maxStrength) {
		strength = strength + maxStrength*.25;
		if (strength > maxStrength) {
			strength = maxStrength;
		}
		cout << nickName << " recovered some strength. It is now " << strength << endl;

	}
}

