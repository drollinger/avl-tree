#include "main.h"
#include "input.h"
#include "avlTree.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	printMainMenu();
	AvlTree avlTree;
	int selection;
	int input;
	string nodeInfo;
	vector<int> arrayOfValues;
	do
	{
		selection = getMainMenuInput();
		switch (selection)
		{
			case CREATE_TREE:
				arrayOfValues = getFileInput();
				avlTree.createTree(arrayOfValues);
				cout << "Create Tree:";
				avlTree.preOrderPrint();
				cout << endl;
				break;
			case INSERTION:
				cout << "Enter the Integer Value to Insert.\n";
				input = getIntInput();
				avlTree.insert(input);
				cout << "Inserted:";
				avlTree.preOrderPrint();
				cout << endl;
				break;
			case DELETION:
				cout << "Enter the Integer Value to Delete.\n";
				input = getIntInput();
				if(!avlTree.remove(input))
					cout << "Node cannot be deleted. Empty Tree!\n";
				else
				{
					cout << "Deleted:";
					avlTree.preOrderPrint();
					cout << endl;
				}
				break;
			case SEARCH:
				cout << "Enter the Integer Value to Search.\n";
				nodeInfo = avlTree.search(getIntInput());
				if (nodeInfo.empty())
					cout << "Value Not Found.\n";
				else
					cout << "Node Found:" << nodeInfo;
				break;
			case TRAVERSAL:
				printTraversalMenu();
				input = getTravMenuInput();
				switch (input)
				{
					case PREORDER:
						cout << "Pre-Order Traversal:";
						avlTree.preOrderPrint();
						cout << endl;
						break;
					case POSTORDER:
						cout << "Post-Order Traversal:";
						avlTree.postOrderPrint();
						cout << endl;
						break;
					case INORDER:
						cout << "In-Order Traversal:";
						avlTree.inOrderPrint();
						cout << endl;
						break;
				}
				break;
			case DELETE_TREE:
				if (avlTree.delete_tree())
					cout << "Delete Tree: Tree Deleted\n";
				else
					cout << "Delete Tree: Tree Does Not Exist\n";
				break;
			case CHECK_BALANCE:
				input = avlTree.check_balance();
				if (input < 0)
					cout << "No Balance Factor. Empty Tree!\n";
				else
					cout << "Check Balance: " << input << endl;
				break;
		}
		if (selection != EXIT)
			cout << "Make Another Selection from the Main Menu.\n";
	} while (selection != EXIT);
}
