#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	CaculatePath();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;
	_sumTick += deltaTick;
	// 1초 마다 무언가 한다
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		// 이동
		_pos = _path[_pathIndex];
		++_pathIndex;
	}

}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CaculatePath()
{
	Pos pos = _pos;
	_path.clear();
	_path.push_back(pos);


	//목적지
	Pos destination = _board->GetExitPos();

	for (int i = 0; i < 20; ++i)
	{
		pos += Pos(1, 0);
		_path.push_back(pos);
	}

	Pos front[4] =
	{
		Pos(-1,0),
		Pos(0,-1),
		Pos(1,0),
		Pos(0,1) 
	};

	Pos next = pos + front[_dir];

	_dir = _dir++;

	while (pos != destination)
	{

	}
}
