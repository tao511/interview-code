#ifndef INTERVIEW_SET_OF_STACKS
#define INTERVIEW_SET_OF_STACKS

#include <climits>
#include <vector>

/**
 * Stack with fixed capacity.
 *
 */
class FixStack {
	size_t capacity;
	int *data;

public:
	size_t size;

	/**
	 * Constructor.
	 *
	 * data is initialized to capacity + 1 because we do not use
	 * data[0], therefore we need an extra space to store n elements
	 */
	FixStack(): size(0), capacity(1), data(nullptr) {
		data = new int[capacity + 1];
	}

	FixStack(size_t capacity): size(0), capacity(capacity), data(nullptr) {
		data = new int[capacity + 1];
	}

	~FixStack() {
		// Check if it is nullptr before delete it
		if (data != nullptr) delete data;
	}
	
	bool push(int val) {
		if (size == capacity) return false;
		data[++size] = val;
		return true;
	}

	bool pop() {
		if (size == 0) return false;
		size--;
		return true;
	}

	int peek() {
		if (size != 0) return data[size];
		return INT_MAX;
	}

};

/**
 * Stack that contains a set of stacks.
 *
 */
class SetOfStacks {

	size_t stackCapacity; //< maximum size of each stack
	size_t stackNum; //< number of stacks
	std::vector<FixStack*> stacks; //< pointer of a set of stacks
	
public:
	size_t size; //< total number of elements in this abstract stack

	SetOfStacks(int stackNum, int stackCapacity): stackCapacity(stackCapacity), size(0), 
																								stackNum(stackNum) {

		// Resize actually filled up the vector with default values of your type
		stacks.resize(stackNum);
		for(int i = 0; i < stackNum; i++) {
			stacks[i] = new FixStack(stackCapacity);
		}
	}

	/**
	 * Push an element into the stack.
	 * 
	 * Find first non-full stack, put this element into it
	 * If we do not implement popAt method, then we can just
	 * do stacks[size++ / stackCapacity].push(val)
	 */
	bool push(int val) {
		if (size == stackNum * stackCapacity) return false;

		for(int i = 0; i < stackNum; i++) {
			if (stacks[i]->size < stackCapacity) {
				if (stacks[i]->push(val)) {
					size++;
					return true;
				} else {
					return false;
				}
			}
		}
		// If there is not enough space, enlarge it 
		stacks[stackNum++] = new FixStack(stackCapacity);
		// And then put it into that stack
		return stacks[stackNum - 1]->push(val);
	}

	/**
	 * Pop an element out of the stack.
	 *
	 * Find first non-empty stack and do pop on it
	 *
	 * If we do not implement popAt method, then we can
	 * do stacks[--size / stackCapacity].pop()
	 *
	 */
	bool pop() {
		if (size == 0) return false;

		for (int i = stackNum - 1; i >= 0; i--) {
			if (stacks[i]->size > 0) {
				if (stacks[i]->pop()) {
					size--;
					return true;
				} else {
					return false;
				}
			}
		}
		return false;
	}

	/**
	 * Return value of the head.
	 */
	int peek() {
		if(size == 0) return INT_MAX;
		for(int i = stackNum - 1; i >= 0; i--) {
			if(stacks[i]->size != 0) {
				return stacks[i]->peek();
			}
		}
		return INT_MAX;
	}

	/**
	 * Pop at a certain stack.
	 */
	bool popAt(size_t i) {
		if (stackNum < i) return false;
		if (stacks[i]->pop()) {
			size--;

			return true;
		}
		
		return false;
	}
};

#endif
