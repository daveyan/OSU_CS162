/*********************************************************************
** Program Filename: Conway's Game of Life
** Author: David Yan
** Date: 1/17/16
** Description: Simulates a version of conway's game of life. 
** The user has an option of three different starting designs on a
** 40x20 world.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "initializeWorld.hpp"
#include "printWorld.hpp"
#include "destroyWorld.hpp"
#include "neighborCheck.hpp"
#include "startShape.hpp"
#include "worldSwap.hpp"

using namespace std;


int main()
{
	int genRepeat;
	int genDelay = 100000;

	bool validRepeat =false;

	//total row +6 buffer on each side
	const int worldR = 32; 
	//total column +6 buffer on each side plus an additional 30 
	//element buffer for the oscillator gun
	const int worldC = 82; 

	const char dead = ' ';
	const char alive = 'X';
	char **world = new char*[worldR];
	char **tempWorld = new char*[worldR];
	
	//creates the necessary "worlds" needed 
	initializeWorld(world, tempWorld, worldR, worldC);

	cout << "How many generations would you like to see?\n";
	cin >> genRepeat;

	//generation repetition validation
	if(genRepeat >0){
		validRepeat = true;
	}
	while(validRepeat == false){
		cout <<"Not a valid generation count\n";
		cout <<"How many generations would you like to see? \n";
		cin >> genRepeat; 
			if(genRepeat >0){
				validRepeat = true;
	}

	}

	//gathers desired shape from the user
	startShape(world, worldR, worldC);
	
	printWorld(world,worldR, worldC);

	for (int i = 0; i < genRepeat; i++) {
		//checks current cell status and copies info to a temporary world
		neighborCheck(world, tempWorld, worldR, worldC);
		//delay for before the new world is printed
		usleep(genDelay);
		//swaps temporary world to actual world
		worldSwap(world, tempWorld, worldR, worldC);
		//clears screen so that the new world can be printed
		system("clear");
		//reprints world
		printWorld(world,worldR, worldC);
		
	}

	//deallocates dynamic memory
	destroyWorld(world, tempWorld);
	

	return 0;
}

