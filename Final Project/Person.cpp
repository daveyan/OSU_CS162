/*********************************************************************
** Program Filename: Person.hpp
** Author: David Yan
** Date: 3/15/16
** Description: Implementation to the person class
*********************************************************************/
#include "Person.hpp"
#include "Container.hpp"
#include "Space.hpp"

#include <iostream>
#include <vector>

using namespace std;

Person::Person()
{

}


Person::~Person()
{
}

Space Person::getLastPosition()
{
	return lastPosition;
}

Space Person::getPosition()
{
	return currentPosition;
}
/*********************************************************************
** Function: checkForItem
** Description: looks through data member pocket to see if an item's
** name matches with string s
** Parameters: string associated with an item
*********************************************************************/
int Person::checkForItem(string s)
{
	for (int i = 0; i < pocket.size(); i++) {
		if (pocket[i].getItemName() == s) {
			return 1;
		}
	}
	return 0;
	
}

int Person::getPocketSize()
{
	return pocket.size();
}
/*********************************************************************
** Function: emptyPockets
** Description: clears out the vector at the start of each game
** Parameters:

*********************************************************************/
void Person::emptyPockets()
{
	pocket.clear();
}
/*********************************************************************
** Function: viewPocket
** Description: displays all items in the data member pocket. if there
** is nothing, it informs the player.
** Parameters:
*********************************************************************/
void Person::viewPocket()
{
	if (pocket.size() == 0) {
		cout << "There is nothing in your pocket" << endl;

	}
	else {
		cout << "Items in your pocket: " << endl << endl;
		for (int i = 0; i < pocket.size(); i++) {
			cout << pocket[i].getItemName() << endl;
		}
	}
}
/*********************************************************************
** Function: addToPocket
** Description: adds and item to the data memeber pocket. certain items
** will trigger unique text.
** Parameters: item i
*********************************************************************/
void Person::addToPocket(Item i)
{
	pocket.push_back(i);
	cout << "You shove the \"" << i.getItemName() << "\" into your pocket." << endl;
	//UNIQUE TEXT FOR CERTAIN ITEMS
	if (i.getItemName() == "Wallet") {
		cout << "Alright you have your wallet! What was it doing in there?" << endl;
	}
	else if (i.getItemName() == "Jacket") {
		cout << "Surprisingly it fits" << endl;
	}
	else if (i.getItemName() == "Old Pizza Slice") {
		cout << "Sweet an extra slice!" << endl;
	}
	else if (i.getItemName() == "Trash") {
		cout << "You're not too sure why you just did that.." << endl;
	}
	else {
		cout << "I'm sure I can use this for something" << endl;
	}
	currentPosition.setHasItem(false);

}

void Person::setLastPosition(Space s)
{
	lastPosition = s;
}

