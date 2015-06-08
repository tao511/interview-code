#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/4_4_bst_to_lists.cpp"

TEST_CASE( "BST to lists" )
{

	SECTION( "Empty BST" ) {
		std::vector< std::vector<int> > res = bstToLists(nullptr, 0);
		REQUIRE(res.size() == 0);
	}

	SECTION( "BST test" ) {
		BSTNode *bstNode = new BSTNode(0);
		bstNode->leftChild = new BSTNode(1);
		bstNode->leftChild->leftChild = new BSTNode(2);
		bstNode->leftChild->rightChild = new BSTNode(2);
		std::vector< std::vector<int> > res = bstToLists(bstNode, 0); 

		REQUIRE(res.size() == 3);
		REQUIRE(res[0].size() == 1);
		REQUIRE(res[1].size() == 1);
		REQUIRE(res[2].size() == 2);
	}
}
