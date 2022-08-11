#include "queen.h"

queen::queen(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/queen_white.png");
	else
		texture = LoadTexture("./resources/queen_black.png");
}