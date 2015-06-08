#ifndef INTERVIEW_BST_TO_LISTS
#define INTERVIEW_BST_TO_LISTS

#include <iostream>
#include <vector>

class BSTNode {
	private:
		int _val;
	public:
		BSTNode *leftChild;
		BSTNode *rightChild;

		BSTNode(int val): _val(val), leftChild(nullptr), rightChild(nullptr) {}
		int getVal() {return _val;}


};

std::vector< std::vector<int> > bstToLists(BSTNode* root, int height) {
	std::vector< std::vector<int> > bstLists;

	std::function<void(BSTNode* root, int height)> traverse;
	traverse = [&traverse, &bstLists](BSTNode* root, int height) -> void {

		if (root == nullptr) return;
		if (height >= bstLists.size()) {
			bstLists.push_back(std::vector<int>());
		}

		bstLists[height].push_back(root->getVal());

		if (root->leftChild != nullptr) {
			traverse(root->leftChild, height + 1);
		}
		if (root->rightChild != nullptr) {
			traverse(root->rightChild, height + 1);
		}
	};

	traverse(root, height);

	return bstLists;
}

#endif
