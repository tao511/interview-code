#define CATCH_CONFIG_MAIN
#include <string>
#include "../lib/catch.hpp"
#include "../CtCI5/1_5_string_count_compression.cpp"

TEST_CASE ( "String compression", "[stringCompression]" )
{
	SECTION( "Empty string" ) {
		std::string emptyStr = "";
		REQUIRE( emptyStr.compare(stringCompression(emptyStr)) == 0 );
	}

	SECTION( "Simple string" ) {
		std::string simpleStr = "aabcccccaaa";
		std::string resStr = "a2b1c5a3";
		REQUIRE( resStr.compare(stringCompression(simpleStr)) == 0);
	}

	SECTION( "Compressed string longer than original one" ) {
		std::string longStr = "aabcdefghig";
		REQUIRE( longStr.compare(stringCompression(longStr)) == 0);
	}

}
