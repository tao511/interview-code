#ifndef INTERVIEW_LINKED_PALINDROM
#define INTERVIEW_LINKED_PALINDROM

struct node {
	int data;
	node *next;
	node(int init_data): data(init_data), next(nullptr) {}
};

/**
 * Reverse a linked list
 */
node* swap(node* left, node* right, node* stop) {
	node* tmp = right->next;
	right->next = left;
	if (tmp == stop || tmp == nullptr) return right; // keep doing until reach end
	return swap(right, tmp, stop);
}

bool isPalindrom(node* head) {
	// Step 1. Find mid pointer
	
	if (head == nullptr) return false;
	
	node* slowPtr = head; // * belongs to variable. So if node* a,b that actually
	node* fastPtr = head; // allocate a node* and a node
	size_t stepCounter = 0;

	while(fastPtr != nullptr) {
		fastPtr = fastPtr->next;
		stepCounter++;
		if (stepCounter % 2 == 0) {
			slowPtr = slowPtr->next;
		}
	}

	if (stepCounter == 1) return false;

	// Step 2. Reverse half of the list, this time we reverse left part
	// If stepCounter % 2 == 0 means slowPtr is at the start of right part
	// If stepCounter % 2 == 1 means slowPtr is at the mid point
	
	node* midPtr = stepCounter % 2 == 0 ? nullptr : slowPtr; // whether there is a mid pointer
	node* concatPtr = slowPtr;
	
	node* rightPtr = stepCounter % 2 == 0 ? slowPtr : slowPtr->next; // head of right part

	// tail of left part
	node* revPtr = swap(nullptr, head, 
		midPtr == nullptr ? rightPtr : midPtr); // stop at mid or right part

	node* leftPtr = revPtr;

	bool isEqual = true;

	while(leftPtr != nullptr && rightPtr != nullptr) {
		if (leftPtr->data != rightPtr->data){
			isEqual = false;
			break;
		}

		leftPtr = leftPtr->next;
		rightPtr = rightPtr->next;
	}

	// Step 3. Reverse back the list
	
	swap(nullptr, revPtr, nullptr);

	// Reconnect s[n/2 -1] and s[n/2]
	
	revPtr->next = concatPtr;
	 
	return isEqual;

}

#endif
