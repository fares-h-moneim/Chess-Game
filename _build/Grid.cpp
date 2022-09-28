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
	team = 'w';
	chessmove = LoadSound("./resources/chessmove.wav");
	notchessmove= LoadSound("./resources/notchessmove.wav");
	take = LoadSound("./resources/take.wav");
	currentlyheld = nullptr;
	texture = text;
	teamwhite = new ChessPiece * [16];
	teamblack = new ChessPiece * [16];
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
		teamwhite[i] = pawnsWhite[i];
		pawnsBlack[i] = new pawn('b');
		teamblack[i] = pawnsBlack[i];
	}
	teamwhite[8] = rookWhite1;
	teamwhite[9] = rookWhite2;
	teamwhite[10] = bishopWhite1;
	teamwhite[11] = bishopWhite2;
	teamwhite[12] = knightWhite1;
	teamwhite[13] = knightWhite2;
	teamwhite[14] = kingWhite;
	teamwhite[15] = queenWhite;
	teamblack[8] = rookBlack1;
	teamblack[9] = rookBlack2;
	teamblack[10] = bishopBlack1;
	teamblack[11] = bishopBlack2;
	teamblack[12] = knightBlack1;
	teamblack[13] = knightBlack2;
	teamblack[14] = kingBlack;
	teamblack[15] = queenBlack;
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
	if(checkmate())
		DrawText("Checkmate", 730, 0, 30, RED);
	if (team == 'w') {
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

bool Grid::checkmate()
{
	ChessPiece* pptr = nullptr;
	Vector2* v1;
	int n;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			n = 0;
			pptr=arr[i][j].getpiece();
			if (pptr)
			{
				if (pptr->getteam() != team)
				{
					v1 = pptr->getlegalmoves(this);
					int arrx[36];
					int arry[36];
					while (v1[n].x != -1)
					{
						arrx[n] = v1[n].x;
						arry[n] = v1[n].y;
						n++;
					}
					n = 0;
					while (n<36)
					{
						if (arrx[n] > 7 || arrx[n] < 0)
							break;
						if (dynamic_cast<king*>(arr[arrx[n]][arry[n]].getpiece()))
						{
							if (arr[arrx[n]][arry[n]].getpiece()->getteam() == team)
								return true;
						}
						n++;
					}

				}



			}
 

		}
	}

	return false;
}

bool Grid::gamewon()
{
	bool formofares = false;
	if (checkmate())
	{
		ChessPiece* temptr = nullptr;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j].getpiece())
				{
					
					if (arr[i][j].getpiece()->getteam() == team)
					{
						//if (i == 6 && j == 3)
						//	printf("for mo fares");

						ChessPiece* ptr = arr[i][j].getpiece();
						Vector2* v1 = ptr->getlegalmoves(this);
						int arrx[36];
						int arry[36];
						int n = 0;
						while (v1[n].x != -1)
						{
							arrx[n] = v1[n].x;
							arry[n] = v1[n].y;
							n++;
						}
						while (n != 0)
						{
							if (arrx[n] >= 0 && arrx[n] < 8)
							{
								temptr = arr[arrx[n]][arry[n]].getpiece();
								arr[arrx[n]][arry[n]].setpiece(ptr, countremoved);
								arr[i][j].removepiece();
								if (!checkmate())
								{
									formofares = true;
								}
								if (temptr)
								{
									Vector2 vtemp = temptr->getxy();
									arr[(int)vtemp.x][(int)vtemp.y].setpiece(temptr, countremoved);
									int num = 0;
									if (temptr->getteam() == 'b')
										num += 5;
									if (dynamic_cast<rook*>(temptr))
										num += 4;
									if (dynamic_cast<knight*>(temptr))
										num += 3;
									if (dynamic_cast<bishop*>(temptr))
										num += 2;
									if (dynamic_cast<queen*>(temptr))
										num += 1;
									countremoved[num]--;
									num = 0;
									if (ptr->getteam() == 'b')
										num += 5;
									if (dynamic_cast<rook*>(ptr))
										num += 4;
									if (dynamic_cast<knight*>(ptr))
										num += 3;
									if (dynamic_cast<bishop*>(ptr))
										num += 2;
									if (dynamic_cast<queen*>(ptr))
										num += 1;
									countremoved[num]--;
									arr[arrx[n]][arry[n]].setpiece(temptr, countremoved);
								}
								else
									arr[arrx[n]][arry[n]].removepiece();
								arr[i][j].setpiece(ptr, countremoved);
								//me wana bhbed 34an ttsl7
								Vector2 vtemp;
								vtemp.x = i;
								vtemp.y = j;
								ptr->setxy(vtemp);
								if (formofares)
									goto out;
							}
							n--;
						}

					}
				}



			}

		}

	out:
		if (formofares)
			return false;
		else
			return true;
	}
	return false;
}

