#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/3_6_stack_sort.cpp"
#include <climits>

TEST_CASE( "Queue" )
{

	SECTION( "construct a stack" ) {
		Stack stack;
		for(int i = 1; i <= 8; i++) {
			stack.push(i);
			REQUIRE( stack.peek() == i );
		}

		REQUIRE( stack.isEmpty() == false );

		for(int i = 8; i >= 1; i--) {
			REQUIRE( stack.peek() == i );
			stack.pop();
		}

		REQUIRE( stack.isEmpty() == true );
	
	}

	SECTION( "Sort descending stack" ) {
		Stack stack;
		for(int i = 1; i <= 8; i++) {
			stack.push(i);
			REQUIRE( stack.peek() == i );
		}

		REQUIRE( stack.isEmpty() == false );

		stackSort(stack);

		for(int i = 1; i <= 8; i++) {
			REQUIRE( stack.peek() == i);
			stack.pop();
		}

		REQUIRE( stack.isEmpty() == true );

	}

	SECTION( "Sort ascending stack" ) {
		Stack stack;

		for(int i = 10; i >= 1; i--) {
			stack.push(i);
			REQUIRE( stack.peek() == i );
		}

		REQUIRE( stack.isEmpty() == false );

		stackSort(stack);

		for(int i = 1; i <= 10; i++) {
			REQUIRE( stack.peek() == i);
			stack.pop();
		}
	}

	SECTION( "Sort unordered stack" ) {
		Stack stack;
		int data[10] = {10,2,32,17,-1,9,9,1,0,0};
		int res[10] = {-1,0,0,1,2,9,9,10,17,32};

		for(int i = 0; i < 10; i++) {
			stack.push(data[i]);
		}

		stackSort(stack);

		for(int i = 0; i < 10; i++) {
			REQUIRE( stack.peek() == res[i] );
			stack.pop();
		}

	}

}
