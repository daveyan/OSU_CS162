/*********************************************************************
** Program Filename: Stairs.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to stairs; a derived class from Space
*********************************************************************/
#pragma once
#include "Space.hpp"
class Stairs :
	public Space
{
public:
	Stairs();
	Stairs(string sName, string fName, int i);
	~Stairs();
	int special(int i);
};

