#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/1_2_reverse_char_string.cpp"

TEST_CASE( "Reverse a null-terminated string" )
{
	SECTION( "Empty String" ) {
		char str[] = "\0";
		reverse(str);
		REQUIRE( str[0] == '\0' );
	}

	SECTION( "String with odd number of characters" ) {
		char str[] = "abcde";
		reverse(str);
		REQUIRE( strcmp(str,"edcba") == 0 );
	}

	SECTION( "String with even number of characters" ) {
		char str[] = "abde";
		reverse(str);
		REQUIRE( strcmp(str,"edba") == 0 );
	}

}
