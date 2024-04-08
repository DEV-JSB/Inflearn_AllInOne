#pragma once
#include<iostream>

using namespace std;

template<typename T>
class Node
{

	//typedef int T;
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr)
	{

	}
public:
	T data;
	Node* prev;
	Node* next;
};

template<typename T>
class List
{
public:
	List()
	{
		_head = new Node<T>(0);
		_tail = new Node<T>(0);
		_head->next = _tail;
		_tail->prev = _head;
	}
	~List()
	{
		Node<T>* node = _head;
		while (node)
		{
			Node<T>* willDeleteNode = node;
			node = willDeleteNode->next;
			delete willDeleteNode;
		}
	}


	Node<T>* AddAtHead(int data)
	{
		Node<T>* node = new Node(data);
		Node<T>* headNextNode = _head->next;

		headNextNode->prev = node;
		node->next = headNextNode;
		_head->next = node;
		node->prev = _head;
		return node;
	}

	Node<T>* AddAtTail(int data)
	{
		Node<T>* node = new Node(data);
		Node<T>* tailPrevNode = _tail->prev;

		tailPrevNode->next = node;
		node->prev = tailPrevNode;
		node->next = _tail;
		_tail->prev = node;
		return node;
	 }
	
	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->next;
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
		Node<T>* node = _head->next;
		while (_tail != node)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	void Insert(Node<T>* posNode, int data)
	{
		Node<T>* node = new Node(data);
		Node<T>* prevNode = posNode->prev;

		prevNode->next = node;
		node->next = posNode;
		node->prev = prevNode;
		posNode->prev = node;
		
	}
	 
	void Remove(Node<T>* wantDeleteNode)
	{
		Node<T>* prevNode = wantDeleteNode->prev;
		Node<T>* nextNode = wantDeleteNode->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete wantDeleteNode;
	}
private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;

};
