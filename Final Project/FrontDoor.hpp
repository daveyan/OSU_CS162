/*********************************************************************
** Program Filename: FrontDoor.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to FrontDoor; a derived class from Space
*********************************************************************/
#pragma once
#include "Space.hpp"
class FrontDoor :
	public Space
{
public:
	FrontDoor();
	FrontDoor(string dName, string fName, int i);
	~FrontDoor();
	int special(int i);
};

