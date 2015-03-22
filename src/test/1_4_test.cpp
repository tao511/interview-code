#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../CtCI5/1_4_substitue_space.cpp"

TEST_CASE( "Replace space by %20" )
{

	SECTION( "Empty String" ) {
		char str[] = "";
		substituteSpace(str, 0);
	}

	SECTION( "Replace Test" ) {
		char str[] = "Mr John Smith    ";
		substituteSpace(str, 13);
		REQUIRE( strcmp(str, "Mr\%20John\%20Smith") == 0);
	}

}
