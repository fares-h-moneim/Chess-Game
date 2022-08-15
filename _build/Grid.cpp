#include "Grid.h"
#include"king.h"
#include"queen.h"
#include"pawn.h"
#include"bishop.h"
#include"knight.h"
#include"rook.h"



Grid::Grid(Texture2D text)
{
	//creating team
	team = 0;
	chessmove = LoadSound("./resources/chessmove.wav");
	notchessmove= LoadSound("./resources/notchessmove.wav");
	take = LoadSound("./resources/take.wav");
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
	arr[0][7].setpiece(rookWhite1,countremoved);
	arr[7][7].setpiece(rookWhite2, countremoved);
	arr[1][7].setpiece(knightWhite1, countremoved);
	arr[6][7].setpiece(knightWhite2, countremoved);
	arr[2][7].setpiece(bishopWhite1, countremoved);
	arr[5][7].setpiece(bishopWhite2, countremoved);
	arr[3][7].setpiece(queenWhite, countremoved);
	arr[4][7].setpiece(kingWhite, countremoved);
	arr[0][0].setpiece(rookBlack1, countremoved);
	arr[7][0].setpiece(rookBlack2, countremoved);
	arr[1][0].setpiece(knightBlack1, countremoved);
	arr[6][0].setpiece(knightBlack2, countremoved);
	arr[2][0].setpiece(bishopBlack1, countremoved);
	arr[5][0].setpiece(bishopBlack2, countremoved);
	arr[3][0].setpiece(queenBlack, countremoved);
	arr[4][0].setpiece(kingBlack, countremoved);
	for (int i = 0; i < 8; i++)
	{
		arr[i][6].setpiece(pawnsWhite[i], countremoved);
		arr[i][1].setpiece(pawnsBlack[i], countremoved);
	}
	for (int i = 0; i < 10; i++)
		countremoved[i] = 0;



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
	int xx, yy;
	xx = 750;
	yy = 130;
	char c[3];
	c[1] = 'x';
	c[2]=0;
	for (int i = 0; i < 5; i++)
	{
		c[0] = countremoved[i] + 48;
		if(countremoved[i] != 0)
			DrawText(c, xx, yy, 30, WHITE);
		yy += 110;
	}
	yy = 130;
	xx = 900;
	for (int i = 5; i < 10; i++)
	{
		c[0] = countremoved[i] + 48;
		if (countremoved[i] != 0)
			DrawText(c, xx, yy, 30, BLACK);
		yy += 110;
	}
	if (team == 0) {
		std::string cur = "Currently Playing White";
		char c[24];
		for (int i = 0; i < cur.size(); i++) {
			c[i] = cur[i];
		}
		c[23] = 0;
		DrawText(c, 730, 690, 30, lightbrown);
	}
	else {
		std::string cur = "Currently Playing Black";
		char c[24];
		for (int i = 0; i < cur.size(); i++) {
			c[i] = cur[i];
		}
		c[23] = 0;
		DrawText(c, 730, 690, 30, lightbrown);
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
	

}

void Grid::movepiece(char &tm)
{
	int coorx = 0, coory = 0;
	coorx = GetMouseX();
	coory = GetMouseY();
	if (IsMouseButtonDown(0))
	{
		if (coorx > x && coorx < (x + sizex * 8) && coory>y && coory < (y + sizey * 8))
		{
			if (!currentlyheld && arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece())
			{
				if(arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece()->getteam()==tm)
				currentlyheld = arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece();
			}
			if (arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece() == currentlyheld)
				arr[(coorx - x) / sizex][(coory - y) / sizey].setpiece(nullptr, countremoved);
			
		}
		if (currentlyheld)
		{
			//to be fixed
			int arrx[36];
			int arry[36];
			if (currentlyheld->getxy().x == 6 && currentlyheld->getxy().y == 5) {
				printf("...");
			}
			Vector2* v1 = currentlyheld->getlegalmoves(this);
			int n = 0;
			int xx;
			int yy;
			
			while (v1[n].x != -1)
			{
				arrx[n] = v1[n].x;
				arry[n] = v1[n].y;
				n++;
			}
			n = 0;
			while (n<36)
			{
				DrawRectangle(arrx[n] * 72 + 72, arry[n] * 72 + 72, 72, 72, Color{ 0,158,47,125 });
				n++;
			}
			currentlyheld->drawpiece(coorx - 32, coory - 16);
		}
			
	}
	
	
	if (IsMouseButtonUp(0)&&currentlyheld)
	{
		Vector2* v1=currentlyheld->getlegalmoves(this);
		int n = 0;
		while (v1[n].x!=-1)
		{
			if(((coorx - x) / sizex)==v1[n].x&& ((coory - y) / sizey)==v1[n].y)
			{
				if (arr[(int)((coorx - x) / sizex)][(int)((coory - y) / sizey)].getpiece()) {
					PlaySound(take);
				}
				else {
					PlaySound(chessmove);
				}
				arr[(int)v1[n].x][(int)v1[n].y].setpiece(currentlyheld, countremoved);
				currentlyheld = nullptr;
				if (tm == 'w') {
					tm = 'b';
					team = 1;
				}
				else {
					tm = 'w';
					team = 0;
				}
				return;
            }
			n++;
		}
		Vector2 v=currentlyheld->getxy();
		arr[(int)v.x][(int)v.y].setpiece(currentlyheld, countremoved);
		PlaySound(notchessmove);
		currentlyheld = nullptr;
	}


}

cell* Grid::getcell(Vector2 v)
{
	if (v.x < 0 || v.x>7 || v.y < 0 || v.y>7)
		return nullptr;
	return &arr[(int)v.x][(int)v.y];
}
