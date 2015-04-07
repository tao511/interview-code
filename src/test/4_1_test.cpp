#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/4_1_check_balance.cpp"

TEST_CASE( "Check if this is a balanced tree" )
{

	SECTION( "Empty tree" ) {
		REQUIRE( checkBalance((Node *)nullptr) == 0 );
		Node node(1);
		REQUIRE( checkBalance(&node) == 0 );
	}

	SECTION( "Tree with one node" ) {
		Node node(1);
		node.left = new Node(2);

		REQUIRE( checkBalance(&node) == 1);
	}

	SECTION( "Complicated tree" ) {
		Node node(0);
		node.left = new Node(1);
		node.right = new Node(2);

		REQUIRE( checkBalance(&node) == 0 );

		node.left->left = new Node(3);
		node.left->right = new Node(4);

		REQUIRE( checkBalance(&node) == 1);

		node.left->left->left = new Node(5);

		REQUIRE( checkBalance(&node) == 2);
	}

}
