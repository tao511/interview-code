#ifndef INTERVIEW_DELETE_MIDDLE_NODE
#define INTERVIEW_DELETE_MIDDLE_NODE

template <typename T>
class node {
public:
	T data;
	node* next;
	
	node(T init_data): data(init_data), next(nullptr){}
};

/**
 * Delete middle element in a linkedlist if given only access
 * to that node.
 *
 * Copy data from its decendent, and delete its decedent.
 * 
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
template <typename T>
void deleteMiddleNodeGivenMiddleNode(node<T>* mid) {
	if(mid == nullptr || mid->next == nullptr) return;
	node<T> *next = mid->next;
	mid->data = next->data;
	mid->next = next->next;
	delete next;
}

/**
 * Delete middle element in a linkedlist if given access to head.
 *
 * Use two pointers, one moves 1 step another one moves 2 step per iteration.
 * When fast pointer reaches the end, then the slow pointer is pointing to 
 * the middle element.
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */
template <typename T>
void deleteMiddleNode(node<T>* head) {
	// This is a typical runner pointer problem
	// ptr moves 1 while ptr2X moves 2
	// when ptr2X reaches nullptr, ptr is right in the middle
	
	// in order to remove the one in the middle, this linked list
	// must have at least 3 nodes.
	if (head == nullptr) return;
	if (head->next == nullptr) return;
	if (head->next->next == nullptr) return;

	node<T> *ptr = head;
	node<T> *ptr2X = head->next->next; // this is actually i-1

	

	while (ptr2X != nullptr) {
		// move ptr2X by 2
		if (ptr2X->next != nullptr &&
			 ptr2X->next->next != nullptr) { // can move 2 position
				ptr2X = ptr2X->next->next;
				// move ptr accordingly
				ptr = ptr->next;
		} else { // reach end, ptr->next is the node we want to delete
			node<T>* tmp = ptr->next;
			ptr->next = ptr->next->next;
			free(tmp);
			ptr2X = nullptr;
		}
	}

}

template <typename T>
void deleteNode(node<T>* ptr) {
	// If we can not access header, then we need duplicate i+1 and then remove it
	if (ptr == nullptr || ptr->next == nullptr) return;

	node<T>* tmp = ptr->next;
	ptr->data = tmp->data;
	ptr->next = tmp->next;
	free(tmp);
}

#endif
