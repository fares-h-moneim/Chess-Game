#include "pawn.h"
#include"Grid.h"
pawn::pawn(char c)
{
	team = c;
	if (c == 'w')
		texture = LoadTexture("./resources/pawn_white.png");
	else
		texture = LoadTexture("./resources/pawn_black.png");
}

Vector2* pawn::getlegalmoves(Grid* gptr)
{
	int count = 0;
	Vector2 legal[8];
	Vector2 v;
	cell* cptr = nullptr;
	first = false;
	if (y == 6 && team == 'w')
		first = true;
	if (y == 1 && team == 'b')
		first = true;
	if (team == 'b')
	{
		if (first)
		{

			v.x = x;
			v.y = y + 1;
			legal[count++] = v;
			v.x = x;
			v.y = y + 2.0;
			legal[count++] = v;
			v.x = -1.0;
			v.y = -1.0;
			legal[count++] = v;
			first = false;
			//Mody on da code
		}
		else
		{
			v.x = x;
			v.y = y + 1;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (!cptr->getpiece())
					legal[count++] = v;
			}
			v.x = x + 1;
			v.y = y + 1;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						legal[count++] = v;
					}
			}
			v.x = x - 1;
			v.y = y + 1;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						legal[count++] = v;
					}
			}
			v.x = x + 1;
			v.y = y;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						v.x = x + 1;
						v.y = y + 1;
						legal[count++] = v;
					}
			}
			v.x = x - 1;
			v.y = y;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						v.x = x - 1;
						v.y = y + 1;
						legal[count++] = v;
					}
			}
			v.x = -1.0;
			v.y = -1.0;
			legal[count++] = v;
		}
	}
	else
	{
		if (first)
		{

			v.x = x;
			v.y = y - 1;
			legal[count++] = v;
			v.x = x;
			v.y = y - 2;
			legal[count++] = v;
			v.x = -1.0;
			v.y = -1.0;
			legal[count++] = v;
			first = false;
			//Mody on da code
		}
		else
		{
			v.x = x;
			v.y = y - 1;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (!cptr->getpiece())
					legal[count++] = v;
			}
			v.x = x + 1;
			v.y = y - 1;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						legal[count++] = v;
					}
			}
			v.x = x - 1;
			v.y = y - 1;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						legal[count++] = v;
					}
			}
			v.x = x + 1;
			v.y = y;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						v.x = x + 1;
						v.y = y - 1;
						legal[count++] = v;
					}
			}
			v.x = x - 1;
			v.y = y;
			cptr = gptr->getcell(v);
			if (cptr)
			{
				if (cptr->getpiece())
					if (cptr->getpiece()->getteam() != team)
					{
						v.x = x - 1;
						v.y = y - 1;
						legal[count++] = v;
					}
			}
			v.x = -1.0;
			v.y = -1.0;
			legal[count++] = v;
		}
		
	}
	return legal;
}
