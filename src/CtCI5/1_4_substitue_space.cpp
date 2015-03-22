#ifndef INTERVIEW_SUBSTITUTE_SPACE
#define INTERVIEW_SUBSTITUTE_SPACE

/**
 * Replace space by %20
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
