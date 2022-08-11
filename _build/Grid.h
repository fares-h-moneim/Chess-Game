#pragma once
#include"cell.h"
class Grid
{
	cell arr[8][8];
	int x = 72, y = 72;
	Texture2D texture;
public:
	Grid(Texture2D text);
	void DrawGrid();
	void mouseclicked();
	void movepiece(int xx,int yy,ChessPiece*ptr);
};

