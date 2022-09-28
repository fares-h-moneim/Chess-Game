#include "cell.h"
#include"king.h"
#include"queen.h"
#include"pawn.h"
#include"bishop.h"
#include"knight.h"
#include"rook.h"
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

void cell::setpiece(ChessPiece* ptr,int arr[])
{
	if (piece != ptr && piece != nullptr&&ptr)
	{
		int num = 0;
		if (piece->getteam() == 'b')
			num += 5;
		if (dynamic_cast<rook*>(piece))
			num += 4;
		if (dynamic_cast<knight*>(piece))
			num += 3;
		if (dynamic_cast<bishop*>(piece))
			num += 2;
		if (dynamic_cast<queen*>(piece))
			num += 1;
		arr[num]++;
	}
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

void cell::removepiece()
{
	piece = nullptr;
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
