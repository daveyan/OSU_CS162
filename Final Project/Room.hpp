/*********************************************************************
** Program Filename: Room.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to room; a derived class from Space
*********************************************************************/
#pragma once
#include "Space.hpp"
class Room :
	public Space
{
public:
	Room();
	Room(string rName, string fName, int i);
	~Room();
	int special(int i);
};

