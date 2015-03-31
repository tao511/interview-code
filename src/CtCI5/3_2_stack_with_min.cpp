#ifndef INTERVIEW_STACK_WITH_MIN
#define INTERVIEW_STACK_WITH_MIN

#include <climits>

/**
 * Stack with O(1) push/pop/min.
 * A simple solution is keeping a minimum stack
 */
class Stack {

	size_t _size; //< current stack size
	size_t _capacity; //< current stack capacity
	int *_stack; //< stack pointer

	int *_minStack; //< min stack pointer
	size_t _minSize; //< min stack size
	size_t _minCapacity; //< min stack capacity

	void extendCapacity(int* &stack, size_t &capa) {
		// double stack size. If 0 init stack with capacity of 4
		int *_tmpStack = new int[capa == 0 ? 4 : capa * 2];

		// copy old values
		for(size_t i = 1; i < capa; i++) {
			_tmpStack[i] = stack[i];
		}

		delete stack;
		stack = _tmpStack;
		capa = capa == 0 ? 4 : capa * 2;
	}

public:
	Stack(): _size(0), _capacity(0), _stack(nullptr),
					_minSize(0), _minCapacity(0), _minStack(nullptr){};
	~Stack() {
		
		if (_stack != nullptr) delete _stack;
		if (_stack != nullptr) delete _minStack;
	}

	void push(int val) {
		if (_stack == nullptr || _size == _capacity-1) {
			extendCapacity(_stack, _capacity);
		}

		// push data in and increase size
		_stack[++_size] = val;

		// update min stack
		if (_minStack == nullptr || _minSize == _minCapacity) {
			extendCapacity(_minStack, _minCapacity);
		}
		if (_size == 1 || val <= _minStack[_minSize]) {
			 _minStack[++_minSize] = val;
		}
	}

	void pop() {
		if (_size == 0) return;

		if (_stack[_size] == _minStack[_minSize]) {
			_minSize--;
		}
		_size--;
	}

	int peek() {
		if (_size == 0) return INT_MAX;
		return _stack[_size];
	}

	int min() {
		if (_size == 0) return INT_MAX;
		return _minStack[_minSize];
	}

	size_t capacity() {return _capacity == 0 ? _capacity : _capacity-1;}
	size_t size() {return _size;}

};

#endif
