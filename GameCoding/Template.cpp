#include<iostream>	


template<typename T>
void Print(T a)
{
	std::cout << a << std::endl;
}

template<typename T1,typename T2>
void Print(T1 a, T2 b)
{

}

template<>
void Print(int a)
{
	std::cout << "int Version" << std::endl;
}

template<typename T = int>
class RandomBox
{
public:
	T GetRandomData()
	{
		int index = rand() % SIZE;
		return data[index];
	}
public:
	T data[SIZE];
};

template<>
class RandomBox<int>
{
public:
	int GetRandomData()
	{
		int index = rand() % 100;
		return data[index];
	}
public:
	int data[100];
};


void main()
{
	RandomBox<int> rbInt;
	RandomBox<float> rbFloat;

}