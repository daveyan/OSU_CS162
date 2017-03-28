/*********************************************************************
** Program Filename : Queue.cpp
** Author : David Yan
** Date : 2/13/16
** Description : implementation for the queue class. this class removes
** the first item in the list when called upon
*********************************************************************/


#include "Queue.hpp"



Queue::Queue()
{
	head = NULL;
}


Queue::~Queue()
{
}

void Queue::add(Creature *c)
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

void Queue::remove()
{
	ListNode *nodePtr = head;
	int firstValue = NULL;

	if (head->next == NULL) {
		delete head;
		head = NULL;	
	}
	else {
		ListNode *rear;
		rear = head->next;
		delete head;
		head = rear;
	}

}
