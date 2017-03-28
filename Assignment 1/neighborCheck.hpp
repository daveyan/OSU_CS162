/*********************************************************************
** Function: neighborCheck (header)
** Description: checks the surrounding elements for each element to
** determine the status of the cell for the next generation. This
** is then passed to the temporary world as storage until it is swapped
** to the current world
** Parameters: world, tempWorld, worldR, worldC
*********************************************************************/
#ifndef NEIGHBORCHECK_HPP
#define NEIGHBORCHECK_HPP

void neighborCheck(char **world, char **tempWorld, int worldR, int worldC);

#endif