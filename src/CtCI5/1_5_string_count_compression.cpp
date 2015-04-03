#ifndef INTERVIEW_STRING_COUNT_COMPRESSION
#define INTERVIEW_STRING_COUNT_COMPRESSION

#include <string>
#include <sstream>

/**
 * Compress a string.
 *
 * Traverse through this string, if reach a character
 * that is differ from its previous character, store
 * previous character and its count, and put that new
 * character into buffer, set counter to 1.
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 */
std::string stringCompression(std::string str) 
{
	// Traverse through str, and count appearance

	if (str.length() == 0) return str;

	std::ostringstream oss;

	size_t nPos = 0; //< Position in new string
	uint32_t cCount = 0; //< Character count
	char prevChar = str[0]; //< previous character

	for(size_t pos = 0; pos < str.length(); pos++) {
		if(prevChar == str[pos]) {
			cCount++; // same character, increase count
		} else { // character changed, save previous (char,count) set
			oss << prevChar;
			oss << cCount;
			nPos = oss.str().length();
			prevChar = str[pos];
			cCount = 1;
		}
	}

	oss << prevChar;
	oss << cCount;

	if (oss.str().length() < str.length()) {
		return oss.str();
	}

	return str;

}

#endif
