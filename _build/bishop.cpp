#include "bishop.h"

bishop::bishop(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/bishop_white.png");
	else
		texture = LoadTexture("./resources/bishop_black.png");
}