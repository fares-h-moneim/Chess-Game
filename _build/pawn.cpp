#include "pawn.h"

pawn::pawn(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/pawn_white.png");
	else
		texture = LoadTexture("./resources/pawn_black.png");
}