/*********************************************************************
** Function: destroyWorld
** Description: final function to deallocate the dynamic memory used
** Parameters: world, tempWorld
*********************************************************************/
#include "destroyWorld.hpp"

void destroyWorld(char **world, char **tempWorld)
{

	delete[] world;
	delete[] tempWorld;
}