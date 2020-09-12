#include "avlTree.h"
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;
class AvlTree
{
public:
	AvlTree()
	{
		headNode = nullptr;
	}
	void createTree(vector<int> arrayOfValues)
	{
		delete_tree();
		for (int i : arrayOfValues)
			insert(i);
	}
	void insert(int value)
	{
		if (headNode == nullptr)
			headNode = new Node(value);
		else
			insert(value, headNode);
		headNode = balance(headNode);
	}
	bool remove(int value)
	{
		if (headNode == nullptr)
			return false;
		else 
			remove(value, headNode);
		return true;
	}
	void search(int value)
	{
		cout << "TODO4\n";
	}
	void traverse()
	{
		cout << "TODO5\n";
	}
	void delete_tree()
	{
		delete headNode;
		headNode = nullptr;
	}
	int check_balance()
	{
		return headNode != nullptr ? 
			abs(getHeight(headNode->leftNode) - getHeight(headNode->rightNode)) : -1;
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

	Node* insert(int value, Node* node)
	{
		if (node == nullptr)
			node = new Node(value);
		else if (value == node->value)
			cout << "Duplicate Value Not Added.\n";
		else
		{
			if (value < node->value)
				node->leftNode = insert(value, node->leftNode);
			else
				node->rightNode = insert(value, node->rightNode);

			node = balance(node);
		}
		return node;
	}

	Node* remove(int value, Node* node)
	{
		if (node == nullptr)
			cout << "Node cannot be found. Deletion cannot be performed.\n";
		else if (value != node->value)
			if (value < node->value)
				node->leftNode = remove(value, node->leftNode);
			else
				node->rightNode = remove(value, node->rightNode);
		else
		{
			Node* successor;
			if (node->leftNode != nullptr && node->rightNode != nullptr)
			{
				successor = getRightest(node->leftNode);
				successor->leftNode = removeRightest(node->leftNode);
				successor->rightNode = node->rightNode;
			}
			else if (node->leftNode == nullptr && node->rightNode != nullptr)
				successor = node->rightNode;
			else if (node->rightNode == nullptr && node->leftNode != nullptr)
				successor = node->leftNode;
			else
				successor = nullptr;
			delete node;
			node = nullptr;
			successor = balance(successor);
			return successor;
		}
		return node;
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
		node->leftNode = leftRightNode->rightNode;

		//Set the new main node
		leftRightNode->leftNode = leftNode;
		leftRightNode->rightNode = node;

		//Update the heights of affected nodes
		updateHeight(leftNode);
		updateHeight(node);
		updateHeight(leftRightNode);

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

		//Update the heights of affected nodes
		updateHeight(node);
		updateHeight(leftNode);

		return leftNode;
	}
	Node* rightLeftRotation(Node* node)
	{
		//Save Right and RightLeft Nodes
		Node* rightNode = node->rightNode;
		Node* rightLeftNode = rightNode->leftNode;

		//Save children of the RightLeft Node
		rightNode->leftNode = rightLeftNode->rightNode;
		node->rightNode = rightLeftNode->leftNode;

		//Set the new main node
		rightLeftNode->leftNode = node;
		rightLeftNode->rightNode = rightNode;

		//Update the heights of affected nodes
		updateHeight(rightNode);
		updateHeight(node);
		updateHeight(rightLeftNode);

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

		//Update the heights of affected nodes
		updateHeight(node);
		updateHeight(rightNode);
		
		return rightNode;
	}
	void updateHeight(Node* node)
	{
		if (node != nullptr)
			node->height = max(getHeight(node->leftNode), getHeight(node->rightNode)) + 1;
	}

	Node* getRightest(Node* node)
	{
		if (node->rightNode != nullptr)
			return getRightest(node->rightNode);
		else
			return node;
	}

	Node* removeRightest(Node* node)
	{
		if (node->rightNode != nullptr)
			node->rightNode = removeRightest(node->rightNode);
		else 
		{
			Node* leftChild = node->leftNode;
			delete node;
			node = nullptr;
			return leftChild;
		}
		node = balance(node);
		return node;
	}
};
