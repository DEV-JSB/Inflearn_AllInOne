#include<iostream>	
#include<vector>
using namespace std;

using namespace std;

class Node
{
public:
	Node(const char* data) : data(data)
	{
	}
public:
	const char* data;
	vector<Node*> children;
};

Node* CreateTree()
{
	Node* root = new Node("R1 ���߽�");
	{
		Node* node = new Node("��������");
		root->children.push_back(node);
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("���丮");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("�ø���");
		root->children.push_back(node);
		{
			Node* leaf = new Node("Ŭ��");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("��Ʈ");
		root->children.push_back(node);
		{
			Node* leaf = new Node("���");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("ĳ����");
			node->children.push_back(leaf);
		}
	}
	return root;
}

void PrintTree(Node* root , int depth = 0)
{
	for (int i = 0; i < depth; ++i)
		cout << "-";

	cout << root->data << endl;
	int size = root->children.size();
	for (int i = 0; i < size; ++i)
	{
		Node* childNode = root->children[i];
		PrintTree(childNode, depth + 1);
	}
}

// Height �� ���ϴ� �Լ�
int GetHeight(Node* root)
{
	int answer = 1;

	int size = root->children.size();
	for (int i = 0; i < size; ++i)
	{
		Node* childNode = root->children[i];
		int h = GetHeight(childNode) + 1;

		if (answer < h)
			answer = h;
	}
	return answer;
}

int main()
{
	Node* root = CreateTree();

	GetHeight(root);

}