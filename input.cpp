#include "input.h"
#include "trim.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void printMainMenu()
{
	cout << "Choose the option to be performed:\n"
	     << "  1. Create_Tree\n"
	     << "  2. Insertion\n"
	     << "  3. Deletion\n"
	     << "  4. Search\n"
	     << "  5. Traversal\n"
	     << "  6. Delete_Tree\n"
	     << "  7. Check_Balance\n"
	     << "  8. Exit\n";
}

int getMainMenuInput()
{
	int selection;
	bool isBadSelection;
	do
	{
		selection = getIntInput();
		isBadSelection = selection < 1 || selection > 8;
		if (isBadSelection)
			cout << "Bad Selection. Try Again.\n";
	} while (isBadSelection);
	return selection;
}

int getIntInput()
{
	string str; 
	bool badInput = false;
	int input;
	do
	{
		do 
		{
			badInput = false;
			cout << "> ";
			getline(cin, str);
		}
		while (!stringIsInt(str));
		try { input = stoi(str); }
		catch(...) 
		{
			cout << "Error Processing Integer. Try Again.\n";
			badInput = true;
		}
	} while (badInput);
	return input;
}

bool stringIsInt(string str)
{
	trim(str);
	bool isInt = false;
	if(str.length())
	{
		isInt = isdigit(str[0]) || str[0] == '-';
		for(int i = 1; i < str.length() && isInt; i++)
			isInt = isdigit(str[i]) && isInt;
		if(!isInt)
			cout << "Please Only Enter a Single Integer. Try Again.\n";
	}
	return isInt;
}

vector<int> getFileInput()
{
	ifstream infile("input.txt");	
	vector<int> arrayOfValues;
	int value;
	while (infile >> value)
		arrayOfValues.push_back(value);
	return arrayOfValues;
}

