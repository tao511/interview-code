#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/4_2_find_routine.cpp"

TEST_CASE( "Find routine on graph" )
{

	SECTION( "Acyclic graph" ) {
		DiGraph digraph;
		digraph.add_edge(1,2);
		digraph.add_edge(1,3);
		digraph.add_edge(2,3);
		digraph.add_edge(3,4);
		digraph.add_edge(2,5);

		REQUIRE( digraph.hasRoutine(1,5) == true );
		REQUIRE( digraph.hasRoutine(3,5) == false );

		std::vector<int> path = digraph.findRoutine(1,5);

		REQUIRE( path.size() == 3 );

		REQUIRE( path[0] == 1 );
		REQUIRE( path[1] == 2 );
		REQUIRE( path[2] == 5 );

	}

	SECTION( "Cyclic graph" ) {
		DiGraph digraph;
		digraph.add_edge(1,2);
		digraph.add_edge(1,3);
		digraph.add_edge(2,3);
		digraph.add_edge(3,4);
		digraph.add_edge(2,5);
		digraph.add_edge(2,1);
		digraph.add_edge(3,1);
		REQUIRE( digraph.hasRoutine(1,5) == true );
		REQUIRE( digraph.hasRoutine(3,5) == true );
		REQUIRE( digraph.hasRoutine(1,2) == true );

		std::vector<int> path = digraph.findRoutine(3,5);

		REQUIRE( path[0] == 3 );
		REQUIRE( path[1] == 1 );
		REQUIRE( path[2] == 2 );
		REQUIRE( path[3] == 5 );
	}
}
