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


		// C 스타일 casting
		// 값 타입 변환
		// 특징 => 의미를 유지하기 위헤서 원본 객체와 다른 비트열 재구성
	{

		int a = 123456789;
		float b = (float)a;
		int c = 0;
	}
		// 참조 타입 변환 
	{
		int a = 123456789;
		float b = (float&)a;
		int c = 0;
	}
	// 작은것을 큰 곳으로 옮김으로 안전한 변환
	{
		int small = 123456789;
		__int64 big = (float&)small;
		int c = 0;
	}
	// 안전하지 않은 변환
	{
		int small = 123456789;
		short ssmall = (float&)small;
		int c = 0;
	}
	// 암시적 변환
	{
		int a = 123456789;
		float b = a;
	}
}