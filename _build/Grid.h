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
	Sound take;
	Font font;
	char team; //w white b black
	int countremoved[10]; //0 pawn 1 queen 2 bishop 3 knight 4 rook 0-4 white 5-9 black
	
	ChessPiece** teamwhite;
	ChessPiece** teamblack;
	
public:
	Grid(Texture2D text);
	void DrawGrid();
	void mouseclicked();
	bool checkmate();
	bool gamewon();
	void movepiece();
	cell* getcell(Vector2 v);
	~Grid();
};

