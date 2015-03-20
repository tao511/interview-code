#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../lib/bst.h"

TEST_CASE( "Empty", "[BSTree.empty]" )
{
  BSTree<int> bsTree = BSTree<int>();

	SECTION( "Call empty for an empty tree" ) {
		REQUIRE( bsTree.empty() == true );
	}

	SECTION( "Call empty for a non-empty tree" ) {
		REQUIRE( bsTree.empty() == true );
		bsTree.insert(1);
		REQUIRE( bsTree.empty() == false );
		REQUIRE( bsTree.remove(1) == true );
//		REQUIRE( bsTree.empty() == true );
	}
	
}

TEST_CASE( "Insert", "[BSTree.insert]" )
{
  BSTree<int> bsTree = BSTree<int>();
  REQUIRE( bsTree.empty() == true );

  SECTION( "Insert into empty tree" ) {
    BSTNode<int>* node = bsTree.insert(1);
    REQUIRE( node == bsTree.lookup(1) );
  }

  SECTION( "Insert value larger than current root" ) {
		bsTree.insert(1);
    BSTNode<int>* node = bsTree.insert(2);
		REQUIRE(bsTree.lookup(2) != nullptr);
    REQUIRE( node == bsTree.lookup(1)->right );
    REQUIRE( bsTree.lookup(1)->left == nullptr );
  }

  SECTION( "Insert duplicate values" ) {
    BSTNode<int>* node = bsTree.insert(3);
    BSTNode<int>* node2 = bsTree.insert(3);
    REQUIRE( node == node2 );
  }
}

TEST_CASE( "Lookup", "[BSTree.lookup]" )
{
  BSTree<int> bsTree = BSTree<int>();
  REQUIRE( bsTree.empty() == true );

  SECTION( "Check unexist value" ) {
    REQUIRE( bsTree.lookup(1) == nullptr );
  }

  SECTION( "Check exist value" ) {
    bsTree.insert(90);
    REQUIRE( bsTree.lookup(90) != nullptr );
  }

}
