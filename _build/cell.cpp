#include "cell.h"

cell::cell()
{
}

void cell::setdata(int xx, int yy, std::string nme, Color color)
{
	y = xx;
	x = yy;
	name = nme;
	colour = color;
}

void cell::setpiece(ChessPiece* ptr)
{
	piece = ptr;
	if (ptr != nullptr)
	{
	Vector2 v;
	v.x = (this->x-72)/sizex;
	v.y = (this->y-72)/sizey;
	piece->setxy(v);
    }
}

ChessPiece* cell::getpiece()
{
	return piece;
}

void cell::drawcell()
{
	DrawRectangle(x, y, sizex, sizey, colour);
	if (piece)
		piece->drawpiece(x, y);
}

std::string cell::getname()
{
	return name;
}
