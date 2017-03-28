/*********************************************************************
** Program Filename: Item.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Header file to a the Item class
*********************************************************************/
#pragma once
#include <string>

using namespace std;
class Item
{
private:
	string itemName;
public:
	Item();
	Item(string name);
	~Item();
	string getItemName();
};

