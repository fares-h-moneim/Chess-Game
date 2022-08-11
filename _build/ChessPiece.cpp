#include "ChessPiece.h"

void ChessPiece::drawpiece(int xx, int yy)
{
	DrawTexture(texture, xx, yy, WHITE);
}

Vector2 ChessPiece::getxy()
{
	Vector2 v;
	v.x = this->x;
	v.y = this->y;
	return v;
}

void ChessPiece::setxy(Vector2 v)
{
	this->x = v.x;
	this->y = v.y;
}
