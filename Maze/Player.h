#pragma once
#include "Vector.h"

class Board;



class Player
{
	enum
	{
		MOVE_TICK = 100
	};

public:
	void Init(Board* board);
	void Update(uint64 deltaTick);


	void SetPos(Pos pos) { _pos = pos; }
	Pos GetPos() {return _pos;}

	bool CanGo(Pos pos);
private:
	void CaculatePath();
private:
	Pos _pos;
	int32 _dir = DIR_UP;
	Board* _board = nullptr;

	// 내가 만든 동적 배열
	Vector _path; 
	int32 _pathIndex;
	uint64 _sumTick = 0;
};

