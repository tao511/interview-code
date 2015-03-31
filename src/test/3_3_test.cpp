#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/3_3_set_of_stacks.cpp"
#include <climits>

TEST_CASE( "SetOfStacks" )
{

	SECTION( "test fix stack" ) {
		FixStack fixStack(1);
		REQUIRE( fixStack.size == 0 );
		REQUIRE( fixStack.push(1) == true );
		REQUIRE( fixStack.peek() == 1 );
		REQUIRE( fixStack.size == 1 );
		REQUIRE( fixStack.push(2) == false );
		REQUIRE( fixStack.peek() == 1 );
		REQUIRE( fixStack.size == 1 );
		REQUIRE( fixStack.pop() == true );
		REQUIRE( fixStack.size == 0 );
		REQUIRE( fixStack.pop() == false );
		REQUIRE( fixStack.peek() == INT_MAX );
	}

	SECTION( "Setstacks" ) {
		SetOfStacks stack(5,5);

		REQUIRE( stack.size == 0 );

		REQUIRE( stack.pop() == false );

		for(int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				REQUIRE( stack.push(i) == true );
			}
		}

		REQUIRE( stack.size == 25 );

		for(int i = 4; i >= 0; i--) {
			for (int j = 4; j >= 0; j--) {
				REQUIRE( stack.peek() == i );
				REQUIRE( stack.pop() == true );
			}
		}

		REQUIRE( stack.size == 0 );
		REQUIRE( stack.peek() == INT_MAX );

		for(int i = 0; i < 10; i++) {
			REQUIRE( stack.push(i) == true );
		}

		for(int i = 0 ; i < 5; i++) {
			REQUIRE( stack.popAt(0) == true );
		}

		REQUIRE( stack.popAt(0) == false );

		REQUIRE( stack.size == 5 );
		REQUIRE( stack.peek() == 9);

		stack.push(10);
		REQUIRE( stack.size == 6 );
		REQUIRE( stack.peek() == 9);

	}

}
