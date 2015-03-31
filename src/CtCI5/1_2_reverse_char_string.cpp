#ifndef SOLUTION_REVERSE_CHAR_STRING
#define SOLUTION_REVERSE_CHAR_STRING

/**
 * Reverse a \0 terminated char* string.
 *
 * Keep two pointers, one at the beginning and the other one 
 * at the end of this char* string. Swap the values that these 
 * two pointers points too, and then move them to the middle by 1.
 * 
 * Reminder do not reverse the endding \0.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */
void reverse(char* str) {

	size_t end = 0;

	while(str[end] != '\0'){
		end++;
	}

	if (end == 0) return; // if length == 0 return

	end--; // we do not reverse '\0'

	for(size_t i = 0; i < end; i++, end--) {
		char tmp = str[end];
		str[end] = str[i];
		str[i] = tmp;
	}

}

#endif
