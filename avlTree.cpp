#include "avlTree.h"
#include <iostream>
#include <ostream>
#include <string>
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
			headNode = insert(value, headNode);
	}
	bool remove(int value)
	{
		if (headNode == nullptr)
			return false;
		remove(value, headNode);
		return true;
	}
	string search(int value)
	{
		Node* node = search(value, headNode);
		return node == nullptr ? string() :
			"\n\tValue: " + to_string(node->value) + "\n" +
			"\tHeight: " + to_string(node->height) + "\n" +
			"\tLeft Child Value: " + getNodeValueString(node->leftNode) + "\n" +
			"\tRight Chile Value: " + getNodeValueString(node->rightNode) + "\n";
	}
	void preOrderPrint()
	{
		preOrderPrint(headNode);
	}
	void postOrderPrint()
	{
		postOrderPrint(headNode);
	}
	void inOrderPrint()
	{
		inOrderPrint(headNode);
	}
	bool delete_tree()
	{
		if (headNode == nullptr)
			return false;
		delete headNode;
		headNode = nullptr;
		return true;
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

	Node* search(int value, Node* node)
	{
		if (node == nullptr)
			return nullptr;
		else if (value < node->value)
			return search(value, node->leftNode);
		else if (value > node->value)
			return search(value, node->rightNode);
		else
			return node;
	}

	void preOrderPrint(Node* node)
	{
		if (node == nullptr)
			return;
		cout << " " << node->value;
		preOrderPrint(node->leftNode);
		preOrderPrint(node->rightNode);
	}
	void postOrderPrint(Node* node)
	{
		if (node == nullptr)
			return;
		postOrderPrint(node->leftNode);
		postOrderPrint(node->rightNode);
		cout << " " << node->value;
	}
	void inOrderPrint(Node* node)
	{
		if (node == nullptr)
			return;
		inOrderPrint(node->leftNode);
		cout << " " << node->value;
		inOrderPrint(node->rightNode);
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
		updateHeight(topNode);
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

	string getNodeValueString(Node* node)
	{
		return node == nullptr ? "NULL" : to_string(node->value);
	}
};
