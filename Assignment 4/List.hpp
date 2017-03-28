/*********************************************************************
** Program Filename : List.hpp
** Author : David Yan
** Date : 2/13/16
** Description : Header file for the Base class "List" for the 
** two derived Queue and Stack
*********************************************************************/

#pragma once
#include <iostream>
#include "Creature.hpp"
using namespace std;


class List
{
protected:
	struct ListNode {
		Creature *c;
		ListNode *next;
		ListNode(Creature *c1, ListNode *next1 = NULL) {
			c = c1;
			next = next1;
		}
	};
	ListNode *head;
public:
	List();
	~List();
	void add(Creature *c1);
	void remove();
	void printList();

	void printWins();
	
	ListNode getHead();
};

