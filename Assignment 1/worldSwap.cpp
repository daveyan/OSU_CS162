/*********************************************************************
** Function: worldSwap
** Description: performs a multidimensional array swap between the 
** world (displayed to user) and tempWorld (holds the next generation
** cell status)
** Parameters: world, tempWorld, worldR, worldC
*********************************************************************/
#include "worldSwap.hpp"

void worldSwap(char ** world, char ** tempWorld, int worldR, int worldC)
{
	//world transfer - swap
	for (int i = 1; i < worldR; i++) {
		for (int j = 1; j < worldC; j++) {
			world[i][j] = tempWorld[i][j];
		}
	}
	//changes edge units to dead
	for (int i = 0; i < worldR; i++) {
		for (int j = 0; j < worldC; j++) {
			if (i == 0 || i == worldR) {
				world[i][j] = ' ';
			}
			if (j == 0 || j == worldC) {
				world[i][j] = ' ';
			}
		}
	}
}