/*********************************************************************
** Program Filename: Space.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to the base class Space
*********************************************************************/
#pragma once
#include "Item.hpp"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Space
{
protected:
	int indexNum;
	string spaceName;
	string fileName;
	Space *up;
	Space *down;
	Space *left;
	Space *right;
	int roomType;
	bool hasItem;

	Item containItem;
public:
	Space();
	~Space();

	
	string getFileName();
	string getName();
	int getRoomType();
	bool getHasItem();
	int getIndex();
	Space getUp();
	Space getDown();
	Space getLeft();
	Space getRight();

	void setIndexNum(int i);
	void setUp(Space *u);
	void setDown(Space *d);
	void setLeft(Space *l);
	void setRight(Space *r);
	void setHasItem(bool b);

	void readDesc(string s);

	Item getItem();
	void setItem(Item cItem);

	virtual int special(int i);
};

