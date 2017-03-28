#include "List.hpp"

#include<iostream>

using namespace std;


List::List()
{
	head = NULL;
}


List::~List()
{
	ListNode *nodePtr = head;
	while (nodePtr != NULL) {
		ListNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}




void List::add(Creature *c1)
{
}

void List::remove()
{

}

void List::printList()
{

		ListNode *nodePtr = head;
		while (nodePtr) {
			cout << nodePtr->c->getNickName() << " ";
			nodePtr = nodePtr->next;
		}
		cout << endl;
}

void List::printWins()
{
	ListNode *nodePtr = head;
	while (nodePtr) {
		for (int i = 0; i < 3; i++) {
			cout << "Rank " << i + 1 << " " << nodePtr->c->getNickName() << " hails from Team Number  " << nodePtr->c->getTeamNum() << endl;
			nodePtr = nodePtr->next;
		}
	}
	cout << endl;
}

List::ListNode List::getHead()
{
	if (head == NULL) {
		cout << "";
	}
	else {
		return *head;
	}
}



