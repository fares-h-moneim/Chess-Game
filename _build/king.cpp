#include "king.h"
#include"Grid.h"
king::king(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/king_white.png");
	else
		texture = LoadTexture("./resources/king_black.png");
}

Vector2* king::getlegalmoves(Grid* gptr)
{
	int count = 0;
	Vector2 legal[64];
	Vector2 v;
	cell* cptr = nullptr;
	v.x = x;
	v.y = y;
	v.x++;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = x;
	v.y = y;
	v.x--;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = x;
	v.y = y;
	v.y++;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = x;
	v.y = y;
	v.y--;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = x;
	v.y = y;
	v.x++;
	v.y--;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = x;
	v.y = y;
	v.x--;
	v.y--;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = x;
	v.y = y;
	v.x++;
	v.y++;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = x;
	v.y = y;
	v.x--;
	v.y++;
	cptr = gptr->getcell(v);
	if (cptr)
	{
		
		if (cptr->getpiece())
		{
			if (cptr->getpiece()->getteam() != team)
			{
				legal[count++] = v;
			}
		}
		else {
			legal[count++] = v;
		}
	}
	v.x = -1;
	v.y = -1;
	legal[count++] = v;
	return legal;
}
