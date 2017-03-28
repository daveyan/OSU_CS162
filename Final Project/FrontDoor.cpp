/*********************************************************************
** Program Filename: FrontDoor.cpp
** Author: David Yan
** Date: 3/15/16
** Description: Implementation file for FrontDoor. This serves as the
** exit/final room to the game
*********************************************************************/
#include "FrontDoor.hpp"



FrontDoor::FrontDoor()
{
}
/*********************************************************************
** Function: Constructor
** Description: sets the name the associated txt for fstream and it's current index
** Parameters: name for space and file, index number
*********************************************************************/
FrontDoor::FrontDoor(string dName, string fName,int i)
{
	spaceName = dName;
	fileName = fName;
	indexNum = i;
	roomType = 4;	// 4 signifies a front door
}


FrontDoor::~FrontDoor()
{
}
/*********************************************************************
** Function: special()
** Description: reads from the txt file associated with the room. It
** returns a value that reads a different description depending on the 
** outcome. 
** Parameters: int "i" determines which file it should read. 
*********************************************************************/
int FrontDoor::special(int i)
{
	if (i == 1) {
		readDesc("Win.txt");
		
	}
	if (i == 0) {
		readDesc("Lose.txt");	//this served a purpose prior to making the 
								//Item "Wallet" as a requirement for beating
								//the game. Free free to read the lose.txt file
	}
	return 0;
}
