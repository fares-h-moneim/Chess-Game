#include "knight.h"
#include"Grid.h"
knight::knight(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/knight_white.png");
	else
		texture = LoadTexture("./resources/knight_black.png");
}

Vector2* knight::getlegalmoves(Grid* gptr)
{
	int count = 0;
	Vector2 legal[10];
	Vector2 v;
	cell* cptr = nullptr;
	v.x = x+2;
	v.y = y+1;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = x + 1;
	v.y = y + 2;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = x - 1;
	v.y = y + 2;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = x + 1;
	v.y = y - 2;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = x + 2;
	v.y = y - 1;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = x - 2;
	v.y = y + 1;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = x - 2;
	v.y = y - 1;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = x - 1;
	v.y = y - 2;
	cptr = gptr->getcell(v);
	if (cptr) {
		if (!cptr->getpiece())
			legal[count++] = v;
		else if (cptr->getpiece())
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
	}
	v.x = -1;
	v.y = -1;
	legal[count++] = v;
	return legal;
}
