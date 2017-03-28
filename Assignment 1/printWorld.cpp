/*********************************************************************
** Function: print world
** Description: displays world to the console. Initial loop counters
** i and j are offset to include the additional room allocated to 
** accomodate cells living on the edge off of the visible area
** Parameters: world, tempWorld, worldR, worldC
*********************************************************************/
#include "printWorld.hpp"
#include <iostream>

using namespace std;

void printWorld(char ** world, int worldR, int worldC)
{
	const char dead = ' ';
	const char alive = 'X';

	for (int i = 6; i < worldR - 6; i++) {

		for (int j = 6; j < worldC - 36; j++) {
			cout << "" << world[i][j] << " ";
		}
		cout << endl;
	}
}