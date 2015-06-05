#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/4_3_array_to_bst.cpp"

TEST_CASE( "Array to BST" )
{

	SECTION( "Array with odd number of elements" ) {
		int* array = new int[7];
		for(int i = 0; i < 7; i++) {
			array[i] = i;
		}
		int* bst = arrayToBST(array, 7);
		REQUIRE(bst[0] == 3);
		REQUIRE(bst[1] == 1);
		REQUIRE(bst[2] == 5);
		REQUIRE(bst[3] == 0);
		REQUIRE(bst[4] == 2);
		REQUIRE(bst[5] == 4);
		REQUIRE(bst[6] == 6);
		delete array;
		delete bst;
	}

	SECTION( "Array with even number of elements" ) {
		int* array = new int[6];
		for(int i = 0; i < 6; i++) {
			array[i] = i;
		}
		int* bst = arrayToBST(array, 6);
		REQUIRE(bst[0] == 2);
		REQUIRE(bst[1] == 0);
		REQUIRE(bst[2] == 4);
		REQUIRE(bst[4] == 1);
		REQUIRE(bst[5] == 3);
		REQUIRE(bst[6] == 5);

		delete array;
		delete bst;
	}
}
