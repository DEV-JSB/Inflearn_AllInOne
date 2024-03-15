#pragma once
#include<iostream>

using namespace std;

class Node
{

	//typedef int T;
	using T = int;
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr)
	{

	}
public:
	T data;
	Node* prev;
	Node* next;
};


class List
{
public:
	List()
	{
		_head = new Node(0);
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}
	~List()
	{
		Node* node = _head;
		while (node)
		{
			Node* willDeleteNode = node;
			node = willDeleteNode->next;
			delete willDeleteNode;
		}
	}


	Node* AddAtHead(int data)
	{
		Node* node = new Node(data);
		Node* headNextNode = _head->next;

		headNextNode->prev = node;
		node->next = headNextNode;
		_head->next = node;
		node->prev = _head;
		return node;
	}

	Node* AddAtTail(int data)
	{
		Node* node = new Node(data);
		Node* tailPrevNode = _tail->prev;

		tailPrevNode->next = node;
		node->prev = tailPrevNode;
		node->next = _tail;
		_tail->prev = node;
		return node;
	 }
	
	Node* GetNode(int index)
	{
		Node* node = _head->next;
		if (node == _tail)
			return nullptr;
		for (int i = 0; i < index; ++i)
		{
			if (node == _tail->prev)
				return nullptr;
			node = node->next;
		}
		return node;

	}
	void Print()
	{
		Node* node = _head->next;
		while (_tail != node)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	void Insert(Node* posNode, int data)
	{
		Node* node = new Node(data);
		Node* prevNode = posNode->prev;

		prevNode->next = node;
		node->next = posNode;
		node->prev = prevNode;
		posNode->prev = node;
		
	}
	 
	void Remove(Node* wantDeleteNode)
	{
		Node* prevNode = wantDeleteNode->prev;
		Node* nextNode = wantDeleteNode->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete wantDeleteNode;
	}
private:
	Node* _head = nullptr;
	Node* _tail = nullptr;

};
