#ifndef INTERVIEW_MY_QUEUE
#define INTERVIEW_MY_QUEUE

#include <climits>

/**
 * A simple stack.
 *
 * Data are stored between _data[1] to _data[size]
 *
 */
class stack {
	int* _data;
	size_t _capacity;
	size_t _size;

	/**
	 * Double storage size
	 */
	void extend() {
		int* tmp = new int[_capacity * 2 + 1]; // since we do not start at 0, we need an extra space here
		for(int i = 1; i <= _capacity; i++) {
			tmp[i] = _data[i];
		}
		delete _data;
		_data = tmp;
		_capacity *= 2;
	}

public:
	stack(): _data(nullptr), _capacity(2), _size(0) {
		// We need one more int because we do not use _data[0]
		_data = new int[_capacity + 1];
	}
	~stack() {
		// Release only if this is not nullptr
		if (_data != nullptr) delete _data;
	}

	void pop() {
		if (_size == 0) return;
		_size--;
	}

	void push(int val) {
		if (_size == _capacity) {
			extend();
		}
		_data[++_size] = val;
	}

	int peek() {
		if (_size != 0) return _data[_size];
		return INT_MAX;
	}

	size_t size() const {
		return _size;
	}

};

class myQueue {

	stack _tmpStack;
	stack _queue;

public:
	
	myQueue() {
	}

	~myQueue() {}

	void append(int val) {

		// Move all elements from _queue to _tmpStack;
		
		while(_queue.size() != 0) {
			_tmpStack.push(_queue.peek());
			_queue.pop();
		}

		// Put val into _queue
		
		_queue.push(val);

		// Move all elements back
		
		while(_tmpStack.size() != 0) {
			_queue.push(_tmpStack.peek());
			_tmpStack.pop();
		}

	}

	int get() {
		if (_queue.size() != 0) {
			int val = _queue.peek();
			_queue.pop();
			return val;
		}

		return INT_MAX;
	}

	size_t size() const { return _queue.size(); }
	
};

#endif
