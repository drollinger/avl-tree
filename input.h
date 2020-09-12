#include <string>
#include <vector>
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
enum travSelection
{
	PREORDER = 1,
	POSTORDER = 2,
	INORDER = 3,
};
void printMainMenu();
void printTraversalMenu();
int getIntInput();
int getMainMenuInput();
int getTravMenuInput();
bool stringIsInt(string str);
vector<int> getFileInput();
