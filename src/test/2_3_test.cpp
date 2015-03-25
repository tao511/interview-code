#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/2_3_delete_middle_node.cpp"

TEST_CASE( "Test delete middle element in a string" )
{
	SECTION( "list with less than 3 elements" ) {
		
		deleteMiddleNode((node<int>*)nullptr);

		node<int>* head = new node<int>(0);
		head->next = new node<int>(1);

		deleteMiddleNode(head);

		REQUIRE(head->data == 0);
		REQUIRE(head->next != nullptr);
		REQUIRE(head->next->data == 1);
		REQUIRE(head->next->next == nullptr);

		while(head != nullptr) {
			node<int>* tmp = head;
			head = head->next;
			free(tmp);
		}

	}

	SECTION( "list with enough elements" ) {
		node<int>* head = new node<int>(0);
		node<int>* ptr = head;
		for(int i = 1; i < 5; i++) {
			ptr->next = new node<int>(i);
			ptr = ptr->next;
		}

		deleteMiddleNode(head);

		while(head != nullptr) {
			node<int>* tmp = head;
			REQUIRE(head->data != 2);
			head = head->next;
			free(tmp);
		}
	}

	SECTION( "delete node without access to header" ) {
		node<int> * head = new node<int>(0);
		head->next = new node<int>(1);
		head->next->next = new node<int>(2);

		deleteNode(head->next);
		
		REQUIRE(head->next->data == 2);
		REQUIRE(head->next->next == nullptr);

		free(head->next);
		free(head);

	}

}
