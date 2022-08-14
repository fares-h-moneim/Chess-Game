#pragma once
#include<string>
#include"raylib.h"

#define lightbrown Color{222,211,157,255}
#define darkbrown Color{101,67,33,255}
const int sizex = 72;
const int sizey = 72;
class ChessPiece;
class cell
{
	int x, y;
	Color colour;
	ChessPiece* piece = nullptr;
	std::string name;


public:
	cell();
	void setdata(int xx, int yy, std::string nme, Color color);
	void setpiece(ChessPiece* ptr,int arr[]);
	ChessPiece* getpiece();
	void drawcell();
	std::string getname();

};

