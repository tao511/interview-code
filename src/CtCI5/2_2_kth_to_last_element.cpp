#ifndef INTERVIEW_KTH_TO_LAST_ELEMENT
#define INTERVIEW_KTH_TO_LAST_ELEMENT

template <typename T>
class node {
	public:
		T data;
		node* next;

		node(T d): data(d), next(nullptr) {}
};

/**
 * Find kth to last elements in a linked list.
 *
 * First we need to know if there are k elements in the list,
 * if not return nothing.
 *
 * After we find the kth element from the beginning, we create
 * a new pointer pointing at the head, so the distance between
 * old pointer and new pointer is `k`. Then we move them 
 * simultaneously until the old pointer reaches the end of the list.
 * Then we get the last k elements in the list.
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */
template <typename T>
node<T>* kthToLast(node<T>* head, size_t k)
{
	node<T>* ptr = head;
	node<T>* kPtr = nullptr;
	size_t cnt = 0;

	while (ptr != nullptr) { // Runner pointer
		cnt++;
		if (cnt == k) break; // reach kth element from start
		ptr = ptr->next;
	}

	if (ptr == nullptr) return nullptr; // there are less than k elements

	kPtr = head;

	while (ptr->next != nullptr) {
		ptr = ptr->next;
		kPtr = kPtr->next;
	}

	return kPtr;

}

#endif
