/*********************************************************************
** Program Filename: Person.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to a the Person class
*********************************************************************/
#pragma once

#include "Space.hpp"
#include "Item.hpp"
#include <vector>
class Person
{
private:

	Space currentPosition;
	Space lastPosition;
	vector<Item> pocket;
public:
	Person();
	~Person();
	Space getLastPosition();
	Space getPosition();
	int checkForItem(string s);
	int getPocketSize();
	void emptyPockets();
	void viewPocket();
	void addToPocket(Item i);
	void setLastPosition(Space s);
	void setPosition(Space s);
	void viewSpaces(Space *map[]);
	void lookForItems();
	void moveChar(char dirInput);
	void displayMoveOptions(Space *map[]);
};

