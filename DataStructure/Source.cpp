#include <iostream>


class Node
{
public:
	Node(int data) :data(data)
	{
		next = nullptr;
	}
public:

	int data;
	void* next = nullptr;
	void* prev = nullptr;
};

void main()
{
	

}