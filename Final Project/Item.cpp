/*********************************************************************
** Program Filename: Item.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Implementation file to Item. The only thing unique
** about Item is that is has a unique name.
*********************************************************************/
#include "Item.hpp"



Item::Item()
{
}
/*********************************************************************
** Function: Constructor
** Description: sets a name for the item
*********************************************************************/
Item::Item(string name)
{
	itemName = name;
}

Item::~Item()
{
}

string Item::getItemName()
{
	return itemName;
}
