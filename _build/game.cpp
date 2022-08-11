#include"raylib.h"
#include"cell.h"
#include"Grid.h"




void main()
{
	

	InitWindow(1280, 720, "Chess");
	SetTargetFPS(30);
	Texture2D texture = LoadTexture("./resources/chess_board.png");
	Grid thegrid(texture);
		
		
	while (!WindowShouldClose())
	{
		BeginDrawing();
		
			ClearBackground(RAYWHITE);
			DrawTexture(texture, 0, 0, WHITE);
			thegrid.DrawGrid();
			thegrid.mouseclicked();

		EndDrawing();
	}
	

}