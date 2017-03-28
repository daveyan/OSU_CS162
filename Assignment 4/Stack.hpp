#pragma once
#include "List.hpp"

#include <iostream>

using namespace std;

class Stack :
	public List
{
public:
	Stack();
	~Stack();
	void add(Creature *c);
	void remove();
};

