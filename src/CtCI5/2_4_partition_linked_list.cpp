#ifndef INTERVIEW_PARTITION_LINKED_LIST
#define INTERVIEW_PARTITION_LINKED_LIST

template <typename T>
class node {
public:
	T data;
	node *next;

	node(T init_data) : data(init_data), next(nullptr) {}
};

template <typename T>
node<T>* partitionLinkedList(node<T>* head, T x) {
	
	if (head == nullptr) return nullptr;

	node<T>* lessPtr = nullptr;
	node<T>* equalPtr = nullptr;
	node<T>* largerPtr = nullptr;
	node<T>* ptr = head;

	// Divide into three lists

	while(ptr != nullptr) {
		node<T>* nextPtr = ptr->next;

		if (ptr->data > x) {
			ptr->next = largerPtr;
			largerPtr = ptr;
		} else if (ptr->data < x) {
			ptr->next = lessPtr;
			lessPtr = ptr;
		} else {
			ptr->next = equalPtr;
			equalPtr=ptr;
		}
		ptr = nextPtr;
	}

	// Combine three liss into one
	
	ptr = lessPtr;
	while (ptr != nullptr && ptr->next != nullptr) {
		ptr=ptr->next;
	} // reach end of less list

	if (ptr == nullptr){
		 ptr = equalPtr;
	} else {
		ptr->next = equalPtr;
	} // concatenate equal list

	while (ptr != nullptr && ptr->next != nullptr) {
		ptr = ptr->next;
	} // reach end of equal list

	if (ptr == nullptr) { // if less/equal are empty
		head = largerPtr;
	} else { // return less or equal pointer, which comes earlier
		ptr->next = largerPtr;
		head = lessPtr != nullptr ? lessPtr : equalPtr;
	}


	return head;

}

#endif
