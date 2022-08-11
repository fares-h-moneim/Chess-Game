#pragma once
#include"raylib.h"
class ChessPiece
{
protected:
	char team;
	//int x,y;   //cell location
	Texture2D texture;

public:
	void drawpiece(int x, int y);

};

