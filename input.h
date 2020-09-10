#include <string>
using namespace std;
enum Selection
{
	CREATE_TREE = 1,
	INSERTION = 2,
	DELETION = 3,
	SEARCH = 4,
	TRAVERSAL = 5,
	DELETE_TREE = 6,
	CHECK_BALANCE = 7,
	EXIT = 8
};
void printMainMenu();
int getIntInput();
int getMainMenuInput();
bool stringIsInt(string str);
