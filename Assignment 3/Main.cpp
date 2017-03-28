/*********************************************************************
** Program Filename: Main.cpp
** Author: David Yan
** Date: 2/14/16
** Description: Test function for the program
*********************************************************************/
#include <iostream>
#include <ctime>

#include "Die.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "BlueMen.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"

using namespace std;

int main() {

	srand(time(NULL));
	int attack;
	int defense;
	bool play = true;
	char yesOrNo;


while(play == true){
	//Creature two distinct list of creatures
	Creature * c1Array[] = {
		new Barbarian(),
		new Medusa(),
		new BlueMen(),
		new Vampire(),
		new HarryPotter(),
	};
	Creature * c2Array[] = {
		new Barbarian(),
		new Medusa(),
		new BlueMen(),
		new Vampire(),
		new HarryPotter(),
	};
	
	int userSelction1;
	int userSelction2;


	system("clear");
		//MENU
		cout << "Welcome to the battle of creatures" << endl;
		cout << "Choose your first creature" << endl;
		cout << "1 " << c1Array[0]->getName() << endl;
		cout << "2 " << c1Array[1]->getName() << endl;
		cout << "3 " << c1Array[2]->getName() << endl;
		cout << "4 " << c1Array[3]->getName() << endl;
		cout << "5 " << c1Array[4]->getName() << endl;
		cout << "Enter a number between 1-5" << endl;
		cin >> userSelction1;
		system("clear");
		cout << "Choose your second creature" << endl;
		cout << "1 " << c1Array[0]->getName() << endl;
		cout << "2 " << c1Array[1]->getName() << endl;
		cout << "3 " << c1Array[2]->getName() << endl;
		cout << "4 " << c1Array[3]->getName() << endl;
		cout << "5 " << c1Array[4]->getName() << endl;
		cout << "Enter a number between 1-5" << endl;
		cin >> userSelction2;
		cin.ignore();

		while (c1Array[userSelction1 - 1]->getIsAlive() == true && c2Array[userSelction2 - 1]->getIsAlive() == true)
		{
			//THE FIRST CREATURE WILL ATTACK FIRST
			system("clear");
			if (c1Array[userSelction1 - 1]->getIsAlive() == true) {

				attack = c1Array[userSelction1 - 1]->creatureAttack();
				cout << c1Array[userSelction1 - 1]->getName() << " attacks for " << attack << " damage" << endl;
				defense = c2Array[userSelction2 - 1]->creatureDefend(attack);
				cout << c2Array[userSelction2 - 1]->getName() << " defends and recieves " << defense << " damage" << endl;

				cout << endl;
			}
			if (c2Array[userSelction2 - 1]->getIsAlive() == true) {

				attack = c2Array[userSelction2 - 1]->creatureAttack();
				cout << c2Array[userSelction2 - 1]->getName() << " attacks for " << attack << " damage" << endl;
				defense = c1Array[userSelction1 - 1]->creatureDefend(attack);
				cout << c1Array[userSelction1 - 1]->getName() << " defends and recieves " << defense << " damage" << endl;

				cout << endl;
			}
			if (c2Array[userSelction2 - 1]->getIsAlive() == false) {
				cout << c2Array[userSelction2 - 1]->getName() << " has been defeated" << endl;
			}
			else if (c1Array[userSelction1 - 1]->getIsAlive() == false) {
				cout << c1Array[userSelction1 - 1]->getName() << " has been defeated" << endl;
			}
			else {
				//DISPLAY REMAINING STRENGTH IF CREATURES ARE ALIVE
				cout << endl;
				cout << "Current Strength" << endl;
				cout << c1Array[userSelction1 - 1]->getName() << " " << c1Array[userSelction1 - 1]->getStrength() << endl;
				cout << c2Array[userSelction2 - 1]->getName() << " " << c2Array[userSelction2 - 1]->getStrength() << endl;
			}
			cin.get();
		}

		cout << "Do you want to play again? [Y/N]" << endl;
		cin >> yesOrNo;
		if (yesOrNo == 'Y' || yesOrNo == 'y') {
			play = true;
		
		}
		else if (yesOrNo == 'N' || yesOrNo == 'n') {
			play = false;
		}
	} 
	//system("PAUSE");
	return 0;
}
