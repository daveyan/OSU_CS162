/*********************************************************************
** Program Filename: Room.cpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to room; a derived class from Space
*********************************************************************/
#include "Room.hpp"
#include <iostream>

using namespace std;

Room::Room()
{
}
/*********************************************************************
** Function: Constructor
** Description: sets the name the associated txt for fstream and it's current index
** Parameters: name for space and file, index number
*********************************************************************/
Room::Room(string rName, string fName, int i)
{

	spaceName = rName;
	fileName = fName;
	indexNum = i;
	roomType = 1;
}


Room::~Room()
{
}
/*********************************************************************
** Function: special()
** Description: returns a value to give the player additional time.
** this special function is limited to 4 uses. this is governed by the
** parameter i
** Parameter: int i 
*********************************************************************/
int Room::special(int i)
{
	if (i == 0) {
		readDesc("roomSpecial0.txt");
		cin.ignore();
		cin.get();
	}
	if (i == 1) {
		readDesc("roomSpecial1.txt");
		cin.ignore();
		cin.get();
	}
	if (i == 2) {
		readDesc("roomSpecial2.txt");
		cin.ignore();
		cin.get();
	}
	if (i == 3) {
		readDesc("roomSpecial3.txt");
		cin.ignore();
		cin.get();
	}
	return 3;
}
