#ifndef INTERVIEW_STRING_ROTATION
#define INTERVIEW_STRING_ROTATION

#include <string>

bool isRotation(std::string s1, std::string s2)
{
	// If s2 is rotated from s1, then it must have a cut point k where
	// s1[(i+k)%len] == s2[i]
	
	if (s1.length() != s2.length()) return false;

	if (s1.length() == 0) return true;


	for(size_t k = 0; k < s1.length(); k++) {
		bool isRotated = true;

		for(size_t i = 0; i < s1.length(); i++) {
			if(s1[(i+k) % s1.length()] != s2[i]){
				isRotated = false;
				break;
			}
		}

		if (isRotated) return true;
	}

	return false;

}

bool isRotationV2(std::string s1, std::string s2)
{
	//With isSubString() method
	
	if (s1.length() != s2.length()) return false;
	if (s1.length() == 0) return true;

	std::string s3 = s1 + s1;
	return s3.find(s2.c_str()) != std::string::npos;
}

#endif
