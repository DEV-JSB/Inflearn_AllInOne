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
	// 1�� ���� ���� �Ѵ�
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		// �̵�
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


	//������
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
		// ���� �ٶ󺸴� ������ �������� ���������� �� �� �ִ��� Ȯ��
		int32 newDir = _dir - 1 % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			_dir = newDir;
			// ������ �������� 90�� ȸ��
			// ������ �� �� ����
			pos += front[_dir];
			// ��ǥ ���
			_path.push_back(pos);
		}
		// ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��
		else if (CanGo(pos + front[_dir]))
		{
			pos += front[_dir];
			_path.push_back(pos);
		}
		// ���� �ٶ󺸴� ������ �������� �������� �� �� �ִ��� Ȯ��
		else
		{
			newDir = _dir + 1 % DIR_COUNT;
			_dir = newDir;
		}
	}
}
