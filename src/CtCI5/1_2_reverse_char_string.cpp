#ifndef SOLUTION_REVERSE_CHAR_STRING
#define SOLUTION_REVERSE_CHAR_STRING

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
