#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/2_6_find_cycle.cpp"

TEST_CASE( "Sum linked numbers" )
{
	SECTION( "No loop" ) {
		node<int>* head = nullptr;
		node<int>* head2 = new node<int>(1);
		REQUIRE(findCycleHead(head) == nullptr);
		REQUIRE(findCycleHead(head2) == nullptr);
	}

	SECTION( "Test result" ) {
		node<int>* head =new node<int>(1);
		head->next = new node<int>(2);
		head->next->next = new node<int>(3);
		head->next->next->next = head->next;

		node<int>* head2 = new node<int>(1);
		head2->next = new node<int>(2);
		head2->next->next = new node<int>(3);
		head2->next->next->next = head2;

		REQUIRE(findCycleHead(head)->data == 2);
		REQUIRE(findCycleHead(head2)->data == 1);

	}

}
