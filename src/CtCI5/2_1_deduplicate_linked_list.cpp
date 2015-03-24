#ifndef INTERVIEW_DEDUPLICATE_LINKED_LIST
#define INTERVIEW_DEDUPLICATE_LINKED_LIST

template <typename T>
class node
{
public:
	T data;
  node *next;

	node(T init_data) : data(init_data), next(nullptr)
	{}

};

// Since this question requires no extra buffer,
// the algorithm will take O(n^2) time

template <typename T>
void deduplicateLinkedList(node<T>* head) {

	node<T>* ptr = head;

	while (ptr != nullptr) {
		T data = ptr->data;
		node<T>* checkPtr = ptr;
		while (checkPtr->next != nullptr) { //check through all elements
			if (checkPtr->next->data == data) { // get duplicate node, remove it
				node<T>* tmpPtr = checkPtr->next; // element to delete
				checkPtr->next = tmpPtr->next; // remove it from list
				free(tmpPtr); // free it
			} else {
				checkPtr = checkPtr->next; // check next element
			}
		}
		ptr = ptr->next;
	}

}

#endif
