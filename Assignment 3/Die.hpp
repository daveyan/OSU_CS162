/*********************************************************************
** Program Filename: Die.hpp
** Author: David Yan
** Date: 2/14/16
** Description: Die class header
*********************************************************************/

#pragma once
#include <ctime>

using namespace std;

class Die
{
private:
	int numOfSides;
public:
	Die();
	void setDieSides(int num);
	int getDieSides();
	int rollDie();
};

