#include "cell.h"

cell::cell()
{
}

void cell::setdata(int xx, int yy, std::string nme, Color color)
{
	x = xx;
	y = yy;
	name = nme;
	colour = color;
}

void cell::setpiece(ChessPiece* ptr)
{
	piece = ptr;
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
