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
/*********************************************************************
** Function: rollDie
** Description: returns a random die roll based on the number of die sides
** of the object
** Parameters:
*********************************************************************/
int Die::rollDie()
{
	
	return rand() % numOfSides + 1;
}


