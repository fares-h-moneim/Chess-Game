#include "rook.h"
#include"Grid.h"
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

Vector2* rook::getlegalmoves(Grid* gptr)
{
	int count = 0;
	Vector2 legal[36];
	Vector2 v;
	cell* cptr = nullptr;
	v.x = x;
	v.y = y;
	while (1)
	{
		v.x++;
		cptr = gptr->getcell(v);
		if (!cptr)
		{
			break;
		}
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
			break;
		}
		legal[count++] = v;
	}
	v.x = x;
	v.y = y;
	while (1)
	{
		v.x--;
		cptr = gptr->getcell(v);
		if (!cptr)
		{
			break;
		}
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
			break;
		}
		legal[count++] = v;
	}
	v.x = x;
	v.y = y;
	while (1)
	{
		v.y++;
		cptr = gptr->getcell(v);
		if (!cptr)
		{
			break;
		}
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
			break;
		}
		legal[count++] = v;
	}
	v.x = x;
	v.y = y;
	while (1)
	{
		v.y--;
		cptr = gptr->getcell(v);
		if (!cptr)
		{
			break;
		}
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
			break;
		}
		legal[count++] = v;
	}
	v.x = -1;
	v.y = -1;
	legal[count++] = v;
	return legal;
}
