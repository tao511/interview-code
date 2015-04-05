#ifndef INTERVIEW_STACK_SORT
#define INTERVIEW_STACK_SORT

#include <climits>

class Stack {
	int* _data;
	size_t _capacity;
	size_t _size;

	void extend() {
		int* tmp = new int[_capacity*2 + 1];
		for(size_t i = 1; i <= _capacity; i++) {
			tmp[i] = _data[i];
		}
		delete _data;
		_data = tmp;
	}
public:
	Stack(): _data(nullptr), _capacity(4), _size(0) {
		_data = new int[_capacity + 1];
	}
	~Stack() {
		if (_data != nullptr) delete _data;
	}

	void pop() {
		if (_size != 0) _size--;
	}

	void push(int val) {
		if (_capacity == _size) {
			extend();
		}
		_data[++_size] = val;
	}
	
	int peek() {
		if (isEmpty()) return INT_MIN;
		return _data[_size];
	}

	bool isEmpty() {
		return _size == 0;
	}

};

void stackSort(Stack& stack) {
	if (stack.isEmpty()) return;

	Stack tmpStack; //< descending stack

	// sort until all data are in tmpStack
	while(!stack.isEmpty()) {
		int tmpVal = stack.peek();
		stack.pop();
		size_t count = 0;

		// find a place to place tmpVal in tmpStack
		while(!tmpStack.isEmpty() && tmpStack.peek() > tmpVal ) {
			count++;
			stack.push(tmpStack.peek());
			tmpStack.pop();
		}

		// put tmpVal into tmpStack
		tmpStack.push(tmpVal);

		// all elements before tmpVal are \leq than tmpVal
		// all elements after tmpVal are \geq than tmpVal
		while(count != 0) {
			tmpStack.push(stack.peek());
			stack.pop();
			count--;
		}
	}

	// reverse tmpStack, so all elements in stack are in 
	// ascending order
	while(!tmpStack.isEmpty()) {
		stack.push(tmpStack.peek());
		tmpStack.pop();
	}
}

#endif
