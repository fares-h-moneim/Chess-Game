#include "Grid.h"





Grid::Grid(Texture2D text)
{
	//creating team
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
	arr[7][0].setpiece(rookWhite1);
	arr[7][7].setpiece(rookWhite2);
	arr[7][1].setpiece(knightWhite1);
	arr[7][6].setpiece(knightWhite2);
	arr[7][2].setpiece(bishopWhite2);
	arr[7][5].setpiece(bishopWhite2);
	arr[7][3].setpiece(queenWhite);
	arr[7][4].setpiece(kingWhite);
	arr[0][0].setpiece(rookBlack1);
	arr[0][7].setpiece(rookBlack2);
	arr[0][1].setpiece(knightBlack1);
	arr[0][6].setpiece(knightBlack2);
	arr[0][2].setpiece(bishopBlack2);
	arr[0][5].setpiece(bishopBlack2);
	arr[0][3].setpiece(queenBlack);
	arr[0][4].setpiece(kingBlack);
	for (int i = 0; i < 8; i++)
	{
		arr[6][i].setpiece(pawnsWhite[i]);
		arr[1][i].setpiece(pawnsBlack[i]);
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
			/*ptrl=arr[(xx - x) / sizex][(yy - y) / sizey].getpiece();
			if (ptrl)
			{
				movepiece(xx, yy, ptrl);
			}*/
			std::string s=arr[(xx - x) / sizex][(yy - y) / sizey].getname();
			char c[4];
			c[0] =  (yy - y) / sizey + 48;
			c[1] = ' ';
			c[2] = (xx - x) / sizex + 48;
			c[3] = 0;
			DrawText(c, 1125, 690, 30, lightbrown);
			c[0] = s[0];
			c[1] = s[1];
			c[2] = 0;
			DrawText(c, 1220, 690, 30, lightbrown);
		}
		

	}

}

void Grid::movepiece(int xx, int yy, ChessPiece* ptr)
{
	int coorx=0, coory=0;
	arr[(xx - x) / sizex][(yy - y) / sizey].setpiece(nullptr);
	while (IsMouseButtonDown(0))
	{
		coorx = GetMouseX();
		coory = GetMouseY();
		//ptr->drawpiece(coorx, coory);
	}
	if (coorx > x && coorx < (x + sizex * 8) && coory>y && coory < (y + sizey * 8))
	{
		arr[(coorx - x) / sizex][(coory - y) / sizey].setpiece(ptr);
		ptr->drawpiece(coorx, coory);

	}
	else
	{
		arr[(xx - x) / sizex][(yy - y) / sizey].setpiece(ptr);
	}


}
