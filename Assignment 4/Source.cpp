/*********************************************************************
** Program Filename: Source.cpp
** Author: David Yan 
** Date: 2/28/16
** Description: Runs a tournament style combat system with various creatures
*********************************************************************/
#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>

/*Creatures*/
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "Die.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
/*List*/
#include "List.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;




int main() {

	srand(time(NULL));
	List *l1, *l2, *l3, *l4;

	Queue q1, q2;
	l1 = &q1; //player 1 creature queue
	l2 = &q2; //player 2 creature queue

	Stack s1, s2;
	l3 = &s1; //Loser Stack
	l4 = &s2; //Ranking
	
	int t1score = 0;	//team 1 score
	int t2score = 0;	//team 2 score
	//creature attack variables
	int attack;
	int defense;

	int rankplace = 0;

	int totalCreatures;

	int userSelection1;

	int remainingCreatures1;
	int remainingCreatures2;
	
	/*Abstract creature arrays for each player*/
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

	system("clear");
		
	cout << "How many creatures will fight in this tournament [2-5] " << endl;
	cin >> totalCreatures;

	//set up the counter for the tournament
	remainingCreatures1 = remainingCreatures2 = totalCreatures;

	//PLAYER 1 TURN
	system("clear");
	cout << "Player 1 Selection" << endl;
	usleep(1000000);

	for (int i = 0; i < totalCreatures; i++) {
		string nickName;

		system("clear");

		cout << "Select Creature Number " << i + 1 << endl;

		cout << "Remaining Creatures" << endl;
		for (int j = 0; j < 5; j++) {
			if (c1Array[j]->getNickName() == "NULL") {
				//creatures default nickname is NULL. if it isn't NULL, it means that it has already been chosen by the user

				cout << j + 1 << " " << c1Array[j]->getName() << endl;
			}
		}
		cout << "Enter a number between 1-5" << endl;

		cin >> userSelection1;
	
				
		cout << "Please name your creature" << endl;
		cin.ignore();
		getline(cin, nickName);
		//initailizng some elements of the creature
		c1Array[userSelection1 - 1]->setNickName(nickName);
		c1Array[userSelection1 - 1]->setTeamNum(1);

		//Adding the creature to the players array
		q1.add(c1Array[userSelection1 - 1]);
		cout << c1Array[userSelection1 - 1]->getNickName() << " the " << c1Array[userSelection1 - 1]->getName();
		cout << " has entered the arena" << endl;
		usleep(1000000);
	}

	//PLAYER 2 TURN
	system("clear");
	cout << "Player 2 Selection" << endl;
	usleep(1000000);

	for (int i = 0; i < totalCreatures; i++) {
		string nickName;

		system("clear");
		cout << "Select Creature Number " << i + 1 << endl;
		cout << "Remaining Creatures" << endl;
		for (int j = 0; j < 5; j++) {
			if (c2Array[j]->getNickName() == "NULL") {
				cout << j + 1 << " " << c2Array[j]->getName() << endl;
			}
		}
		cout << "Enter a number between 1-5" << endl;

		cin >> userSelection1;
	

		cout << "Please name your creature" << endl;
		cin.ignore();
		getline(cin, nickName);

		c2Array[userSelection1 - 1]->setNickName(nickName);
		c2Array[userSelection1 - 1]->setTeamNum(2);

		q2.add(c2Array[userSelection1 - 1]);
		cout << c2Array[userSelection1 - 1]->getNickName() << " the " << c2Array[userSelection1 - 1]->getName();
		cout << " has entered the arena" << endl;
		usleep(1000000);
	}


	while (q1.getHead().c->getIsAlive() == true && q2.getHead().c->getIsAlive() == true && remainingCreatures1 >0 && remainingCreatures2 >0)
	{
		system("clear");
		if (q1.getHead().c->getIsAlive() == true) {
			//fighting sequence
			attack = q1.getHead().c->creatureAttack();
			cout << q1.getHead().c->getNickName() << " attacks for " << attack << " damage" << endl;
			defense = q2.getHead().c->creatureDefend(attack);
			cout << q2.getHead().c->getNickName() << " defends and recieves " << defense << " damage" << endl;
			cout << q2.getHead().c->getNickName() << " Stength: " << q2.getHead().c->getStrength() << endl;
			cout << endl;
		}
		if (q2.getHead().c->getIsAlive() == true) {

			attack = q2.getHead().c->creatureAttack();
			cout << q2.getHead().c->getNickName() << " attacks for " << attack << " damage" << endl;
			defense = q1.getHead().c->creatureDefend(attack);
			cout << q1.getHead().c->getNickName() << " defends and recieves " << defense << " damage" << endl;
			cout << q1.getHead().c->getNickName() << " Strength: " << q1.getHead().c->getStrength() << endl;
			cout << endl;
		}
		//DEFEAT AND VICTORY 
		if (q2.getHead().c->getIsAlive() == false) {
			cout << q2.getHead().c->getNickName() << " has been defeated" << endl;
			s1.add(q2.getHead().c);
			q2.remove();
			t1score++;
			cout << q1.getHead().c->getNickName() << " won! " <<endl;
			q1.getHead().c->recover();

			q1.add(q1.getHead().c);
			q1.remove();
			remainingCreatures2--;
;
		}
		if (q1.getHead().c->getIsAlive() == false) {
			cout << q1.getHead().c->getNickName() << " has been defeated" << endl;
			s1.add(q1.getHead().c);
			q1.remove();
			t2score++;
			cout << q2.getHead().c->getNickName() << " won! " << endl;
			q2.getHead().c->recover();

			q2.add(q2.getHead().c);
			q2.remove();
			remainingCreatures1--;

		}
	

		usleep(1000000);
	}
	system("clear");
	cout << "Pile of losers" << endl;
	s1.printList();
	cin.get();

	system("clear");
	/*End results*/
	if (remainingCreatures1 == 0) {
		cout << "Player 2 wins" << endl;
	//adding the winner queue to the rank stack
		while (remainingCreatures2 > 0 && rankplace <3) {
			s2.add(q2.getHead().c);
			q2.remove();
			remainingCreatures2--;
			rankplace++;
		}
	//adding members from the loser stack to the rank stack
		while (rankplace < 3) {
			s2.add(s1.getHead().c);
			s1.remove();
			rankplace++;
		}
	
	}
	else if (remainingCreatures2 == 0) {
		cout << "Player 1 wins" << endl;
		while (remainingCreatures1 > 0 && rankplace <3) {
			s2.add(q1.getHead().c);
			q1.remove();
			remainingCreatures1--;
			rankplace++;
		}
		while (rankplace < 3) {
			s2.add(s1.getHead().c);
			s1.remove();
			
			rankplace++;
		}
		
	}
	cout <<"Team 1 score: " << t1score << endl;
	cout <<"Team 2 score: " << t2score << endl << endl; 	
	s2.printWins();



	return 0;
}
