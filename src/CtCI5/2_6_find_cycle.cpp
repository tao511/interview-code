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
node<T>* findCycleHead(node<T>* head) {
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

#endif 
