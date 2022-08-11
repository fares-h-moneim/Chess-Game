#include "king.h"

king::king(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/king_white.png");
	else
		texture = LoadTexture("./resources/king_black.png");
}
