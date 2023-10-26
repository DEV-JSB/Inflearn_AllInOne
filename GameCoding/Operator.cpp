
class Pos
{
public:
	Pos()
	{

	}
	Pos(int a,int b) :x(a), y(b)
	{

	}
	explicit Pos(int a):x(a),y(a)
	{
		
	}
	Pos operator+(const Pos& b)
	{
		Pos pos;
		pos.x = x + b.x;
		pos.y = y + b.y;
		return pos;
	}
	void operator=(const int& a)
	{
		this->x = a;
		this->y = a;
	}
	Pos& operator=(int b)
	{
		this->x = b;
		this->y = b;
		return *this;
	}
	Pos operator+(const int& a)
	{
		return Pos{ this->x + a,this->y + a };
	}
public:
	int x;
	int y;
};

Pos operator+(int a, const Pos& b)
{
	return Pos{b.x + a, b.y + a};
}
void TestPos(Pos a)
{

}

void main()
{
	/*Pos pos1;
	Pos pos2;
	Pos pos3 = pos1 + pos2;
	pos3 = pos1.operator+(pos2);*/
	Pos pos2 = 10;
	TestPos(10);
} 