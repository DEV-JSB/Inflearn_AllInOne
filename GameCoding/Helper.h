enum class DIRECTION
{
	LEFT,
	DOWN,
	RIGHT,
	UP
};

void MoveDirectionCleanCode(int& nextX, int& nextY, DIRECTION type)
{
	int dir = (int)type;
	int directionX[]{ 1,0,-1,0 };
	int directionY[]{ 0,1,-1,0 };
	nextX += directionX[dir];
	nextY += directionX[dir];
}
void MoveDirectionNotClean(int& x, int& y, DIRECTION dir)
{
	switch (dir)
	{
	case DIRECTION::LEFT:
		++x;
		break;
	case DIRECTION::DOWN:
		++y;
		break;
	case DIRECTION::RIGHT:
		--x;
		break;
	case DIRECTION::UP:
		--y;
		break;
	}
}