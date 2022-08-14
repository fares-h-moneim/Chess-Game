#pragma once
#include"cell.h"
class Grid
{
	cell arr[8][8];
	int x = 72, y = 72;
	Texture2D texture;
	ChessPiece* currentlyheld;
	Sound chessmove;
	Sound notchessmove;
	int countremoved[10]; //0 pawn 1 queen 2 bishop 3 knight 4 rook 0-4 white 5-9 zengi
	
public:
	Grid(Texture2D text);
	void DrawGrid();
	void mouseclicked();
	void movepiece(char &tm);
	cell* getcell(Vector2 v);
};

