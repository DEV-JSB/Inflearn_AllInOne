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
	Node* root = new Node("R1 개발실");
	{
		Node* node = new Node("디자인팀");
		root->children.push_back(node);
		{
			Node* leaf = new Node("전투");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("경제");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("스토리");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("플머팀");
		root->children.push_back(node);
		{
			Node* leaf = new Node("클라");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("서버");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("엔진");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("아트");
		root->children.push_back(node);
		{
			Node* leaf = new Node("배경");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("캐릭터");
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

// Height 를 구하는 함수
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