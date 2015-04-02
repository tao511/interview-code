#ifndef INTERVIEW_SUBSTITUTE_SPACE
#define INTERVIEW_SUBSTITUTE_SPACE

/**
 * Replace space by %20.
 * 
 * First calculate the number of spaces, then set a pointer A
 * at the end of your new string. Then use another pointer B 
 * to reversely traverse your old string, move the non-space 
 * character that B meet to A, and then move A and B accordingly.
 *
 * If space is met, move "%20" to A, then discard that space character.
 *
 * Keep doing this until you reach the start of your old string.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 * 
 * @param len length of string (index will be [0, len - 1])
 */
void substituteSpace(char* str, size_t len) {

	if (len == 0) return;

	// First, find out how many spaces in str
	int spaceCount = 0;
	for(size_t pos = 0; pos < len; pos++) {
		if(str[pos] == ' ') spaceCount++;
	}

	if (spaceCount == 0) return; // no space in string, return

	size_t nLen = len - 1 + spaceCount * 2; //< space -> %20, 2 characters added

	for(size_t pos = len - 1; ; pos--) {

		if(str[pos] != ' ') {
			str[nLen--] = str[pos];
		} else {
			str[nLen--] = '0';
			str[nLen--] = '2';
			str[nLen--] = '%';
		}

		if (pos == 0) break;
	}

}

#endif
