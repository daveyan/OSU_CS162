/*********************************************************************
** Function: worldSwap (header)
** Description: performs a multidimensional array swap between the
** world (displayed to user) and tempWorld (holds the next generation
** cell status)
** Parameters: world, tempWorld, worldR, worldC
*********************************************************************/
#ifndef WORLDSWAP_HPP
#define WORLDSWAP_HPP

void worldSwap(char **world, char **tempWorld, int worldR, int worldC);

#endif
