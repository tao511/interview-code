#ifndef INTERVIEW_KTH_TO_LAST_ELEMENT
#define INTERVIEW_KTH_TO_LAST_ELEMENT

template <typename T>
class node {
	public:
		T data;
		node* next;

		node(T d): data(d), next(nullptr) {}
};

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
