#ifndef INTERVIEW_CHECK_BALANCE
#define INTERVIEW_CHECK_BALANCE

struct Node {
	int data;
	Node *left;
	Node *right;
	Node *parent;

	Node(int data) : data(data), left(nullptr), 
		right(nullptr), parent(nullptr) {}
};

void getLevel(Node *node, int& level) {
	if (node == nullptr) return;
	level++;
	int leftLevel = level, rightLevel = level;
	getLevel(node->left, leftLevel);
	getLevel(node->right, rightLevel);
	level = leftLevel > rightLevel ? leftLevel : rightLevel;
}

bool checkBalance(Node *node) {
	if (node == nullptr) return true; // Defensive programming

	int leftLevel = 0, rightLevel = 0;

	getLevel(node->left, leftLevel);
	getLevel(node->right, rightLevel);

	int diff = leftLevel > rightLevel ? leftLevel - rightLevel : rightLevel - leftLevel;

	return (diff < 2) && checkBalance(node->left) && checkBalance(node->right);
}


#endif
