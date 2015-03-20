#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/1_1_unique_char.cpp"

TEST_CASE( "Check if a string contains only unique characters", "[isUnique]" )
{
	SECTION( "Empty String" ) {
		std::string str = "";
		REQUIRE( isUnique(str) == true );
	}

	SECTION( "Unique String" ) {
		std::string str = "abcdefg\n";
		REQUIRE( isUnique(str) == true);
	}

	SECTION( "String with duplicate values" ) {
		std::string str = "abcde\nfghi\n";
		REQUIRE( isUnique(str) == false );
	}
}
