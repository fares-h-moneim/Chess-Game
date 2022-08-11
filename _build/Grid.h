#pragma once
#include"cell.h"
class Grid
{
	cell arr[8][8];
	int x = 72, y = 72;
	Texture2D texture;
	ChessPiece* currentlyheld;
public:
	Grid(Texture2D text);
	void DrawGrid();
	void mouseclicked();
	void movepiece();
	cell getcell(Vector2 v);
};

