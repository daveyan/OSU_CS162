/*********************************************************************
** Program Filename : Stack.cpp
** Author : David Yan
** Date : 2/13/16
** Description : implementation for the stack class. this class removes
** the most recently entered node
*********************************************************************/


#include "Stack.hpp"



Stack::Stack()
{
}


Stack::~Stack()
{
}

void Stack::add(Creature *c)
{
	if (head == NULL) {
		head = new ListNode(c);
	}
	else {
		ListNode *nodePtr = head;
		while (nodePtr->next != NULL) {
			nodePtr = nodePtr->next;
		}
		nodePtr->next = new ListNode(c);
	}
}

void Stack::remove()
{

	ListNode *nodePtr = head;
	int lastValue = NULL;
	if (head->next == NULL) {
		delete head;
		head = NULL;
	}
	else {
	
		ListNode *end = head->next;
		while (end->next != NULL) {
			nodePtr = end;
			end = end->next;
		}
		delete end;
		nodePtr->next = NULL;
	}

}
