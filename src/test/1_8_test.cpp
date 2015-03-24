#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../CtCI5/1_8_string_rotation.cpp"

TEST_CASE( "Test string rotation detection" ) 
{
	SECTION( "Empty string" ) {
		std::string s1 = "";
		std::string s2 = "";

		REQUIRE( isRotation(s1,s2) == true );
		REQUIRE( isRotationV2(s1,s2) == true );

	}

	SECTION( "Strings with inequal length" ) {
		std::string s1 = "abc";
		std::string s2 = "cbaa";

		REQUIRE( isRotation(s1,s2) == false );
		REQUIRE( isRotationV2(s1,s2) == false );
	}

	SECTION( "Rotated String" ) {
		std::string s1 = "waterbottle";
		std::string s2 = "erbottlewat";

		REQUIRE( isRotation(s1, s2) == true );
		REQUIRE( isRotationV2(s1, s2) == true );
	}

	SECTION( "Complicated rotated string" ) {
		std::string s1 = "ababababc";
		std::string s2 = "ababcabab";

		REQUIRE( isRotation(s1, s2) == true );
		REQUIRE( isRotationV2(s1, s2) == true );
	}
}
