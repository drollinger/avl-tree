#include "avlTree.h"
#include <iostream>

using namespace std;
class AvlTree
{
public:
	AvlTree()
	{
		headNode = nullptr;
	}
	void createTree()
	{
		cout << "TODO1\n";
	}
	void insert(int value)
	{
		if (headNode == nullptr)
			headNode = new Node(value);
		else
			insert(value, headNode);
		headNode = balance(headNode);
	}
	void remove()
	{
		cout << "TODO3\n";
	}
	void search()
	{
		cout << "TODO4\n";
	}
	void traverse()
	{
		cout << "TODO5\n";
	}
	void delete_tree()
	{
		cout << "TODO6\n";
	}
	void check_balance()
	{
		cout << "TODO7\n";
	}
private:
	struct Node
	{
		Node(int newValue):
			value(newValue),
			height(1),
			leftNode(nullptr),
			rightNode(nullptr){};
		int value;
		int height;
		Node* leftNode;
		Node* rightNode;
	};
	Node* headNode;

	void insert(int value, Node* node)
	{
		if (node == nullptr)
			node = new Node(value);
		else
		{
			if (value < node->value)
				insert(value, node->leftNode);
			else if (value > node->value)
				insert(value, node->rightNode);
			else
				cout << "Duplicate Value Not Added.\n";

			node->leftNode = balance(node->leftNode);
			node->rightNode = balance(node->leftNode);
		}
	}

	Node* balance(Node* node)
	{
		if (node == nullptr)
			return nullptr;
		int leftHeight = getHeight(node->leftNode);
		int rightHeight = getHeight(node->rightNode);
		Node* topNode = node;
		//left height is greater
		if (leftHeight - rightHeight > 1)
			topNode = getHeight(node->leftNode->leftNode) - getHeight(node->leftNode->rightNode) < 0 ?
				leftRightRotation(node) : leftLeftRotation(node);
		//right height is greater
		else if (rightHeight - leftHeight > 1)
			topNode = getHeight(node->rightNode->rightNode) - getHeight(node->rightNode->leftNode) < 0 ?
				rightLeftRotation(node) : rightRightRotation(node);
		return topNode;
	}

	int getHeight(Node* node) 
	{
		return node != nullptr ? node->height : 0;
	}

	Node* leftRightRotation(Node* node)
	{
		//Save Left and LeftRight Nodes
		Node* leftNode = node->leftNode;
		Node* leftRightNode = leftNode->rightNode;

		//Save children of the LeftRight Node
		leftNode->rightNode = leftRightNode->leftNode;
		Node* leftestNode = getLeftestNode(node);
		leftestNode->leftNode = leftRightNode->rightNode;

		//Set the new main node
		leftRightNode->leftNode = leftNode;
		leftRightNode->rightNode = node;
		return leftRightNode;
	}

	Node* leftLeftRotation(Node* node)
	{
		//Save Left Node
		Node* leftNode = node->leftNode;

		//Save Right child of Left Node
		node->leftNode = leftNode->rightNode;

		//Set the new main node
		leftNode->rightNode = node;
		return leftNode;
	}
	Node* rightLeftRotation(Node* node)
	{
		//Save Right and RightLeft Nodes
		Node* rightNode = node->rightNode;
		Node* rightLeftNode = rightNode->leftNode;

		//Save children of the RightLeft Node
		rightNode->leftNode = rightLeftNode->rightNode;
		Node* rightestNode = getRightestNode(node);
		rightestNode->rightNode = rightLeftNode->leftNode;

		//Set the new main node
		rightLeftNode->leftNode = node;
		rightLeftNode->rightNode = rightNode;
		return rightLeftNode;
	}
	Node* rightRightRotation(Node* node)
	{
		//Save Right Node
		Node* rightNode = node->rightNode;

		//Save Left Child of Right Node
		node->rightNode = rightNode->leftNode;

		//Set the new main node
		rightNode->leftNode = node;
		return rightNode;
	}
	Node* getLeftestNode(Node* node)
	{
		return node->leftNode == nullptr ? node : getLeftestNode(node->leftNode);
	}
	Node* getRightestNode(Node* node)
	{
		return node->rightNode == nullptr ? node : getRightestNode(node->rightNode);
	}
}
