/*********************************************************************
** Function: neighborCheck
** Description: checks the surrounding elements for each element to 
** determine the status of the cell for the next generation. This 
** is then passed to the temporary world as storage until it is swapped
** to the current world
** Parameters: world, tempWorld, worldR, worldC
*********************************************************************/
#include "neighborCheck.hpp"

void neighborCheck(char ** world, char ** tempWorld, int worldR, int worldC)
{
	int neighbors;

	for (int i = 1; i < worldR - 1; i++) {
		for (int j = 1; j < worldC - 1; j++) {

			neighbors = 0;


			//top row
			if (world[i - 1][j - 1] == 'X') {
				neighbors++;
			}
			if (world[i - 1][j] == 'X') {
				neighbors++;
			}
			if (world[i - 1][j + 1] == 'X') {
				neighbors++;
			}
			//middle row
			if (world[i][j - 1] == 'X') {
				neighbors++;
			}

			if (world[i][j + 1] == 'X') {
				neighbors++;
			}
			//bottom row
			if (world[i + 1][j - 1] == 'X') {
				neighbors++;
			}
			if (world[i + 1][j] == 'X') {
				neighbors++;
			}
			if (world[i + 1][j + 1] == 'X') {
				neighbors++;
			}


			//filling in temp		

			if (world[i][j] == 'X' && neighbors < 2) {
				tempWorld[i][j] = ' ';
			}
			else if (world[i][j] == 'X' && (neighbors == 2 || neighbors == 3)) {
				tempWorld[i][j] = 'X';
			}
			else if (world[i][j] == 'X' && neighbors > 3) {
				tempWorld[i][j] = ' ';
			}
			else if (world[i][j] == ' ' && neighbors == 3) {
				tempWorld[i][j] = 'X';



			}
		}


	}
}