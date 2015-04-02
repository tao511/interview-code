#ifndef INTERVIEW_HANOI_STACK
#define INTERVIEW_HANOI_STACK

#include <climits>

class stack {
	int* _data;
	size_t _size;
	size_t _capacity;

	void enlarge() {
		if(_capacity == _size) {
			int* tmp = new int[_capacity * 2];
			for(int i = 0; i <= _capacity; i++) { // Copy all data from 1 to capacity
				tmp[i] = _data[i];
			}
			delete _data;
			_capacity *= 2;
			_data = tmp;
		}
	}

public:

	stack() {
		_capacity = 5;
		_data = new int[_capacity+1];
		_size = 0;
	}
	~stack() { // Always write deconstructor
		delete _data;
	}
	
	void push(int val) {
		if (_size == _capacity) {
			enlarge();
		}

		_data[++_size] = val;
	}

	void pop() {
		if (_size != 0) {
			_size--;
		}
	}

	int peek() {
		if (_size != 0) {
			return _data[_size];
		}
		return INT_MAX;
	}

	size_t size() {return _size;}

};

void hanoi(int n, stack& current, stack& dest, stack& buffer) {
	// Move plates 1 till n-1 from current to buffer, using dest as buffer
	
	if (n > 1)
		hanoi(n - 1, current, buffer, dest);

	// Move plate n from current to dest
	int v = current.peek();
	current.pop();
	dest.push(v);

	// Move plates 1 till n-1 from buffer to dest, using current as buffer
	
	if (n > 1)
		hanoi(n - 1, buffer, dest, current);
}

#endif
