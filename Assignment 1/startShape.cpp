/*********************************************************************
** Function: startShape
** Description: allows the user to generate the initial shape in the 
** world. 
** Parameters: world, tempWorld, worldR, worldC
*********************************************************************/
#include "startShape.hpp"

#include <iostream>

using namespace std;

void startShape(char ** world, int worldR, int worldC)
{
	int shape;
	int userR;
	int userC;

	bool validR = false;

	cout << "Select a starting point (between ROW (1-" << worldR - 12 << ") and COLUMN (1-" << worldC - 42 << "))\n";

	cout << "ROW: ";
	cin >> userR;
	userR += 5;

	cout << "COLUMN: ";
	cin >> userC;
	userC += 5;

	bool validNum = false;

	cout << "Which starting shape do you want you to exist in your world?\n";
	cout << "1. Oscillator\n";
	cout << "2. Glider\n";
	cout << "3. Glider Gun\n";
	cout << "Please enter a number now: ";
	cin >> shape;

	do {
		//OSCILLATOR
		if (shape == 1) {
			validNum = true;
			

			world[userR - 1][userC] = 'X';
			world[userR][userC] = 'X';
			world[userR + 1][userC] = 'X';
		}

		//GLIDER
		if (shape == 2) {
			validNum = true;
		

			world[userR - 2][userC] = 'X';
			world[userR - 1][userC] = 'X';
			world[userR][userC] = 'X';
			world[userR][userC - 1] = 'X';
			world[userR - 1][userC - 2] = 'X';
		}

		//GLIDER GUN
		if (shape == 3) {
			validNum = true;
		

			world[userR][userC] = 'X';
			world[userR - 1][userC] = 'X';
			world[userR - 1][userC + 1] = 'X';
			world[userR][userC + 1] = 'X';
			world[userR - 3][userC + 12] = 'X';
			world[userR - 2][userC + 11] = 'X';
			world[userR - 1][userC + 10] = 'X';
			world[userR][userC + 10] = 'X';
			world[userR + 1][userC + 10] = 'X';
			world[userR + 2][userC + 11] = 'X';
			world[userR + 3][userC + 12] = 'X';
			world[userR + 3][userC + 13] = 'X';
			world[userR - 3][userC + 13] = 'X';
			world[userR][userC + 14] = 'X';
			world[userR - 2][userC + 15] = 'X';
			world[userR + 2][userC + 15] = 'X';
			world[userR - 1][userC + 16] = 'X';
			world[userR][userC + 16] = 'X';
			world[userR + 1][userC + 16] = 'X';
			world[userR][userC + 17] = 'X';
			world[userR - 3][userC + 20] = 'X';
			world[userR - 3][userC + 21] = 'X';
			world[userR - 2][userC + 20] = 'X';
			world[userR - 2][userC + 21] = 'X';
			world[userR - 1][userC + 20] = 'X';
			world[userR - 1][userC + 21] = 'X';
			world[userR - 4][userC + 22] = 'X';
			world[userR][userC + 22] = 'X';
			world[userR - 4][userC + 24] = 'X';
			world[userR - 5][userC + 24] = 'X';
			world[userR][userC + 24] = 'X';
			world[userR + 1][userC + 24] = 'X';
			world[userR - 3][userC + 34] = 'X';
			world[userR - 3][userC + 35] = 'X';
			world[userR - 2][userC + 34] = 'X';
			world[userR - 2][userC + 35] = 'X';
		}

		//SHAPE VALIDATION
		if (shape < 1 || shape >3) {
			cout << "The number you have entered is invalid\n";
			cout << "Please try again: ";
			cin >> shape;
		}

	} while (validNum == false);

}