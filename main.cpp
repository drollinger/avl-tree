#include "main.h"
#include "input.h"
#include "avlTree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	printMainMenu();
	AvlTree avlTree;
	int selection;
	do
	{
		selection = getMainMenuInput();
		switch (selection)
		{
			case CREATE_TREE:
				avlTree.createTree();
				break;
			case INSERTION:
				avlTree.insert();
				break;
			case DELETION:
				avlTree.remove();
				break;
			case SEARCH:
				avlTree.search();
				break;
			case TRAVERSAL:
				avlTree.traverse();
				break;
			case DELETE_TREE:
				avlTree.delete_tree();
				break;
			case CHECK_BALANCE:
				avlTree.check_balance();
				break;
		}
	} while (selection != EXIT);
}
