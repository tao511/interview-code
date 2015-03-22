#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../CtCI5/1_3_string_permutation.cpp"

TEST_CASE( "Check if a string is the permutation of another string" )
{

	SECTION( "Empty String" ) {
		std::string src = "";
		std::string target = "";
		REQUIRE( isStringPermutation(src,target) == true );
		REQUIRE( isStringPermutationV2(src,target) == true );
	}

	SECTION( "String with different length" ) {
		std::string src = "a";
		std::string target = "aa";
		REQUIRE( isStringPermutation(src,target) == false );
		REQUIRE( isStringPermutationV2(src,target) == false );
	}

	SECTION( "Permutation Strings" ) {
		std::string src = "abc def";
		std::string target = "fdec ab";
		REQUIRE( isStringPermutation(src,target) == true );
		REQUIRE( isStringPermutationV2(src,target) == true );
	}

}
