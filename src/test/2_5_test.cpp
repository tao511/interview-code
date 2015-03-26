#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/2_5_sum_number_list.cpp"

TEST_CASE( "Sum linked numbers" )
{
	SECTION( "Empty list" ) {
		node* head = nullptr;
		node* head2 = new node(1);
		REQUIRE(sumListNumber(head, head, true) == 0);
		REQUIRE(sumListNumber(head2, head, true) == 1);
		REQUIRE(sumListNumber(head, head2, false) == 1);
	}

	SECTION( "Test result" ) {
		node* head =new node(1);
		head->next = new node(2);
		head->next->next = new node(3);

		node* head2 = new node(1);
		head2->next = new node(2);
		head2->next->next = new node(3);

		REQUIRE(sumListNumber(head, head2, false) == 246);
		REQUIRE(sumListNumber(head2, head, true) == 642);

	}

}
