#ifndef INTERVIEW_STRING_PERMUTATION
#define INTERVIEW_STRING_PERMUTATION

/**
 * Use bin sort to detect if there are unseen characters in target.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
bool isStringPermutation(std::string src, std::string target)
{
  // Solution 1: If we assume this is an ASCII string, we create a set
  // containing all char in src, and check if there are unseen characters
  // in target

  // Permutation should have the same length
  if (src.length() != target.length()) return false;

	// We consider two empty strings are the same
	if (src.length() == 0) return true;

  // Permutation should use the same characters
  int charSet[256] = {0};
  for(size_t i = 0; i < src.length(); i++) {
    charSet[src[i]]++;
  }

  // Check characters they use
  for(size_t i = 0; i < target.length(); i++) {
    charSet[target[i]]--;
    if (charSet[target[i]] < 0) return false;
  }

  return true;

}

void _sink(std::string& str, size_t pos, size_t highBound)
{
  while (2 * pos + 1 < highBound) {
    size_t childPos = 2 * pos + 1; // index of left child
    if (childPos < highBound) { // find largest child
      if (childPos + 1 < highBound && str[childPos] < str[childPos+1]) {
        childPos++;
      }
      if (str[pos] < str[childPos]) { // replace if child larger than parent
        char tmp = str[pos];
        str[pos] = str[childPos];
        str[childPos] = tmp;
        pos = childPos; // check sub heap
      } else { // no replacement take place, exit
        break;
      }
    }
  }
}

void _heapSort(std::string& str)
{
	if (str.length() <= 1) return;

	size_t bound = str.length();
	for(size_t pos = bound/2 - 1; ; pos--) {

		_sink(str, pos, bound);

		if(pos == 0) break;
	}

	while (bound > 1) {
		char tmp = str[--bound];
		str[bound] = str[0];
		str[0] = tmp;

		_sink(str, 0, bound);
	}
}

/**
 * Use heap sort and check if two strings are identical
 * 
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */
bool isStringPermutationV2(std::string src, std::string target)
{
  // Solution 2: Sort two strings, compare if they are the same
  // if not then they are not permutation to each other

	if(src.length() != target.length()) return false;

	if(src.length() == 0) return true;

	_heapSort(src);
	_heapSort(target);

	for(size_t pos = 0; pos < src.size(); pos++) {
		if (src[pos] != target[pos]) return false;
	}

	return true;
}

#endif
