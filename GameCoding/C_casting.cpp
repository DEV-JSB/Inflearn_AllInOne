#include<iostream>	

using namespace std;


class Player
{
public:
};

class Knight : public Player
{

};

class Dog
{
public:
};

void main()
{
	Knight* k = new Knight;
	Dog* dog = (Dog*)k;


		// C ��Ÿ�� casting
		// �� Ÿ�� ��ȯ
		// Ư¡ => �ǹ̸� �����ϱ� ���켭 ���� ��ü�� �ٸ� ��Ʈ�� �籸��
	{

		int a = 123456789;
		float b = (float)a;
		int c = 0;
	}
		// ���� Ÿ�� ��ȯ 
	{
		int a = 123456789;
		float b = (float&)a;
		int c = 0;
	}
	// �������� ū ������ �ű����� ������ ��ȯ
	{
		int small = 123456789;
		__int64 big = (float&)small;
		int c = 0;
	}
	// �������� ���� ��ȯ
	{
		int small = 123456789;
		short ssmall = (float&)small;
		int c = 0;
	}
	// �Ͻ��� ��ȯ
	{
		int a = 123456789;
		float b = a;
	}
}