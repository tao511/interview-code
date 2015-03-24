#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/2_1_deduplicate_linked_list.cpp"

TEST_CASE( "Remove node with duplicate values" )
{

	SECTION( "empty list" ) {
		deduplicateLinkedList((node<int>*)nullptr);
	}

	SECTION( "list without duplication" ) {
		node<int> *head = new node<int>(0);
		head->next = new node<int>(1);
		head->next->next = new node<int>(2);

		deduplicateLinkedList(head);

		int val = 0;
		node<int> *ptr = head;
		while(ptr != nullptr) {
			REQUIRE(ptr->data == val++);
			ptr = ptr->next;
		}

		ptr = head;
		while(ptr != nullptr) {
			head = ptr;
			ptr = ptr->next;
			free(head);
		}
	}

	SECTION( "list with duplication" ) {
		node<int> *head = new node<int>(0);
		node<int> *ptr = head;
		for(int i = 0; i < 100; i++) {
			for(int j = 0; j < 5; j++) {
				ptr->next = new node<int>(j);
				ptr = ptr->next;
			}
		}

		deduplicateLinkedList(head);
		bool valRange[5] = {false};
		ptr = head;
		while(ptr!= nullptr) {
			REQUIRE( valRange[ptr->data] == false );
			valRange[ptr->data] = true;
			ptr = ptr->next;
		}

		ptr = head;
		while(ptr != nullptr) {
			head = ptr;
			ptr = ptr->next;
			free(head);
		}
	}

}
