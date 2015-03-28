#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/2_7_linked_palindrom.cpp"

TEST_CASE( "Find palindrom" )
{
	SECTION( "No palindrom" ) {
		node* head = nullptr;
		REQUIRE( isPalindrom(head) == false );

		head = new node(1);
		REQUIRE( isPalindrom(head) == false);

	}

	SECTION( "Has palindrom" ) {
		node* head = new node(1);
		head->next = new node(2);

		REQUIRE( isPalindrom(head) == false);

		head->next->data = 1;
		REQUIRE( isPalindrom(head) == true);

		head->next->data = 2;
		head->next->next = new node(3);
		head->next->next->next = new node(1);
		REQUIRE( isPalindrom(head) == false);

		head->next->next->data = 2;
		REQUIRE( isPalindrom(head) == true);

		free(head->next->next->next);
		head->next->next->next = nullptr;
		REQUIRE( isPalindrom(head) == false);

		head->next->next->data = 1;
		REQUIRE( isPalindrom(head) == true);

		REQUIRE(head->data == 1);
		REQUIRE(head->next->data == 2);
		REQUIRE(head->next->next->data == 1);

	}

}
