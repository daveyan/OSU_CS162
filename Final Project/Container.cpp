/*********************************************************************
** Program Filename: Container.cpp
** Author: David Yan
** Date: 3/15/16
** Description: Implementation file to Container; a derived class from Space. Unique as
** it contains an Item object
*********************************************************************/
#include "Container.hpp"
#include <iostream>

using namespace std;


Container::Container()
{
}
/*********************************************************************
** Function: Constructor
** Description: sets the name the associated txt for fstream and it's current index
** Parameters: name for space and file, index number
*********************************************************************/
Container::Container(string cName, string fName, int i)
{
	spaceName = cName;
	
	fileName = fName;
	hasItem = true;
	indexNum = i;
	roomType = 2;	//2 signifies a container
}


Container::~Container()
{
}
/*********************************************************************
** Function: special()
** Description: reads from the txt file associated with the room. It
** returns a value that alters the game's "time"
** Parameters: int "i" this acts as a bool as to whether or not it should
** run the function.
*********************************************************************/
int Container::special(int i)
{
	
	readDesc("containerSpecial.txt");
			
	return 5;
}
