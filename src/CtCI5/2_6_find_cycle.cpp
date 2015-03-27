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
