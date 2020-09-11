#include "avlTree.h"
#include <iostream>

using namespace std;

AvlTree::AvlTree()
{
	headNode = nullptr;
}
void AvlTree::createTree()
{
	cout << "TODO1\n";
}
void AvlTree::insert(int value)
{
	if (headNode == nullptr)
		headNode = new Node(value);
	else
	{

	}

	
	
}
void AvlTree::remove()
{
	cout << "TODO3\n";
}
void AvlTree::search()
{
	cout << "TODO4\n";
}
void AvlTree::traverse()
{
	cout << "TODO5\n";
}
void AvlTree::delete_tree()
{
	cout << "TODO6\n";
}
void AvlTree::check_balance()
{
	cout << "TODO7\n";
}
