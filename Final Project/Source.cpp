/*********************************************************************
** Program Filename: Source.cpp
** Author: David Yan
** Date: 3/15/16
** Description: The  tester program to this project. simulates a game
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//Space and it's derived classes
#include "Space.hpp"
#include "Room.hpp"
#include "Stairs.hpp"
#include "Container.hpp"
#include "FrontDoor.hpp"

//Additional classes
#include "Item.hpp"
#include "Person.hpp"

using namespace std;

void readDesc(string s);
void readRoomDesc(Person p);
int getIndex(Space map[],string spaceName);


int main() {

	int index = 0;
	char mainMenuInput = NULL;
	char menuInput = NULL;
	char dirInput = NULL;
	bool mainMenu = true;
	bool play = true;
	int time;
	int endtime;
	int specialCount = 0;

	//CREATING AN ARRAY TO STORE ALL OF THE ROOMS
	Space *map[] = {
		new Room(),
		new Room(),
		new Room(),
		new Room(),
		new Room(),
		new Room(),
		new Room(),
		new Room(),
		new FrontDoor(),
		new Room(),
		new Stairs(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		new Container(),
		

	};
	//SPACES AND THEIR CORRESPONDING FILES AND INDEX
	Room r0("Empty", "0Empty.txt", 0);
	Room r1("Bedroom", "1Bedroom.txt", 1);
	Room r2("Hallway", "2Hallway.txt", 2);
	Room r3("Bathroom", "3Bathroom.txt", 3);
	Room r4("Bottom of Stairs", "4BStairs.txt", 4);
	Room r5("Living Room", "5LivingRoom.txt", 5);
	Room r6("Dining Room", "6DiningRoom.txt", 6);
	FrontDoor r7("Front Door", "7FrontDoor.txt", 7);
	Room r8("Outside", "8Outside.txt", 8);			

	Stairs s9("Top of Stairs", "9TStairs.txt", 9);

	Container c10("Closet", "10Closet.txt", 10);
	Container c11("Desk", "11Desk.txt", 11);
	Container c12("Computer", "12Computer.txt", 12);
	Container c13("Grandfather Clock", "13GClock.txt", 13);
	Container c14("Medicine Cabinet", "14MCabinet.txt", 14);
	Container c15("Toilet", "15Toilet.txt", 15);
	Container c16("Bathtub", "16Btub.txt", 16);
	Container c17("Lamp", "17Lamp.txt", 17);
	Container c18("Cactus", "18Cactus.txt", 18);
	Container c19("Console Table", "19CSTable.txt", 19);
	Container c20("Coffee Table", "20CTable.txt", 20);
	Container c21("Kitchen Table", "21KTable.txt", 21);
	Container c22("Oven", "22Oven.txt", 22);
	Container c23("Garbage Can", "23GCan.txt", 23);

	//CREATING SOME ITEMS. "" means that no names were given - hence will not be used in the game
	Item i10("Jacket");
	Item i11("Old Pizza Slice");
	Item i12("");
	Item i13("");
	Item i14("");
	Item i15("");
	Item i16("Rubber Ducky");
	Item i17("");
	Item i18("Cactus Needle");
	Item i19("Dust Bunny");
	Item i20("");
	Item i21("");
	Item i22("Wallet");
	Item i23("Trash");

	//SETTING UP ITEMS IN THEIR CONTAINERS
	c10.setItem(i10);
	c11.setItem(i11);
	c12.setHasItem(false);
	c13.setHasItem(false);
	c14.setHasItem(false);
	c15.setHasItem(false);
	c16.setItem(i16);
	c17.setHasItem(false);
	c18.setItem(i18);
	c19.setItem(i19);
	c20.setHasItem(false);
	c21.setHasItem(false);
	c22.setItem(i22);
	c23.setItem(i23);
	//MAP SET UP

	//MAP SECTIONS
	map[0] = &r0;
	map[1] = &r1;
	map[2] = &r2;
	map[3] = &r3;
	map[4] = &r4;
	map[5] = &r5;
	map[6] = &r6;
	map[7] = &r7;
	map[8] = &r8;
	map[9] = &s9;
	map[10] = &c10;
	map[11] = &c11;
	map[12] = &c12;
	map[13] = &c13;
	map[14] = &c14;
	map[15] = &c15;
	map[16] = &c16;
	map[17] = &c17;
	map[18] = &c18;
	map[19] = &c19;
	map[20] = &c20;
	map[21] = &c21;
	map[22] = &c22;
	map[23] = &c23;

	//SET UP ROOMS
	map[1]->setUp(map[10]);
	map[1]->setLeft(map[11]);
	map[1]->setDown(map[2]);
	map[1]->setRight(map[12]);

	map[2]->setUp(map[1]);
	map[2]->setLeft(map[13]);
	map[2]->setDown(map[3]);
	map[2]->setRight(map[9]);

	map[3]->setUp(map[2]);
	map[3]->setLeft(map[14]);
	map[3]->setDown(map[15]);
	map[3]->setRight(map[16]);

	map[4]->setUp(map[17]);
	map[4]->setLeft(map[5]);
	map[4]->setDown(map[18]);
	map[4]->setRight(map[19]);

	map[5]->setUp(map[7]);
	map[5]->setLeft(map[20]);
	map[5]->setDown(map[6]);
	map[5]->setRight(map[4]);

	map[6]->setUp(map[5]);
	map[6]->setLeft(map[21]);
	map[6]->setDown(map[22]);
	map[6]->setRight(map[23]);

	map[7]->setUp(map[7]);
	map[7]->setLeft(map[0]);
	map[7]->setDown(map[5]);
	map[7]->setRight(map[0]);

	map[8]->setUp(map[0]);
	map[8]->setLeft(map[0]);
	map[8]->setDown(map[0]);
	map[8]->setRight(map[0]);

	map[9]->setUp(map[0]);
	map[9]->setLeft(map[2]);
	map[9]->setDown(map[0]);
	map[9]->setRight(map[0]);

	map[10]->setUp(map[0]);
	map[10]->setLeft(map[0]);
	map[10]->setDown(map[0]);
	map[10]->setRight(map[0]);

	map[11]->setUp(map[0]);
	map[11]->setLeft(map[0]);
	map[11]->setDown(map[0]);
	map[11]->setRight(map[0]);

	map[12]->setUp(map[0]);
	map[12]->setLeft(map[0]);
	map[12]->setDown(map[0]);
	map[12]->setRight(map[0]);

	map[13]->setUp(map[0]);
	map[13]->setLeft(map[0]);
	map[13]->setDown(map[0]);
	map[13]->setRight(map[0]);

	map[14]->setUp(map[0]);
	map[14]->setLeft(map[0]);
	map[14]->setDown(map[0]);
	map[14]->setRight(map[0]);

	map[15]->setUp(map[0]);
	map[15]->setLeft(map[0]);
	map[15]->setDown(map[0]);
	map[15]->setRight(map[0]);

	map[16]->setUp(map[0]);
	map[16]->setLeft(map[0]);
	map[16]->setDown(map[0]);
	map[16]->setRight(map[0]);

	map[17]->setUp(map[0]);
	map[17]->setLeft(map[0]);
	map[17]->setDown(map[0]);
	map[17]->setRight(map[0]);

	map[18]->setUp(map[0]);
	map[18]->setLeft(map[0]);
	map[18]->setDown(map[0]);
	map[18]->setRight(map[0]);

	map[19]->setUp(map[0]);
	map[19]->setLeft(map[0]);
	map[19]->setDown(map[0]);
	map[19]->setRight(map[0]);

	map[20]->setUp(map[0]);
	map[20]->setLeft(map[0]);
	map[20]->setDown(map[0]);
	map[20]->setRight(map[0]);

	map[21]->setUp(map[0]);
	map[21]->setLeft(map[0]);
	map[21]->setDown(map[0]);
	map[21]->setRight(map[0]);

	map[22]->setUp(map[0]);
	map[22]->setLeft(map[0]);
	map[22]->setDown(map[0]);
	map[22]->setRight(map[0]);

	map[23]->setUp(map[0]);
	map[23]->setLeft(map[0]);
	map[23]->setDown(map[0]);
	map[23]->setRight(map[0]);

	Person p;



	while (mainMenu == true) {
		system("clear");

		time = 10;
		endtime = 30;
		play = true;

		

		p.setPosition(*map[1]);
		p.emptyPockets();
		//MAIN MENU
		std::cout << "THE STRUGGLE" << endl;
		std::cout << "\t based on a true story" << endl;
		std::cout << endl;
		std::cout << "" << endl;
		std::cout << "[P]lay the game" << endl;
		std::cout << "[C]redits" << endl;
		std::cout << "[E]xit" << endl << endl;
		std::cout << "Enter the charater that corresponds to the menu item" << endl;
		std::cin >> mainMenuInput;

		//PLAY THE GAME
		if (mainMenuInput == 'P' || mainMenuInput == 'p') {
			//READING THE INTRO MATERIAL
			system("clear");
			readDesc("Instructions.txt");
			std::cin.ignore();
			std::cin.get();
		
			system("clear");
			readDesc("Plot.txt");
			
			std::cin.get();

			system("clear");
			readDesc("Intro.txt");
			std::cin.get();

			//RUNNING ACTUAL GAME
			while (play == true) {
				
				mainMenuInput = NULL;
	

				//THERE IS STILL TIME
				if (time < endtime) {
					system("clear");
					std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
					readRoomDesc(p);
					std::cout << endl;


					//Current Position is a room
					if (p.getPosition().getRoomType() == 1) {
						std::cout << "[Player Options]\n" << endl;
						std::cout << "[P]ocket		:Check your inventory" << endl;
						std::cout << "[L]ook			:Look around to see the surrounding space" << endl;
						std::cout << "[B]luePrint		:View a map of your apartment" << endl;
						std::cout << "[M]ove			:Move to a new location" << endl << endl;
						if (specialCount < 4 && (time % 3 == 0)) {			//ROOMS SPECIALS APPEAR ONLY AT TIMES WITH MULTIPLES OF 3
							std::cout << "[S]pecial		:It's a suprise" << endl << endl;
						}
						std::cout << "What are you going to do? ";

						std::cin >> menuInput;

						//VIEW ITEMS IN POCKET
						if (menuInput == 'P' || menuInput == 'p') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							p.viewPocket();
							std::cin.ignore();
							std::cin.get();
						}
						//LOOK AROUND TO VIEW ALL AVAILABLE SPACES
						if (menuInput == 'L' || menuInput == 'l') {

							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							readDesc("look.txt");
							std::cout << endl;
							p.viewSpaces(map);
							std::cin.ignore();
							std::cin.get();
						}
						//MOVE FROM CURRENT POSITION
						if (menuInput == 'M' || menuInput == 'm') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							p.displayMoveOptions(map);

							std::cout << "Where would you like to go? ";
							std::cin >> dirInput;
							p.moveChar(dirInput);
							if (p.getPosition().getRoomType() == 1) {
								time++;
							}
						}
						//VIEW A MAP OF THE LOCATION
						if (menuInput == 'B' || menuInput == 'b') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							readDesc("map.txt");
							std::cin.ignore();
							std::cin.get();
						}
						//SPECIAL
						if (menuInput == 'S' || menuInput == 's') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							//ROOMS ADD ADDITIONAL TIME TO THE GAME
							endtime += map[p.getPosition().getIndex()]->special(specialCount);
							time++;
							specialCount++;	//HOWEVER SPECIALS CAN ONLY BE USED 4 TIMES

						}
					}
					//Current Position is a container
					if (p.getPosition().getRoomType() == 2) {
						system("clear");

						std::cout << "[Current Position] " << p.getPosition().getName() << "\t Time: 8:" << time << endl << endl;
						readRoomDesc(p);
						cout << endl;
						std::cout << "[Player Options]\n" << endl;
						std::cout << "[S]earch		:Search around the point of interest" << endl;
						std::cout << "[R]eturn		:Go back to the room you were in" << endl;

						std::cout << endl;
						if (specialCount < 4 && (time % 4 == 0)) {		//CONTAINER SPECIALS APPEAR LESS OFTEN
							std::cout << "S[P]ecial		:It's a suprise" << endl << endl;
						}

						std::cout << "What are you going to do? ";
						std::cin >> menuInput;

						//SEARCH THE CONTAINER FOR ITEMS
						if (menuInput == 'S' || menuInput == 's') {
							system("clear");

							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							p.lookForItems();
							//IF THERE IS AN ITEM ADD IT TO POCKET
							if (p.getPosition().getHasItem() == true) {
								std::cout << endl;
								p.addToPocket(p.getPosition().getItem());
								//MARK CONTAINER AS EMPTY
								map[p.getPosition().getIndex()]->setHasItem(false);
							}
							std::cin.ignore();
							std::cin.get();
						}
						//RETURN TO PREVIOUS LOCATION - THIS WILL "BE A ROOM
						if (menuInput == 'R' || menuInput == 'r') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							p.setPosition(p.getLastPosition());
						}
						//CONTAINER SPECIALS ARE DENOTED WITH A P INSTEAD OF AN S
						if (menuInput == 'P' || menuInput == 'p') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							//WASTES GAME TIME TO USER
							time += map[p.getPosition().getIndex()]->special(specialCount);
							std::cin.ignore();
							std::cin.get();

						}
					}
					//Current Position is a stair
					if (p.getPosition().getRoomType() == 3) {
						system("clear");

						std::cout << "[Current Position] " << p.getPosition().getName() << "\t Time: 8:" << time << endl << endl;
						readRoomDesc(p);
						std::cout << endl;
						std::cout << "[Player Options]\n" << endl;
						std::cout << "[P]ocket		:Check your inventory" << endl;
						std::cout << "[L]ook			:Look around to see the surrounding space" << endl;
						std::cout << "[B]luePrint		:View a map of your apartment" << endl;
						std::cout << "[M]ove			:Move to a new location" << endl << endl;
						std::cout << "What are you going to do? ";
						std::cin >> menuInput;

						//DOESNT MATTER WHAT THE USER CHOOSES, THEY'RE GOING TO FALL DOWN
						if (menuInput == 'P' || menuInput == 'p' || menuInput == 'L' || menuInput == 'l' || menuInput == 'M' || menuInput == 'm' || menuInput == 'B' || menuInput == 'b') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\t Time: 8:" << time << endl << endl;
							time += map[p.getPosition().getIndex()]->special(specialCount);
							std::cin.ignore();
							std::cin.get();
							p.setPosition(*map[4]);			//BOTTOM OF STAIRS

						}
					}
					//Current Positiom is a frontdoor
					if (p.getPosition().getRoomType() == 4) {
						system("clear");

						std::cout << "[Current Position] " << p.getPosition().getName() << "\t Time: 8:" << time << endl << endl;
						readRoomDesc(p);
						std::cout << endl;
						std::cout << "[Player Options]\n" << endl;
						std::cout << "[O]pen Door		:Open the door and let the pizza guy in! Duh!" << endl;
						std::cout << "[R]eturn		:Go back to the room you were in" << endl;
						std::cout << endl;
						std::cout << "What are you going to do? ";

						std::cin >> menuInput;

						//OPEN THE DOOR TO COMPLETE THE GAME
						if (menuInput == 'O' || menuInput == 'o') {
							if (p.checkForItem("Wallet") == 1) {
								system("clear");
								//IF PERSON HAS WALLET, THEN THEY WIN (OR LOSE)
								std::cout << "[Current Position] " << p.getPosition().getName() << "\t Time: 8:" << time << endl << endl;
								map[p.getPosition().getIndex()]->special(1);
								//ARBITARY SCORE BASED ON ITEMS
								std::cout << "\n[Score] : "<<(p.getPocketSize()*10)+30<<"/100" << endl;
								std::cin.ignore();
								std::cin.get();
								play = false;
							}
							else {
								system("clear");
								std::cout << "[Current Position] " << p.getPosition().getName() << "\t Time: 8:" << time << endl << endl;
								//map[p.getPosition().getIndex()]->special(0);
								//std::cout << "\n[Score] : 0/100" << endl;

								//INFORMING PLAYER TO COMPLETE GAME REQUIREMENTS
								std::cout << "You can't leave yet, you don't have your \"Wallet\""<<endl; 
								std::cin.ignore();
								std::cin.get();
								//play = false;
							}
						}
						//RETURN TO PREVIOUS ROOM
						if (menuInput == 'R' || menuInput == 'r') {
							system("clear");
							std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
							p.setPosition(p.getLastPosition());
						}
					}
				}
				//TIME IS UP. GAMEOVER
				else {
					system("clear");
					std::cout << "[Current Position] " << p.getPosition().getName() << "\tTime: 8:" << time << endl << endl;
					readDesc("gameover.txt");
					std::cin.ignore();
					std::cin.get();
					play = false;
				}
			}
		}
		//CREDITS
		if (mainMenuInput == 'C' || mainMenuInput == 'c') {
			system("clear");

			std::cout << "[Credits]" << endl << endl;
			std::cout << "[Producer]" << endl;
			std::cout << "David Yan" << endl;
			std::cout << "[Project Lead]" << endl;
			std::cout << "David Yan" << endl;
			std::cout << "[Story Writer]" << endl;
			std::cout << "David Yan" << endl;
			std::cout << "[Level Design]" << endl;
			std::cout << "David Yan" << endl;
			std::cout << "[Map Design]" << endl;
			std::cout << "David Yan" << endl;
			std::cout << "[Quality Assurance]" << endl;
			std::cout << "David Yan" << endl;
			std::cout << "[Life Story]" << endl;
			std::cout << "Anthony C." << endl;		//BASED ON A TRUE STORY
			std::cout << "[Cast]" << endl;
			std::cout << "You (the player)" << endl;
			std::cout << "Pizza Guy" << endl;
			std::cout << "Mickey" << endl;
			std::cout << "Ricky" << endl;
			std::cout << "Granny" << endl;
			std::cout << "American Citzen" << endl;
			std::cout << "The NYPD" << endl;

			std::cin.ignore();
			std::cin.get();
		}
		//EXIT PROGRAM
		if (mainMenuInput == 'E' || mainMenuInput == 'e') {
			system("clear");
			std::cout << "Exiting program. Goodbye" << endl;
			mainMenu = false;
		}
	}
//	system("PAUSE");
	return 0;
}
/*********************************************************************
** Function: readRoomDect
** Description: reads the txt file associated with the room pased on the
** person p
** Parameters: persons p - for the location
*********************************************************************/
void readRoomDesc(Person p)
{
	
	ifstream ifs;
		ifs.open(p.getPosition().getFileName());
		string textString;
		if (ifs.good()) {
			while (getline(ifs, textString)) {
				std::cout << textString << '\n';
			
			}
		}
}
/*********************************************************************
** Function: getIndex
** Description: returns the space index
** Parameters: the array of spaces and the space name
*********************************************************************/
int getIndex(Space map[], string sName)
{
	for (int i = 0; i < 6; i++) {
		if (map[i].getName() == sName)
			return i;
	}
	return 0;

}
/*********************************************************************
** Function: readDesc
** Description: reads a file based on the given string
** Parameters: string s
*********************************************************************/
void readDesc(string s)
{

	ifstream ifs;
	ifs.open(s);
	string textString;
	if (ifs.good()) {
		while (getline(ifs, textString)) {
			std::cout << textString << '\n';

		}
	}
}
