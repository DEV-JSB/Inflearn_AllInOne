#include "Player.h"
#include "Map.h"
#include "Helper.h"

int GPlayerX = 2;
int GPlayerY = 2;


bool canMove = true;

void HandleMove()
{
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	if (canMove == false)
		return;

	canMove = false;

	switch (GMoveDir)
	{
	case MD_LEFT:
		MovePlayer(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer(GPlayerX, GPlayerY + 1);
		break;
	}
}
void MovePlayer(int x, int y)
{
	if (x < 0 || x >= MAP_SIZE)
		return;
	if (y < 0 || y >= MAP_SIZE)
		return;
	int index = MAP_SIZE * y + x;
	if (GMap1D[index] == 1)
		return;
	if (GMap2D[y][x] == 1)
		return;

	int prevIndex = GPlayerY * MAP_SIZE + GPlayerX;
	GMap1D[prevIndex] = 0;
	GMap2D[GPlayerY][GPlayerX] = 0;

	GPlayerX = x;
	GPlayerY = y;
	GMap1D[index] = 2;
	GMap2D[GPlayerY][GPlayerX] = 2;

}
