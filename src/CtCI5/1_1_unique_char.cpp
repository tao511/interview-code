#ifndef SOLUTION_UNIQUE_STR_CPP
#define SOLUTION_UNIQUE_STR_CPP

#include <string>

size_t _partition(std::string& str, size_t i, size_t j) {
	size_t low = i;
	size_t high = j;
	char pivot = str[(i + j) / 2];

	while(i <= j) {
		while(str[i] < pivot) {
			i++;
			if (i == high) break;
		}
		while(str[j] > pivot) {
			j--;
			if (j == low) break;
		}
		if (i <= j) {
			char tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			if (i < high) i++;
			if (j > low) j--;
		}
	}
	return i;
}

void _quickSort(std::string& str, size_t i, size_t j) {
	if (str.length() <= j || i >= j) return;

	size_t pivotPos = _partition(str, i, j);
	_quickSort(str, i, pivotPos - 1);
	_quickSort(str, pivotPos, j);
}

/*
 * Detect if all characters in str is unique or not
 */
bool isUnique(std::string str) {
	// Solution 1: Sort it and then check if str[i-1] str[i] has the same value

	//if (str.length() == 0) return true; // Must deal with length() == 0 because
																			// length() is size_t, length() - 1 equals
																			// to a large number instead of -1
	
	_quickSort(str, 0, str.length() - 1);


	bool isUniq = true;

	for (int i = 1; i < str.length(); i++) { // compare str[i] and str[i-1] to avoid
																					 // length() - 1 when length() == 0
		if (str[i] == str[i-1]) isUniq = false;
	}
	
	return isUniq;

}

bool isUniqueV2(std::string str) {
	// Solution 2: Create an array and check if a character exists
	
	bool charTable[256] = {false};

	for(size_t i = 0; i < str.length(); i++) {
		if (charTable[str[i]]) return false;
		charTable[str[i]] = true;
	}

	return true;

}

bool isUniqueV3(std::string str) {
	// Solution 3: Create an integer array to store character table
	
	uint32_t charTable[8] = {0};
	for(size_t i = 0; i < str.length(); i++) {
		uint8_t pos = str[i] / 32;
		uint32_t val = 1 << (str[i] % 32);
		if ((charTable[pos] & val) == val) return false; // bit ops have lower precedence than comparsion
		charTable[pos] |= val;
	}
	return true;
}

#endif
