#include"raylib.h"
#include"cell.h"
#include"Grid.h"




void main()
{
	

	InitWindow(1280, 720, "Chess");
	InitAudioDevice();
	SetTargetFPS(30);
	Texture2D texture = LoadTexture("./resources/chess_board.png");
	Grid thegrid(texture);
	char team = 'w';
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(texture, 0, 0, WHITE);
		//buttons
		thegrid.DrawGrid();
		thegrid.mouseclicked();
		thegrid.movepiece(team);
			
		EndDrawing();
	}
	CloseAudioDevice();
	

}