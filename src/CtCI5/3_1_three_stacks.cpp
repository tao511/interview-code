#ifndef INTERVIEW_THREE_STACKS
#define INTERVIEW_THREE_STACKS


class ArrayStack {
	size_t stacks;
	size_t arraySize;
	std::vector<size_t> stackSize;
	int* data;

	inline size_t getPos(size_t stackId) {
		// stack offset id * len_of_stack
		size_t pos = stackId * (arraySize / stacks);
		// if not empty
		if (stackSize[stackId] >= 1) {
			pos += stackSize[stackId] - 1;
		}
		return pos;
	}

public:
	ArrayStack(size_t numStack, size_t arraySize): stacks(numStack), arraySize(arraySize) {
		stackSize.reserve(numStack);
		data = new int[arraySize]; //< Allocate array

		for(size_t i = 0; i < numStack; i++) {
			stackSize.push_back(0); //< All stacks have 0 element at beginning
			assert(stackSize[i] == 0);
		}
		for(size_t i = 0; i < arraySize; i++) {
			data[i] = 0;
		}
	}

	~ArrayStack() {
		delete data;
	}

	bool push(int val, size_t stackId) {
		if (stackId >= stacks) return false;

		if (stackSize[stackId] >= arraySize / stacks) return false;

		size_t pos = stackSize[stackId] == 0 ?
			getPos(stackId) : getPos(stackId) + 1;

		data[pos] = val;

		stackSize[stackId]++;

		return true;

	}

	bool pop(size_t stackId) {
		if (stackId >= stacks) return false;

		if (stackSize[stackId] == 0) return false;

		stackSize[stackId]--;

		return true;
	}

	int peek(size_t stackId) {
		if (stackId >= stacks) return 0;
		
		if (stackSize[stackId] == 0) return 0;

		return data[getPos(stackId)];
	}

	size_t size(size_t stackId) {
		if (stackId >= stacks) return 0;
		return stackSize[stackId];
	}

};

#endif
