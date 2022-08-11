#include "Grid.h"





Grid::Grid(Texture2D text)
{
	//creating team
	currentlyheld = nullptr;
	texture = text;
	std::string name = "A8";
	king* kingBlack=new king('b');
	king* kingWhite = new king('w');
	queen* queenBlack=new queen('b');
	queen* queenWhite=new queen('w');
	knight* knightBlack1=new knight('b');
	knight* knightBlack2= new knight('b');
	knight* knightWhite1 = new knight('w');
	knight* knightWhite2 = new knight('w');
	rook* rookBlack1=new rook('b');
	rook* rookBlack2=new rook('b');
	rook* rookWhite1 = new rook('w');
	rook* rookWhite2 = new rook('w');
	bishop* bishopBlack1=new bishop('b');
	bishop* bishopBlack2= new bishop('b');
	bishop* bishopWhite1 = new bishop('w');
	bishop* bishopWhite2 = new bishop('w');
	pawn** pawnsWhite = new pawn * [8];
	pawn** pawnsBlack = new pawn * [8];
	for (int i = 0; i < 8; i++)
	{
		pawnsWhite[i] = new pawn('w');
		pawnsBlack[i] = new pawn('b');
	}
	// creating cells
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((j + i) % 2 == 0)
				arr[i][j].setdata(x, y, name, lightbrown);
			else
				arr[i][j].setdata(x, y, name, darkbrown);
			x += sizex;
			name[1]--;

		}
		x = 72;
		y += sizey;
		name[0]++;
		name[1]='8';
	}
	x = 72;
	y = 72;
	//positioning pieces
	arr[0][7].setpiece(rookWhite1);
	arr[7][7].setpiece(rookWhite2);
	arr[1][7].setpiece(knightWhite1);
	arr[6][7].setpiece(knightWhite2);
	arr[2][7].setpiece(bishopWhite1);
	arr[5][7].setpiece(bishopWhite2);
	arr[3][7].setpiece(queenWhite);
	arr[4][7].setpiece(kingWhite);
	arr[0][0].setpiece(rookBlack1);
	arr[7][0].setpiece(rookBlack2);
	arr[1][0].setpiece(knightBlack1);
	arr[6][0].setpiece(knightBlack2);
	arr[2][0].setpiece(bishopBlack1);
	arr[5][0].setpiece(bishopBlack2);
	arr[3][0].setpiece(queenBlack);
	arr[4][0].setpiece(kingBlack);
	for (int i = 0; i < 8; i++)
	{
		arr[i][6].setpiece(pawnsWhite[i]);
		arr[i][1].setpiece(pawnsBlack[i]);
	}



}

void Grid::DrawGrid()
{
	
	DrawTexture(texture, 0, 0, WHITE);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j].drawcell();
		}

	}

}

void Grid::mouseclicked()
{
	int xx, yy;
	ChessPiece* ptrl;
	
	if (IsMouseButtonDown(0))
	{
		xx = GetMouseX();
		yy = GetMouseY();
		if (xx > x && xx < (x + sizex * 8) && yy>y && yy < (y + sizey * 8))
		{
			if(!currentlyheld)
				currentlyheld=arr[(xx - x) / sizex][(yy - y) / sizey].getpiece();

			std::string s=arr[(xx - x) / sizex][(yy - y) / sizey].getname();
			char c[4];
			c[0] =  (xx - x) / sizex + 48;
			c[1] = ' ';
			c[2] = (yy - y) / sizey + 48;
			c[3] = 0;
			DrawText(c, 1125, 690, 30, lightbrown);
			c[0] = s[0];
			c[1] = s[1];
			c[2] = 0;
			DrawText(c, 1220, 690, 30, lightbrown);
		}
		

	}
	if (currentlyheld)
		movepiece();
	

}

void Grid::movepiece()
{
	int coorx=0, coory=0;
	coorx = GetMouseX();
	coory = GetMouseY();
	if(arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece()==currentlyheld)
		arr[(coorx - x) / sizex][(coory - y) / sizey].setpiece(nullptr);
	
	
	currentlyheld->drawpiece(coorx-32, coory-16);
	if (IsMouseButtonUp(0))
	{
		
		if (coorx > x && coorx < (x + sizex * 8) && coory>y && coory < (y + sizey * 8))
		{
			if (!arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece())
			{
				arr[(coorx - x) / sizex][(coory - y) / sizey].setpiece(currentlyheld);
				currentlyheld = nullptr;
			}
			else
			{
				Vector2 v=currentlyheld->getxy();
				arr[(int)v.x][(int)v.y].setpiece(currentlyheld);
				currentlyheld = nullptr;
			}
		}
		else
		{
			Vector2 v = currentlyheld->getxy();
			arr[(int)v.x][(int)v.y].setpiece(currentlyheld);
			currentlyheld = nullptr;
		}
	}


}

cell Grid::getcell(Vector2 v)
{

	return arr[(int)v.x][(int)v.y];
}
