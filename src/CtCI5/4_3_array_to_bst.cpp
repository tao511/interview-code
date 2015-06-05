#include <iostream>
#ifndef INTERVIEW_ARRAY_TO_BST
#define INTERVIEW_ARRAY_TO_BST

void constructBST(int* array, int* bst, int left, int right, int pos) {
	int selectedPos = left + (right - left) / 2; // always floor
	bst[pos] = array[selectedPos];
	std::cout << pos << " " << selectedPos << " " << array[selectedPos] << std::endl;
	if (left < selectedPos) {
		constructBST(array, bst, left, selectedPos-1, pos * 2 + 1);
	}
	if (right > selectedPos) {
		constructBST(array, bst, selectedPos + 1, right, pos * 2 + 2);
	}
}

int* arrayToBST(int* array, int size) {
	int* bst = new int[size%2 == 0 ? size + 1 : size];
	constructBST(array, bst, 0, size-1, 0);
	return(bst);
}


#endif
