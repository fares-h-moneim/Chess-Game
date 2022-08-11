#include "knight.h"

knight::knight(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/knight_white.png");
	else
		texture = LoadTexture("./resources/knight_black.png");
}