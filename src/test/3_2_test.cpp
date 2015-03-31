#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/3_2_stack_with_min.cpp"
#include <climits>

TEST_CASE( "MinStack" )
{

	SECTION( "Test empty stack" ) {
		Stack stack;

		REQUIRE( stack.capacity() == 0 );
		REQUIRE( stack.size() == 0 );
	}

	SECTION( "Test capacity" ) {
		Stack stack;
		
		stack.push(1);
		REQUIRE( stack.capacity() == 3 );
		REQUIRE( stack.size() == 1);
	}

	SECTION( "Test push and min" ) {
		Stack stack;

		for(int i = -5; i < 6; i++) {
			stack.push(i);

			REQUIRE( stack.peek() == i );
			REQUIRE( stack.min() == -5 );
		}

		REQUIRE( stack.capacity() == 15 );

		for(int i = 5; i >-5; i--) {
			stack.pop();
			REQUIRE( stack.size() > 0);
			REQUIRE( stack.peek() == i-1 );
			REQUIRE( stack.min() == -5 );
		}

		stack.pop();
		
		REQUIRE(stack.size() == 0);
		REQUIRE(stack.peek() == INT_MAX);
		REQUIRE(stack.min() == INT_MAX);

		stack.pop();

		REQUIRE(stack.size() == 0);
		REQUIRE(stack.peek() == INT_MAX);
		REQUIRE(stack.min() == INT_MAX);

	}

}
