#pragma once
#include <ctime>

using namespace std;

class Die
{
private:
	int numOfSides;
public:
	Die();
	void setDieSides(int num);
	int getDieSides();
	int rollDie();
};

