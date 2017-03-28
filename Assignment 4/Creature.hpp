#pragma once
#include "Die.hpp"
#include <string>
class Creature
{
protected:

	string name;
	string nickName;
	Die attackDie;
	Die defenseDie;
	int armor;
	int maxStrength;
	int strength;
	bool isAlive;
	int wins;
	int teamNum;
public:
	Creature();
	string getNickName();
	string getName();
	int getWins();
	int getArmor();
	int getStrength();
	bool getIsAlive();
	void addWin();
	int getTeamNum();
	void setTeamNum(int num);
	void setNickName(string nName);
	void setArmor(int newArmor);
	void setStrength(int newStrength);
	void setIsAlive(bool status);
	virtual int creatureAttack() = 0;
	virtual int creatureDefend(int attackDamage) = 0;
	void recover();

};

