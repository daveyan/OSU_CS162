/*********************************************************************
** Function: initializeWorld
** Description: first function used to initialize the two multi dimensional
** arrays. All elements are initialized as "dead" to display an empty world
** Parameters: world, tempWorld
*********************************************************************/
#include "initializeWorld.hpp"

void initializeWorld(char **world, char **tempWorld, int worldR, int worldC)
{
	const char dead = ' ';
	const char alive = 'X';
	//world
	for (int i = 0; i < worldR; i++) {
		world[i] = new char[worldC];
	}
	for (int i = 0; i < worldR; i++) {
		for (int j = 0; j < worldC; j++) {
			world[i][j] = dead;
		}
	}
	//temp world
	for (int i = 0; i < worldR; i++) {
		tempWorld[i] = new char[worldC];
	}
	for (int i = 0; i < worldR; i++) {
		for (int j = 0; j < worldC; j++) {
			tempWorld[i][j] = dead;
		}
	}
}
