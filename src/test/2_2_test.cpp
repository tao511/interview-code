#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/2_2_kth_to_last_element.cpp"

TEST_CASE( "Find kth element to the end of a linked list" )
{

	SECTION( "empty list" ) {
		REQUIRE( kthToLast((node<int>*)nullptr, 1)==nullptr );
	}

	SECTION( "list without sufficient number of nodes" ) {
		node<int> *head = new node<int>(0);
		node<int> *ptr = head;
		head->next = new node<int>(1);
		head->next->next = new node<int>(2);


		REQUIRE( kthToLast(head, 5) == nullptr);
		
		while(ptr != nullptr) {
			head = ptr;
			ptr = ptr->next;
			free(head);
		}
	}

	SECTION( "list with sufficient number of nodes" ) {
		node<int> *head = new node<int>(0);
		node<int> *ptr = head;
		for(int j = 0; j < 5; j++) {
			ptr->next = new node<int>(j);
			ptr = ptr->next;
		}

		REQUIRE( kthToLast(head, 5) == head->next );
		REQUIRE( kthToLast(head, 2) == head->next->next->next->next);

		ptr = head;
		while(ptr != nullptr) {
			head = ptr;
			ptr = ptr->next;
			free(head);
		}
	}

}