void Grid::movepiece()
{
	int coorx = 0, coory = 0;
	coorx = GetMouseX();
	coory = GetMouseY();
	//getting a piece to mouse
	if (IsMouseButtonDown(0))
	{
		if (coorx > x && coorx < (x + sizex * 8) && coory>y && coory < (y + sizey * 8))
		{
			if (!currentlyheld && arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece())
			{
				if(arr[(coorx - x) / sizex][(coory - y) / sizey].getpiece()->getteam()==team)
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
				if (arrx[n] >= 0 && arrx[n] <= 7 && arry[n] <= 7 && arry[n] >= 0 && arr[arrx[n]][arry[n]].getpiece()) {
					DrawRectangle(arrx[n] * 72 + 72, arry[n] * 72 + 72, 72, 72, Color{ 237,41,57,125 });
				}
				else {
					DrawRectangle(arrx[n] * 72 + 72, arry[n] * 72 + 72, 72, 72, Color{ 0,158,47,125 });
				}
				n++;
			}
			currentlyheld->drawpiece(coorx - 32, coory - 16);
		}
			
	}
	//end of getting piece
	//placing a piece
	if (IsMouseButtonUp(0)&&currentlyheld)
	{
		//if the position we are going to contains an enemy for sound
		bool formofares;
		if (arr[(int)((coorx - x) / sizex)][(int)((coory - y) / sizey)].getpiece()) {
			formofares = true;
		}
		else {
			formofares = false;
		}
		
		 Vector2* v1=currentlyheld->getlegalmoves(this);
		 int arrx[36];
		 int arry[36];
		 int n = 0;
		 //placing the values in array bec vector2 sucks
		 while (v1[n].x != -1)
		 {
			 arrx[n] = v1[n].x;
			 arry[n] = v1[n].y;
			 n++;
		 }
		 n = 0;
		//checking the arrays
		 bool ifcheckmated=false;
		 Vector2 temploc;
		while (n<36)
		{
			//if coordinate is legal "exists in array"
			if(((coorx - x) / sizex)==arrx[n] && ((coory - y) / sizey) == arry[n])
			{
				ChessPiece* temptr = arr[arrx[n]][arry[n]].getpiece();
				temploc = currentlyheld->getxy();
				arr[arrx[n]][arry[n]].setpiece(currentlyheld, countremoved);
				if(!checkmate())
				currentlyheld = nullptr;
				else
				{
					ifcheckmated = true;
					if (temptr)
					{
						Vector2 vtemp = temptr->getxy();
						arr[(int)vtemp.x][(int)vtemp.y].setpiece(temptr, countremoved);
						int num = 0;
						if (temptr->getteam() == 'b')
							num += 5;
						if (dynamic_cast<rook*>(temptr))
							num += 4;
						if (dynamic_cast<knight*>(temptr))
							num += 3;
						if (dynamic_cast<bishop*>(temptr))
							num += 2;
						if (dynamic_cast<queen*>(temptr))
							num += 1;
						countremoved[num]--;
						 num = 0;
						if (currentlyheld->getteam() == 'b')
							num += 5;
						if (dynamic_cast<rook*>(currentlyheld))
							num += 4;
						if (dynamic_cast<knight*>(currentlyheld))
							num += 3;
						if (dynamic_cast<bishop*>(currentlyheld))
							num += 2;
						if (dynamic_cast<queen*>(currentlyheld))
							num += 1;
						countremoved[num]--;
					}
					break;
				}
				//playing sound depending on case
				if (formofares)
				{
					PlaySound(take);
				}
				else
					PlaySound(chessmove);
				//if piece placed change team
				if (team == 'w') {
					team = 'b';
				}
				else {
					team = 'w';
					
				}
				return;
            }
			n++;
		}
		//if no piece placed "invalid" return it to place
		Vector2 v = currentlyheld->getxy();
		if (ifcheckmated)
		{
			if(arr[(int)v.x][(int)v.y].getpiece()==currentlyheld)
			arr[(int)v.x][(int)v.y].removepiece();
			v = temploc;
		}
		
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

Grid::~Grid()
{
	for (int i = 0; i < 16; i++)
	{
		delete teamblack[i];
		delete teamwhite[i];
	}
	UnloadSound(take);
	UnloadSound(chessmove);
	UnloadSound(notchessmove);
	delete[]teamblack;
	delete[]teamwhite;
}
