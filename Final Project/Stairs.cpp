/*********************************************************************
** Program Filename: Stairs.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to stairs; a derived class from Space
*********************************************************************/
#include "Stairs.hpp"





Stairs::Stairs()
{
}
/*********************************************************************
** Function: Constructor
** Description: sets the name the associated txt for fstream and it's current index
** Parameters: name for space and file, index number
*********************************************************************/
Stairs::Stairs(string sName, string fName, int i)
{
	spaceName = sName;
	fileName = fName;
	roomType = 3;
	indexNum = i;
}

Stairs::~Stairs()
{
}
/*********************************************************************
** Function: special()
** Description: returns a value to add as a penalty to the player.
** reads the appropriate file associated with the stairs.
** Parameter: int i
*********************************************************************/
int Stairs::special(int i)
{
	readDesc("stairs.txt");

	return 2;
}
