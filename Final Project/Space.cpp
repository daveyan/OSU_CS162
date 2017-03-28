
/*********************************************************************
** Program Filename: Space.cpp
** Author: David Yan
** Date: 3/15/16
** Description: Implementation file to the base class Space
*********************************************************************/
#include "Space.hpp"




Space::Space()
{
}

Space::~Space()
{
}

string Space::getFileName()
{
	return fileName;
}

string Space::getName()
{
	return spaceName;
}

int Space::getRoomType()
{
	return roomType;
}


bool Space::getHasItem()
{
	return hasItem;
}

int Space::getIndex()
{
	return indexNum;
}



Space Space::getUp()
{
	return *up;
}

Space Space::getDown()
{
	return *down;
}

Space Space::getLeft()
{
	return *left;
}

Space Space::getRight()
{
	return *right;
}

void Space::setIndexNum(int i)
{
	indexNum = i;
}

void Space::setUp(Space *u)
{
	up = u;
}

void Space::setDown(Space * d)
{
	down = d;
}

void Space::setLeft(Space * l)
{
	left = l;
}

void Space::setRight(Space * r)
{
	right = r;
}

void Space::setHasItem(bool b)
{
	hasItem = b;
}
/*********************************************************************
** Function: readDesc
** Description: reads from the txt file associated with the room.
** Parameters: string for the file name
*********************************************************************/
void Space::readDesc(string s)
{

	ifstream ifs;
	ifs.open(s);
	string textString;
	if (ifs.good()) {
		while (getline(ifs, textString)) {
			cout << textString << '\n';

		}
	}
}



Item Space::getItem()
{
	return containItem;
}

void Space::setItem(Item cItem)
{
	containItem = cItem;
}

int Space::special(int i)
{
	return 0;
}

