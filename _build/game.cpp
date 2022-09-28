#include"raylib.h"
#include"cell.h"
#include"Grid.h"
bool reset()
{
	if (IsMouseButtonDown(0))
	{
		int coorx = 0, coory = 0;
		coorx = GetMouseX();
		coory = GetMouseY();
		if (coorx >= 1043 && coorx <= 1257 && coory >= 325 && coory <= 397)
		{
		
		printf("ana fl if ya kelab w 48al\n");
		int coorx = 0, coory = 0;
		coorx = GetMouseX();
		coory = GetMouseY();
		if (coorx >= 1043 && coorx <= 1257 && coory >= 325 && coory <= 397)
			return true;
		}
	}


	return false;
}



void main()
{
	

	InitWindow(1280, 720, "Chess");
	InitAudioDevice();
	SetTargetFPS(30);
	Texture2D texture = LoadTexture("./resources/chess_board.png");
	Texture2D texturebutton = LoadTexture("./resources/Reset_button.png");
	Texture2D texturepressed = LoadTexture("./resources/Reset_Pressed.png");
	Image icon = LoadImage("./resources/pawn_black.png");
	SetWindowIcon(icon);
	Grid* thegrid=new Grid(texture);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(texture, 0, 0, WHITE);
		//buttons
		thegrid->DrawGrid();
		if (reset())
		{
			DrawTexture(texturepressed, 1043,335, WHITE);
			delete thegrid;
			thegrid = new Grid(texture);
		}
		else
		{
			DrawTexture(texturebutton, 1043, 325, WHITE);

		}
		if (thegrid->gamewon())
		{
			DrawText("Game Ended press left click to reset", 320, 380, 50, BLACK);
			if (IsMouseButtonDown(0))
			{
				delete thegrid;
				thegrid = new Grid(texture);
			}

		}
		else {
			thegrid->mouseclicked();
			thegrid->movepiece();
		}
		EndDrawing();
	}
	CloseAudioDevice();
	

}