#pragma once
#include "List.hpp"

class Queue :
	public List
{
public:
	Queue();
	~Queue();
	void add(Creature *c);
	void remove();
};

