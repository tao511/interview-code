#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/2_4_partition_linked_list.cpp"

TEST_CASE( "Partition linked list by given value x" )
{
	SECTION( "Empty list" ) {
		node<int>* head = nullptr;
		REQUIRE(partitionLinkedList(head, 0) == nullptr);
		REQUIRE(head == nullptr);
	}

	SECTION( "List with all small values" ) {
		node<int>* head =new node<int>(0);
		head->next = new node<int>(0);
		head->next->next = new node<int>(0);

		node<int>* nPtr = partitionLinkedList(head,1);
		REQUIRE(nPtr != nullptr);
		REQUIRE(nPtr->data == 0);

		nPtr = partitionLinkedList(head, 0);
		REQUIRE(nPtr != nullptr);
		REQUIRE(nPtr->data == 0);

		nPtr = partitionLinkedList(head, -1);
		REQUIRE(nPtr != nullptr);
		REQUIRE(nPtr->data == 0);

	}

	SECTION( "List with no equal values" ) {
		node<int>* head = new node<int>(9);
		head->next = new node<int>(3);
		head->next->next = new node<int>(7);
		head->next->next->next = new node<int>(4);
		head->next->next->next->next = new node<int>(10);


		node<int>* nPtr = partitionLinkedList(head,5);
		REQUIRE(nPtr != nullptr);
		REQUIRE(nPtr->data == 4);

		nPtr = partitionLinkedList(nPtr, 7);
		REQUIRE(nPtr != nullptr);
		REQUIRE(nPtr->next->next->data == 7);

	}

}
