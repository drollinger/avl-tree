#include "main.h"
#include "input.h"
#include "avlTree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	printMainMenu();
	//Node 
	int selection;
	do
	{
		selection = getMainMenuInput();
		switch (selection)
		{
			case CREATE_TREE:
			case INSERTION:
			case DELETION:
			case SEARCH:
			case TRAVERSAL:
			case DELETE_TREE:
			case CHECK_BALANCE:
				createTree();
		}
	} while (selection != EXIT);
}
