#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/3_1_three_stacks.cpp"

TEST_CASE( "Stacks in one array" )
{
	SECTION( "tight array" ) {
		size_t maxStack = 10;
		ArrayStack arrayStack(maxStack, maxStack);

		for(size_t i = 0; i < maxStack; i++) {
			REQUIRE( arrayStack.size(i) == 0 );
		}

		for(size_t i = 0; i < maxStack; i++) {
			REQUIRE( arrayStack.push(i, i) == true );
			REQUIRE( arrayStack.size(i) == 1 );
			REQUIRE( arrayStack.peek(i) == (int)i);
			REQUIRE( arrayStack.push(-i,i) == false);
			REQUIRE( arrayStack.peek(i) == (int)i);
			REQUIRE( arrayStack.size(i) == 1 );
		}
		for(size_t i = 0; i < maxStack; i++) {
			REQUIRE( arrayStack.peek(i) == (int)i);
			REQUIRE( arrayStack.size(i) == 1 );

			REQUIRE( arrayStack.pop(i) == true );
			REQUIRE( arrayStack.size(i) == 0 );

			REQUIRE( arrayStack.pop(i) == false );
		}
	}
}
