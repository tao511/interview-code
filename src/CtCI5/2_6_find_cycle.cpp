#ifndef INTERVIEW_FIND_CYCLE
#define INTERVIEW_FIND_CYCLE

#include <set>

template <typename T>
class node {
public:
	T data;
	node* next;
	node(T init_data) : data(init_data), next(nullptr) {}
};

template <typename T>
node<T>* findCycleHeadNaive(node<T>* head) {
	std::set<node<T> *> ptrSet;
	node<T>* ptr = head;
	while(ptr != nullptr) {
			if (ptrSet.find(ptr) == ptrSet.end()) {
				ptrSet.insert(ptr);
				ptr = ptr->next;
			} else {
				return ptr;
			}
	}

	return nullptr;
	
}

/**
 * Find the starting point of a loop in a singly linked list.
 *
 * First use two pointers, one moves 1 step every time and the other
 * one moves 2 steps per time. Then when the slow pointer reaches 
 * the starting point of the loop, the fast pointer is at k%m position in
 * the loop (where k is the distance between the start of the list and the start
 * of the loop, and m is the length of the loop). When slow and fast pointers meet,
 * it is at m - k%m position. Then we need move the slow pointer back to the
 * head, and when these two pointers meet again, it is the starting point
 * of that loop.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */
template <typename T>
node<T>* findCycleHead(node<T>* head) {
	//first, construct a quick pointer and slow pointer and make them meet
	node<T>* slowPtr = head;
	node<T>* fastPtr = head;
	
	while(fastPtr != nullptr) {
		fastPtr = fastPtr->next; // move fast once
		if (fastPtr == nullptr) break; // reach end
		if (fastPtr == slowPtr) break; // meet slowPtr

		fastPtr = fastPtr->next; // move fast again
		if (fastPtr == slowPtr) break; // meet slowPtr

		slowPtr = slowPtr->next; // move slow
	}

	if (fastPtr == nullptr) return nullptr; // no loop


	slowPtr = head;

	while(fastPtr != nullptr) {
		fastPtr = fastPtr->next; // move fast once
		if (fastPtr == nullptr) break; // reach end
		if (fastPtr == slowPtr) break; // meet slowPtr

		fastPtr = fastPtr->next; // move fast again
		if (fastPtr == slowPtr) break; // meet slowPtr

		slowPtr = slowPtr->next; // move slow
	}

	return fastPtr;

}

#endif 
