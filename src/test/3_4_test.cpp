#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/3_4_hanoi_stack.cpp"
#include <climits>

TEST_CASE( "Stack" ) {
	SECTION( "test" ) {
		stack s;
		for(int i = 1; i <= 10; i++) {
			s.push(i);
			REQUIRE( s.peek() == i );
		}
		for(int i = 10; i != 1; i--) {
			REQUIRE( s.peek() == i );
			s.pop();
			REQUIRE( s.size() == i - 1 );
		}
	}
}

TEST_CASE( "Hanoi Stack" )
{
	int HANOI_SIZE = 20;

	SECTION( "Hanoi" ) {

		stack current, mid, dest;
		for(int i = HANOI_SIZE; i >= 1; i--) {
			current.push(i);
		}

		// Make sure you call your function correctly
		// Check parameter order TWICE!
		hanoi(HANOI_SIZE, current, dest, mid);

		REQUIRE( current.size() == 0);
		REQUIRE( mid.size() == 0);
		REQUIRE( dest.size() == HANOI_SIZE);
		
		for(size_t i = 1; i <= HANOI_SIZE; i++) {
			REQUIRE( dest.peek() == i );
			dest.pop();
		}

	}

}
