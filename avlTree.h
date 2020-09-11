class AvlTree
{
public:
	AvlTree();
	void createTree();
	void insert(int value);
	void remove();
	void search();
	void traverse();
	void delete_tree();
	void check_balance();
private:
	struct Node
	{
		Node(int newValue):value(newValue), leftNode(nullptr), rightNode(nullptr){};
		int value;
		Node* leftNode;
		Node* rightNode;
	};
	Node* headNode;
};
