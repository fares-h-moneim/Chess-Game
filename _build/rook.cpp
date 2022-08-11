#include "rook.h"

rook::rook(char c)
{
	team = c;
	if (team == 'w')
	{
		texture = LoadTexture("./resources/rook_white.png");
	}
	else
		texture = LoadTexture("./resources/rook_black.png");
}
