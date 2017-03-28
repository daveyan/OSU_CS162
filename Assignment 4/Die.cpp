/*********************************************************************
** Program Filename: Die.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Die class implementation
*********************************************************************/
#include "Die.hpp"
#include <ctime>
#include <iostream>

using namespace std;

Die::Die()
{
}

void Die::setDieSides(int num)
{
	numOfSides = num;
}

int Die::getDieSides()
{
	return numOfSides;
}

int Die::rollDie()
{
	
	return rand() % numOfSides + 1;
}


