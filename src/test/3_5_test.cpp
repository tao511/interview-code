#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/3_5_my_queue.cpp"
#include <climits>

TEST_CASE( "Queue" )
{

	SECTION( "construct a queue" ) {
		myQueue myqueue;

		REQUIRE( myqueue.size() == 0 );
	}

	SECTION( "Append test" ) {
		myQueue queue;

		for(int i = 1; i < 100; i++) {
			queue.append(i);
			REQUIRE( queue.size() == i );
		}

		for(int i = 1; i < 100; i++) {
			REQUIRE( queue.get() == i );
		}

		REQUIRE( queue.get() == INT_MAX );

	}

}
