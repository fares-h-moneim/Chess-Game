#pragma once
#include"raylib.h"
class ChessPiece
{
protected:
	char team;
	int x=-1,y=-1;   //cell location
	Texture2D texture;

public:
	void drawpiece(int xx, int yy);
	Vector2 getxy();
	void setxy(Vector2 v);

};

