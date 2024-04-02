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
		// 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인
		int32 newDir = _dir - 1 % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			_dir = newDir;
			// 오른쪽 방향으로 90도 회전
			// 앞으로 한 보 전진
			pos += front[_dir];
			// 좌표 기록
			_path.push_back(pos);
		}
		// 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if (CanGo(pos + front[_dir]))
		{
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 현재 바라보는 방향을 기준으로 왼쪽으로 갈 수 있는지 확인
		else
		{
			newDir = _dir + 1 % DIR_COUNT;
			_dir = newDir;
		}
	}
}
