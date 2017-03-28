/*********************************************************************
** Program Filename: Container.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to Container; a derived class from Space. Unique as
** it contains an Item object
*********************************************************************/
#pragma once
#include <string>

#include "Space.hpp"
#include "Item.hpp"

using namespace std;

class Container :
	public Space
{
private:

	Item containItem;
public:
	Container();
	Container(string cName, string fName, int i);
	~Container();

	int special(int i);
};