void Person::setPosition(Space s)
{
	currentPosition = s;
}
/*********************************************************************
** Function: viewSpaces
** Description: goes through the space pointers of a space and returns
** the name of the space to the player.
** there is a display order of frontdoor, rooms, stairs, and then containers
** Parameters: map of the game
*********************************************************************/
void Person::viewSpaces(Space *map[])
{
	cout << "Obvious exits are :" << endl;
	
	//for frontDoor
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 4) {
		cout << "\"" << currentPosition.getUp().getName() << "\" ";
	}
	if (currentPosition.getLeft().getName() != "Empty"&& currentPosition.getLeft().getRoomType() == 4) {
		cout << "\"" << currentPosition.getLeft().getName() << "\" ";
	}
	if (currentPosition.getDown().getName() != "Empty"&& currentPosition.getDown().getRoomType() == 4) {
		cout << "\"" << currentPosition.getDown().getName() << "\" ";
	}
	if (currentPosition.getRight().getName() != "Empty"&& currentPosition.getRight().getRoomType() == 4) {
		cout << "\"" << currentPosition.getRight().getName() << "\" ";
	}
	//for rooms
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 1) {
		cout << "\"" << currentPosition.getUp().getName() << "\" ";
	}
	if (currentPosition.getLeft().getName() != "Empty" && currentPosition.getLeft().getRoomType() == 1) {
		cout << "\"" << currentPosition.getLeft().getName() << "\" ";
	}
	if (currentPosition.getDown().getName() != "Empty" && currentPosition.getDown().getRoomType() == 1) {
		cout << "\"" << currentPosition.getDown().getName() << "\" ";
	}
	if (currentPosition.getRight().getName() != "Empty" && currentPosition.getRight().getRoomType() == 1) {
		cout << "\"" << currentPosition.getRight().getName() << "\" ";
	}
	//for stairs
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 3) {
		cout << "\"" << currentPosition.getUp().getName() << "\" ";
	}
	if (currentPosition.getLeft().getName() != "Empty"&& currentPosition.getLeft().getRoomType() == 3) {
		cout << "\"" << currentPosition.getLeft().getName() << "\" ";
	}
	if (currentPosition.getDown().getName() != "Empty"&& currentPosition.getDown().getRoomType() == 3) {
		cout << "\"" << currentPosition.getDown().getName() << "\" ";
	}
	if (currentPosition.getRight().getName() != "Empty"&& currentPosition.getRight().getRoomType() == 3) {
		cout << "\"" << currentPosition.getRight().getName() << "\" ";
	}
	cout << endl << endl;
	cout << "Places of intrest include :" << endl;
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 2) {
		cout << "\"" << currentPosition.getUp().getName() << "\" ";
	}
	if (currentPosition.getLeft().getName() != "Empty"&& currentPosition.getLeft().getRoomType() == 2) {
		cout << "\"" << currentPosition.getLeft().getName() <<"\" ";
	}
	if (currentPosition.getDown().getName() != "Empty"&& currentPosition.getDown().getRoomType() == 2) {
		cout << "\"" << currentPosition.getDown().getName() << "\" ";
	}
	if (currentPosition.getRight().getName() != "Empty"&& currentPosition.getRight().getRoomType() == 2) {
		cout << "\"" << currentPosition.getRight().getName() << "\" ";
	}


	cout << endl;
}
/*********************************************************************
** Function: look for item
** Description: returns the name of an items if a container has an item
** Parameters:
*********************************************************************/
void Person::lookForItems()
{
	cout << "You look around and you find ";
	if (currentPosition.getHasItem() == true) {
		cout << "a \"" << currentPosition.getItem().getItemName()<<"\"" << endl;
	}
	else {
		cout << "nothing " << endl;
		
	}
}
/*********************************************************************
** Function: moveChar
** Description: moves the Person's position pointer depending on the
** directionInput "dirInput"
** Parameters: char 
*********************************************************************/
void Person::moveChar(char dirInput)
{
	if (dirInput == 'W' || dirInput == 'w') {
		lastPosition = currentPosition;
		currentPosition = currentPosition.getUp();
	}
	if (dirInput == 'A' || dirInput == 'a') {
		lastPosition = currentPosition;
		currentPosition = currentPosition.getLeft();
	}
	if (dirInput == 'S' || dirInput == 's') {
		lastPosition = currentPosition;
		currentPosition = currentPosition.getDown();
	}
	if (dirInput == 'D' || dirInput == 'd') {
		lastPosition = currentPosition;
		currentPosition = currentPosition.getRight();
	}

}
/*********************************************************************
** Function: displayMoveOptions
** Description: displays all potential paths with directional keys
** Parameters: a pointer to an array of spaces
*********************************************************************/
void Person::displayMoveOptions(Space * map[])
{
	cout << "Potential Paths\n " << endl;
	
	//for FrontDoor
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 4) {
		cout << "[W]" << currentPosition.getUp().getName() << endl;
	}
	if (currentPosition.getLeft().getName() != "Empty"&& currentPosition.getLeft().getRoomType() == 4) {
		cout << "[A]" << currentPosition.getLeft().getName() << endl;
	}
	if (currentPosition.getDown().getName() != "Empty"&& currentPosition.getDown().getRoomType() == 4) {
		cout << "[S]" << currentPosition.getDown().getName() << endl;
	}
	if (currentPosition.getRight().getName() != "Empty"&& currentPosition.getRight().getRoomType() == 4) {
		cout << "[D]" << currentPosition.getRight().getName() << endl;
		
	}
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 1) {
		cout << "[W]" << currentPosition.getUp().getName() << endl;
	}
	if (currentPosition.getLeft().getName() != "Empty" && currentPosition.getLeft().getRoomType() == 1) {
		cout << "[A]" << currentPosition.getLeft().getName() << endl;
	}
	if (currentPosition.getDown().getName() != "Empty" && currentPosition.getDown().getRoomType() == 1) {
		cout << "[S]" << currentPosition.getDown().getName() << endl;
	}
	if (currentPosition.getRight().getName() != "Empty" && currentPosition.getRight().getRoomType() == 1) {
		cout << "[D]" << currentPosition.getRight().getName() << endl;
	}
	//for Stairs
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 3) {
		cout << "[W]" << currentPosition.getUp().getName() << endl;
	}
	if (currentPosition.getLeft().getName() != "Empty"&& currentPosition.getLeft().getRoomType() == 3) {
		cout << "[A]" << currentPosition.getLeft().getName() << endl;
	}
	if (currentPosition.getDown().getName() != "Empty"&& currentPosition.getDown().getRoomType() == 3) {
		cout << "[S]" << currentPosition.getDown().getName() << endl;
	}
	if (currentPosition.getRight().getName() != "Empty"&& currentPosition.getRight().getRoomType() == 3) {
		cout << "[D]" << currentPosition.getRight().getName() << endl;

	}
	cout << endl;
	cout << "Places of Interest \n" << endl;
	if (currentPosition.getUp().getName() != "Empty" && currentPosition.getUp().getRoomType() == 2) {
		cout << "[W]" << currentPosition.getUp().getName() << endl;
	}
	if (currentPosition.getLeft().getName() != "Empty"&& currentPosition.getLeft().getRoomType() == 2) {
		cout << "[A]" << currentPosition.getLeft().getName() << endl;
	}
	if (currentPosition.getDown().getName() != "Empty"&& currentPosition.getDown().getRoomType() == 2) {
		cout << "[S]" << currentPosition.getDown().getName() << endl;
	}
	if (currentPosition.getRight().getName() != "Empty"&& currentPosition.getRight().getRoomType() == 2) {
		cout << "[D]" << currentPosition.getRight().getName() << endl;
		cout << endl;
	}



	cout << endl;
	
}