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
	vector<int> arrayOfValues;
	do
	{
		selection = getMainMenuInput();
		switch (selection)
		{
			case CREATE_TREE:
				arrayOfValues = getFileInput();
				cout << "Create Tree:";
				for (int value : arrayOfValues)
					cout << " " << value;
				avlTree.createTree(arrayOfValues);
				cout << endl;
				break;
			case INSERTION:
				cout << "Enter the Integer Value to Insert.\n";
				avlTree.insert(getIntInput());
				break;
			case DELETION:
				cout << "Enter the Integer Value to Delete.\n";
				if(!avlTree.remove(getIntInput()))
					cout << "Node cannot be deleted. Empty Tree!\n";
				break;
			case SEARCH:
				avlTree.search(1);
				break;
			case TRAVERSAL:
				avlTree.traverse();
				break;
			case DELETE_TREE:
				avlTree.delete_tree();
				break;
			case CHECK_BALANCE:
				int balance = avlTree.check_balance();
				if (balance < 0)
					cout << "No Balance Factor. Empty Tree!\n";
				else
					cout << "Check Balance: " << balance << endl;
				break;
		}
		if (selection != EXIT)
			cout << "Make Another Selection from the Main Menu.\n";
	} while (selection != EXIT);
}
