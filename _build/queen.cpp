#include "queen.h"
#include"Grid.h"
queen::queen(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/queen_white.png");
	else
		texture = LoadTexture("./resources/queen_black.png");
}

Vector2* queen::getlegalmoves(Grid* gptr)
{
	int count = 0;
	Vector2 legal[64];
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
	v.x = x;
	v.y = y;
	while (1)
	{
		v.x++;
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
	v.x = x;
	v.y = y;
	while (1)
	{
		v.x--;
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
	v.x = x;
	v.y = y;
	while (1)
	{
		v.x++;
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
		v.x--;
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
	v.x = -1;
	v.y = -1;
	legal[count++] = v;
	return legal;
}
